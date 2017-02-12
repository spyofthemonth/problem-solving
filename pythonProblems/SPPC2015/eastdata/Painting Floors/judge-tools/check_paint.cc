#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdarg>
using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

std::ifstream judgein,judgeans;
FILE *judgemessage = NULL;

void wrong_answer(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  
  vfprintf(judgemessage, err, pvar);
  fprintf(judgemessage, "\n");
  
  exit(EXIT_WA);
}

void judge_error(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  // If judgemessage hasn't been set up yet, write error to stderr
  if (!judgemessage) judgemessage = stderr;
  vfprintf(judgemessage, err, pvar);
  fprintf(judgemessage, "\n");
  assert(!"Judge Error");
}

template <typename Stream>
void openfile(Stream &stream, const char *file, const char *whoami) {
  stream.open(file);
  if (stream.fail()) {
    judge_error("%s: failed to open %s\n", whoami, file);
  }
}

FILE *openfeedback(const char *feedbackdir, const char *feedback, const char *whoami) {
  std::string path = std::string(feedbackdir) + "/" + std::string(feedback);
  FILE *res = fopen(path.c_str(), "w");
  if (!res) {
    judge_error("%s: failed to open %s for writing", whoami, path.c_str());
  }
  return res;
}

void do_case(){
  const int MAX_N = 500;
  const int MAX_LINES = 1000;
  char C[MAX_N][MAX_N];
  
  int m,n;
  judgein >> m >> n;
  assert(1 <= m && m <= MAX_N && 1 <= n && n <= MAX_N);
  
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      judgein >> C[i][j];
  
  string line;
  int num_lines = 0;
  
  string s;
  int row,col;
  while(getline(cin,line)){
    num_lines++;
    
    if(num_lines > MAX_LINES) wrong_answer("Too many lines of output");
    
    stringstream ss(line);
    if(!(ss >> row >> col))
      wrong_answer("This line does not have two integers on it: %s",line.c_str());
    if(ss >> s) wrong_answer("Extra output on line: %s",line.c_str());
    if(!(1 <= row && row <= m && 1 <= col && col <= n))
      wrong_answer("Invalid array indices: (%d,%d) with bounds: (%d,%d)",row,col,m,n);
    row--;
    col--;
    if(C[row][col] == 'x') wrong_answer("Painting on furniture");
    
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = { 0, 0, 1,-1};
    for(int k=0;k<4;k++)
      for(int d=0;;d++){
        int nI = row+d*di[k], nJ = col+d*dj[k];
        if(!(0 <= nI && nI < m && 0 <= nJ && nJ < n)) break;
        if(C[nI][nJ] == 'x') break;
        C[nI][nJ] = '@';
      }
  }
  
  // Now did we actually paint the whole floor?
  int ctr = 0;
  
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(C[i][j] == '.')
        ctr++;
  
  if(ctr)
    wrong_answer("They did not paint %d/%d of the floor.",ctr,m*n);
  
}

int main(int argc,char* argv[]){
  if(argc != 4)
    judge_error("Usage: %s <judge.in> <judge.ans> <feedback_dir>",argv[0]);
  
  judgemessage = openfeedback(argv[3], "judgemessage.txt", argv[0]);
  openfile(judgein, argv[1], argv[0]);
  openfile(judgeans, argv[2], argv[0]);
  
  do_case();
  
  string team;
  if(cin >> team)
    wrong_answer("Trailing output:\n%s", team.c_str());

  exit(EXIT_AC);
}

