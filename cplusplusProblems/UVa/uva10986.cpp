#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define INF 1000000000

int main(){
    int nCases;
    scanf("%d", &nCases);
    for (int c = 1; c <= nCases; c++){
        int n,m,s,t;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        vector< vector< pair<int, int> > > network(n+1);
        for (int i = 0; i < m; i++){
            int a,b,w;
            scanf("%d %d %d", &a, &b, &w);
            network[a].push_back(make_pair(b, w));
            network[b].push_back(make_pair(a, w));
        }
        vector<int> dist(n+1, INF);
        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
        pq.push(make_pair(0, s));
        dist[s] = 0;
        while (!pq.empty()){
            pair<int, int> current = pq.top();
            pq.pop();
            int d = current.first;
            int u = current.second;
            if (d == dist[u]){
                for (int i = 0; i < network[u].size(); i++){
                    int v = network[u][i].first;
                    int w = network[u][i].second;
                    if (dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }
        printf("Case #%d: ", c);
        if (dist[t] != 0 && dist[t] != INF)
            printf("%d\n", dist[t]);
        else
            printf("unreachable\n");
        //dist.clear();
        //network.clear();
    }
    return 0;
}