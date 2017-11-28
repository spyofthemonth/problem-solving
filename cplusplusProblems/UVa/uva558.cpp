#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
#define INF 1000000000

int main(){
    int nCases;
    scanf("%d", &nCases);
    while (nCases--){
        int n,m;
        scanf("%d %d", &n, &m);
        int i = m;
        vector< vector< pair<int, int> > > adjList(n);
        while (i--){
            int u,v,w;
            scanf("%d %d %d", &u, &v, &w);
            adjList[u].push_back(make_pair(v, w));
        }
        vector<int> dist(n, INF);
        dist[0] = 0;
        for (int i = 0; i < n-1; i++){
            for (int u = 0; u < n; u++){
                for (int b = 0; b < adjList[u].size(); b++){
                    pair<int, int> v = adjList[u][b];
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }
            }
        }
        bool negCycle = false;
        for (int u = 0; u < n-1; u++){
            for (int b = 0; b < adjList[u].size(); b++){
                pair<int, int> v = adjList[u][b];
                if (dist[v.first] > dist[u] + v.second){
                    negCycle = true;
                    break;
                }
            }
            if (negCycle)
                break;
        }
        if (negCycle)
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}