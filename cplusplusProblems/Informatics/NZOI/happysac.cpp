#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,m,sacNum = 0;
int dp[1001];
vector<int> weight;
vector<int> value;

int main(){
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i < n; i++){
    int w,v,q;
    scanf("%d %d %d", &w, &v, &q);
    while (q--){
      sacNum++;
      weight.push_back(w);
      value.push_back(v);
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= sacNum; i++){
    for (int j = m; j >= 0; j--){
      dp[j] = (weight[i-1] > j)? dp[j] : max(dp[j], value[i-1] + dp[j - weight[i-1]]);
    }
  }  
  printf("%d\n", dp[m]);
  return 0;
}