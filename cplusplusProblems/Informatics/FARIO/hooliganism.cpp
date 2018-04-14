#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n,r,ai,b,c,topoCount = 0;
vector< vector<int> > adjList;
vector<int> inDegrees;
vector<bool> finished;
queue<int> q;
string se;
bool first = true;

int main(){
  cin >> n >> r;
  inDegrees.resize(n+1, 0);
  adjList.resize(n+1);
  finished.resize(n+1);
  for (int i = 1; i <= n; i++){
    cin >> ai;
    inDegrees[i] = -ai;
  }
  for (int i = 0; i < r; i++){
    cin >> b >> c;
    adjList[b].push_back(c);
    adjList[c].push_back(b);
    inDegrees[b]++;
    inDegrees[c]++;
  }
  for (int i = 1; i <= n; i++){
    if (inDegrees[i] <= 0){
      inDegrees[i] = 0;
      q.push(i);
    }
  }
  while (!q.empty()){
    int u = q.front();
    q.pop();

    for (int i = 0; i < adjList[u].size(); i++){
      if (!finished[adjList[u][i]]){
        if (!first)
          se.append("\n" + to_string(u) + " " + to_string(adjList[u][i]));
        else{
          first = false;
          se.append(to_string(u) + " " + to_string(adjList[u][i]));
        }
      }
      finished[u] = true;
      if (--inDegrees[adjList[u][i]] == 0){
        q.push(adjList[u][i]);
      }
    }
    topoCount++;
  }
  if (topoCount == n){
    cout << se << endl;
  }else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}