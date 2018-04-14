#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000

vector< vector< pair<int, int> > > adjList;
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
vector<int> dist;
vector<int> distTwo;
vector<int> shawls;

pair<int, int> shortestPath;

int main(){
  int n,m,t,a,b;
  cin >> n >> m >> t >> a >> b;
  adjList.resize(n);
  dist.resize(n, INF);
  distTwo.resize(n, INF);
  shortestPath = make_pair(INF, INF);

  while (m--){
    int x,y,w;
    cin >> x >> y >> w;
    adjList[x].push_back(make_pair(y, w));
    adjList[y].push_back(make_pair(x, w));
  }
  while (t--){
    int index;
    cin >> index;
    shawls.push_back(index);
  }

  pq.push(make_pair(0, a));
  dist[a] = 0;
  while (!pq.empty()){
    pair<int, int> front = pq.top();
    pq.pop();
    int d = front.first;
    int u = front.second;
    if (d == dist[u]){
      for (int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i].first;
        int w = adjList[u][i].second;
        if (dist[u] + w < dist[v]){
          dist[v] = dist[u] + w;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
  }

  pq.push(make_pair(0, b));
  distTwo[b] = 0;
  while (!pq.empty()){
    pair<int, int> front = pq.top();
    pq.pop();
    int d = front.first;
    int u = front.second;
    if (d == distTwo[u]){
      for (int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i].first;
        int w = adjList[u][i].second;
        if (distTwo[u] + w < distTwo[v]){
          distTwo[v] = distTwo[u] + w;
          pq.push(make_pair(distTwo[v], v));
        }
      }
    }
  }

  for (int i = 0; i < shawls.size(); i++){
    if (dist[shawls[i]] + distTwo[shawls[i]] < shortestPath.first){
      shortestPath.first = dist[shawls[i]] + distTwo[shawls[i]];
      shortestPath.second = shawls[i];
    }
    else if (dist[shawls[i]] + distTwo[shawls[i]] == shortestPath.first && shawls[i] < shortestPath.second)
      shortestPath.second = shawls[i];
  }
  cout << shortestPath.first << " " << shortestPath.second << endl;
  return 0;
}