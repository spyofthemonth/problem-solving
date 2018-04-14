#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,k,ia,sa;
vector<int> initialAngles;
vector<int> slavkoAngles;
vector< set<int> > angles;
vector<int> possible;

int main(){
  cin >> n >> k;
  angles.resize(362);
  possible.resize(361, false);
  for (int i = 0; i < n; i++){
    cin >> ia;
    initialAngles.push_back(ia);
  }
  for (int i = 0; i < k; i++){
    cin >> sa;
    slavkoAngles.push_back(sa);
  }
  angles[0].insert(0);
  bool terminate;
  for (int i = 0; i <= 360; i++){
    angles[i+1] = angles[i];
    terminate = true;
    for (set<int>::iterator it = angles[i].begin(); it != angles[i].end(); ++it){
      for (int b = 0; b < initialAngles.size(); b++){
        int x = ((*it + initialAngles[b]) % 360 == 0)? 360 : (*it + initialAngles[b]) % 360;
        int y = ((*it - initialAngles[b] < 0)? 0 : *it - initialAngles[b]);
        y = (y % 360 == 0)? 360 : y % 360;
        if (!angles[i+1].count(x) || !angles[i+1].count(y)){
          terminate = false;
        }
        angles[i+1].insert(x);
        angles[i+1].insert(y);
        possible[x] = true;
        possible[y] = true;
      }
    }
    if (terminate)
      break;
  }

  for (int i = 0; i < slavkoAngles.size(); i++)
    cout << ((possible[slavkoAngles[i]])? "YES" : "NO") << endl;

  return 0;
}