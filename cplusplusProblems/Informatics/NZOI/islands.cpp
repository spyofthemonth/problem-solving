#include <iostream>
#include <vector>
using namespace std;

int w,h,t,landCount = 0,islandCount = 0;
char point;
vector< vector<bool> > map;
vector< vector<bool> > visited;
vector< pair<int, int> > landPoints;

void dfs(int y, int x){
  if (y == h || y < 0 || x == w || x < 0)
    return;
  if (!visited[y][x]){
    visited[y][x] = true;
    if (map[y][x] == true){
      landCount++;
      dfs(y+1, x);
      dfs(y-1, x);
      dfs(y, x+1);
      dfs(y, x-1);
    }
  }
}

int main(){
  cin >> w >> h >> t;
  map.resize(h, vector<bool>(w));
  visited.resize(h, vector<bool>(w));
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> point;
      if (point == '#'){
        map[i][j] = true;
        landPoints.push_back(make_pair(i, j));
      }
      else
        map[i][j] = false;
    }
  }
  for (int i = 0; i < landPoints.size(); i++){
    if (!visited[landPoints[i].first][landPoints[i].second]){
      dfs(landPoints[i].first, landPoints[i].second);
      if (landCount >= t)
        islandCount++;
      landCount = 0;
    }
  }

  cout << islandCount << endl;
  return 0;
}