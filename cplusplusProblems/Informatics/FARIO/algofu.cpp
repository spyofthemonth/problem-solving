#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int r,c,t,hij,rt,ct,p,currentPurity = 0, numOfTasks = 0;
vector< vector<ii> > grid; //height, purity if any
priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater< pair<int, ii> > > pq; //height, coordinates
priority_queue<int> tasks; //purity
ii temple;

void adjCells(int row, int col){
  //cout << row << " : " << col << " is " <<  endl;
  if (row != 1 && grid[row-1][col].second != -2){ //up
    pq.push(make_pair(grid[row-1][col].first, make_pair(row-1, col)));
    //cout << "adding up " << row-1 << " : " << col << endl;
    if (grid[row-1][col].second != -1){
      tasks.push(grid[row-1][col].second);
    }
    grid[row-1][col].second = -2;
  }
  if (row != r && grid[row+1][col].second != -2){ //down
    pq.push(make_pair(grid[row+1][col].first, make_pair(row+1, col)));
    //cout << "adding down " << row+1 << " : " << col << endl;
    if (grid[row+1][col].second != -1){
      tasks.push(grid[row+1][col].second);
    }
    grid[row+1][col].second = -2;
  }
  if (col != 1 && grid[row][col-1].second != -2){ //left
    pq.push(make_pair(grid[row][col-1].first, make_pair(row, col-1)));
    //cout << "adding left " << row << " : " << col-1 << endl;
    if (grid[row][col-1].second != -1){
      tasks.push(grid[row][col-1].second);
    }
    grid[row][col-1].second = -2;
  }
  if (col != c && grid[row][col+1].second != -2){ //right
    pq.push(make_pair(grid[row][col+1].first, make_pair(row, col+1)));
    //cout << "adding right " << row << " : " << col+1 << endl;
    if (grid[row][col+1].second != -1){
      tasks.push(grid[row][col+1].second);
    }
    grid[row][col+1].second = -2;
  }
  //cout << "---------------" << endl;
}

int main(){
  cin >> r >> c >> t;
  grid.resize(r+1, vector<ii>(c+1));
  for (int i = 1; i <= r; i++){
    for (int j = 1; j <= c; j++){
      cin >> hij;
      grid[i][j].first = hij;
      grid[i][j].second = -1;
    }
  }
  for (int i = 0; i < t; i++){
    cin >> rt >> ct >> p;
    grid[rt][ct].second = p;
  }
  cin >> temple.first >> temple.second;
  int row = 1, col = 1;
  grid[row][col].second = -2;
  adjCells(row, col);
  if (pq.empty())
    cout << "0" << endl;
  bool invalid = false;
  while (true){
    if (pq.top().first <= currentPurity){
      int y = pq.top().second.first, x = pq.top().second.second;
      pq.pop();
      if (y == temple.first && x == temple.second)
        break;
      adjCells(y, x);
      continue;
    }

    if (tasks.empty()){
      invalid = true;
      break;
    }
    currentPurity += tasks.top();
    //cout << "purity is now " << currentPurity << endl;
    tasks.pop();
    numOfTasks++;
  }
  if (!invalid)
    cout << numOfTasks << endl;
  else
    cout << "-1" << endl;

  return 0;
}