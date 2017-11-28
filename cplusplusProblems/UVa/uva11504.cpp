#include <stdio.h>
#include <map>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;

void dfs(int u, map<int, bool> *visited, map< int, vector<int> > *dominoes, bool second){
    (*visited)[u] = true;
    for (int i = 0; i < (*dominoes)[u].size(); i++){
        int v = (*dominoes)[u][i];
        if (!(*visited)[v]){
            dfs(v, visited, dominoes, second);
        }
    }
    if (!second)
        s.push(u);
}

int main(){
    int nTestCases;
    scanf("%d", &nTestCases);
    while (nTestCases--){
        int nDoms, nLines;
        scanf("%d %d", &nDoms, &nLines);
        map< int, vector<int> > dominoes;
        map<int, bool> visited;
        while (nLines--){
            int x, y;
            scanf("%d %d", &x, &y);
            dominoes[x].push_back(y);
        }
        for (int i = 1; i <= nDoms; i++){
            if (!visited[i])
                dfs(i, &visited, &dominoes, false);
        }
        
        for (int i = 1; i <= nDoms; i++)
            visited[i] = false;
        
        int minDoms = 0;
        while (!s.empty()){
            int u = s.top();
            s.pop();
            if (!visited[u]){
                dfs(u, &visited, &dominoes, true);
                ++minDoms;
            }
        }
        printf("%d\n", minDoms);
    }
    return 0;
}