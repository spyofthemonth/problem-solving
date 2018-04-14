#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,q,qType,vertex;
vector<int> parent;
vector<int> target;
vector<int> toBeBroken;
vector< pair<int, int> > queries;
vector<int> output;
vector<bool> cycle;

int find(int i){
  if (parent[i] != i)
    parent[i] = find(parent[i]);
  return parent[i];
}

int sameSet(int x, int y){
  return find(x) == find(y);
}

void un(int x, int y){
  //cannot have rank compression
  int xParent = find(x);
  int yParent = find(y);
  if (!sameSet(x, y)){
    parent[xParent] = yParent;
  }else{
    cycle[xParent] = true;
  }
  
}

int main(){
  scanf("%d", &n);
  parent.resize(n+1);
  target.resize(n+1);
  toBeBroken.resize(n+1, false);
  cycle.resize(n+1, false);
  for (int i = 1; i <= n; i++)
    parent[i] = i;
  for (int i = 1; i <= n; i++){
    int t;
    scanf("%d", &t);
    target[i] = t;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%d %d", &qType, &vertex);
    if (qType == 2)
      toBeBroken[vertex] = true;
    queries.push_back(make_pair(qType, vertex));
  }
  for (int i = 1; i <= n; i++){
    if (!toBeBroken[i] && target[i])
      un(i, target[i]);
  }
  reverse(queries.begin(), queries.end());
  for (int i = 0; i < q; i++){
    qType = queries[i].first;
    vertex = queries[i].second;
    if (qType == 1){
      if (cycle[find(vertex)]){
        //cout << vertex << " has cycle" << endl;
        output.push_back(-1);
      }
      else{
        //cout << vertex << " has parent " << find(vertex) << endl;
        output.push_back(find(vertex));
      }
    }else{
      un(vertex, target[vertex]);
    }
  }
  reverse(output.begin(), output.end());
  for (int i = 0; i < output.size(); i++){
    if (output[i] == -1)
      printf("CIKLUS\n");
    else
      printf("%d\n", output[i]);
  }

  return 0;
}