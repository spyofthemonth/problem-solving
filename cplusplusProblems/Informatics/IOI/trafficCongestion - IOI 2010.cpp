#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 1000000000

int n,u,v;
vector< vector<int> > adjList;
vector<int> pops;
vector<int> dist;
vector<int> l;
vector<bool> visited;
vector< vector<int> > nAtL;
pair<int, int> bestLoc;

void bfs(int starting){
    queue<int> q;
    q.push(starting);
    visited[starting] = true;
    while (!q.empty()){
        int top = q.front();
        q.pop();
        for (int i = 0; i < adjList[top].size(); i++){
            int vee = adjList[top][i];
            if (!visited[vee]){
                visited[vee] = true;
                l[vee] = l[top] + 1;
                nAtL[l[vee]].push_back(vee);
                q.push(vee);
            }
        }
    }
}

void dfsForTree(int current, int parent, int previousCongestion){
    int mx = previousCongestion;
    for (int i = 0; i < adjList[current].size(); i++){
        int node = adjList[current][i];
        if (node != parent){
            dfsForTree(node, current, previousCongestion + (dist[current] - dist[node]));
            mx = max(mx, dist[node]); //for nodes that have multiple children
        }
    }
    if (mx < bestLoc.second){
        bestLoc.first = current;
        bestLoc.second = mx;
    }

}

int main(){
    cin >> n;
    adjList.resize(n);
    pops.resize(n);
    dist.resize(n);
    visited.resize(n);
    l.resize(n);
    nAtL.resize(n);
    for (int i = 0; i < n; i++){
        cin >> pops[i];
        dist[i] = pops[i];
    }
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(0);
    nAtL[0].push_back(0);
    for (int level = n-1; level >= 0; level--){
        for (int j = 0; j < nAtL[level].size(); j++){
            int current = nAtL[level][j];
            for (int b = 0; b < adjList[current].size(); b++){
                int node = adjList[current][b];
                if (l[node] < l[current]){
                    dist[node] += dist[current];
                }
            }
        }
    }

    bestLoc = make_pair(-1, INF);
    dfsForTree(0, -1, 0);
    cout << bestLoc.first << endl;

    return 0;
}