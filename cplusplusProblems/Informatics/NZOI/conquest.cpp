#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define INF 1000000000
typedef pair<int, int> ii;

int n,d,a,b,t;
vector< vector<ii> > adjList;
vector<int> dfsOrder;
vector<ii> vnc;
vector<int> weight;
int dp[201][501];

int maxValue(int current, int daysLeft){
    int i = dfsOrder[current];
    if (current == n) return 0;
    if (dp[i][daysLeft] != -1) return dp[i][daysLeft];
    if (weight[i] > daysLeft) return dp[i][daysLeft] = maxValue(current+vnc[i].second+1, daysLeft);
    if (!current) return dp[i][daysLeft] = vnc[i].first + maxValue(current+1, daysLeft - weight[i]); //always take the root
    return dp[i][daysLeft] = max(maxValue(current+vnc[i].second+1, daysLeft), vnc[i].first + maxValue(current+1, daysLeft - weight[i]));
}

void dfs(int current, int previous){
    dfsOrder.push_back(current);
    vnc[current].second = adjList[current].size() - 1;
    if (!current) vnc[current].second++; //exception for root
    for (int i = 0; i < adjList[current].size(); i++){
        int v = adjList[current][i].first;
        int w = adjList[current][i].second;
        if (v != previous){
            weight[v] = w * 2;
            dfs(v, current);
            vnc[current].second += vnc[v].second;
        }
    }
}

int main(){
    cin >> n >> d;
    adjList.resize(n);
    vnc.resize(n);
    weight.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vnc[i].first;
    for (int i = 0; i < n-1; i++){
        cin >> a >> b >> t;
        adjList[a].push_back(make_pair(b, t));
        adjList[b].push_back(make_pair(a, t));
    }
    dfs(0, -1);
    memset(dp, -1, sizeof(dp));
    cout << maxValue(0, d) << endl;
    return 0;
}