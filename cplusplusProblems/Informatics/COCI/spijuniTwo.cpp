#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int n,w,mstCost = 0;
vector<int> spyPrice;
vector< vector<bool> > edgesCheck;
vector< ii > parent;
vector<bool> checked;
priority_queue< pair<int, ii> > pq;

int find(int i){
  if (parent[i].first != i)
    parent[i].first = find(parent[i].first);
  return parent[i].first;
}

bool isSameSet(int x, int y){
  return find(x) == find(y);
}

void un(int x, int y){
  int xParent = find(x);
  int yParent = find(y);
  if (parent[xParent].second < parent[yParent].second){
    parent[yParent].first = xParent;
    spyPrice[xParent] = min(spyPrice[xParent], spyPrice[yParent]);
  }
  else if (parent[xParent].second > parent[yParent].second){
    parent[xParent].first = yParent;
    spyPrice[yParent] = min(spyPrice[xParent], spyPrice[yParent]);
  }
  else{
    parent[yParent].first = xParent;
    parent[xParent].second++;
    spyPrice[xParent] = min(spyPrice[xParent], spyPrice[yParent]);
  }
}

void initParent(){
  for (int i = 1; i <= n; i++){
    parent[i].first = i;
    parent[i].second = 0;
  }
}

int main(){
  //cin >> n;
  scanf("%d", &n);
  edgesCheck.resize(n+1, vector<bool>(n+1));
  spyPrice.resize(n+1);
  checked.resize(n+1, false);
  parent.resize(n+1);
  initParent();
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      //cin >> w;
      scanf("%d", &w);
      if (w && !edgesCheck[i][j] && !edgesCheck[j][i]){
        pq.push(make_pair(-w, make_pair(i, j)));
        edgesCheck[i][j] = true;
        edgesCheck[j][i] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++){
    //cin >> w;
    scanf("%d", &w);
    spyPrice[i] = w;
  }
  while (!pq.empty()){
    pair<int, ii> front = pq.top();
    pq.pop();
    int pOne = find(front.second.first), pTwo = find(front.second.second);
    if (!isSameSet(front.second.first, front.second.second) && -(front.first) + min(spyPrice[pOne], spyPrice[pTwo]) < spyPrice[pOne] + spyPrice[pTwo]){
      un(front.second.first, front.second.second);
      mstCost += -(front.first);
    }
  }

  for (int i = 1; i <= n; i++){
    int iParent = find(i);
    if (!checked[iParent]){
      checked[iParent] = true;
      mstCost += spyPrice[iParent];
    }
  }

  //cout << mstCost << endl;
  printf("%d\n", mstCost);

  return 0;
}