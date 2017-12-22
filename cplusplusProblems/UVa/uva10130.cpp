#include <cstdio>
#include <algorithm>

int dp[1000][1000];
int value[1000];
int weight[1000];
int people[100];

int main(){
  int tc,o,p,maxValue;
  scanf("%d", &tc);
  while (tc--){
    scanf("%d", &o);
    for (int i = 0; i < o; i++)
      scanf("%d %d", &value[i], &weight[i]);
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
      scanf("%d", &people[i]);
    maxValue = 0;
    for (int a = 0; a < p; a++){
      for (int i = 0; i <= o; i++){
        for (int j = 0; j <= people[a]; j++){
          if (i == 0 || j == 0){
            dp[i][j] = 0;
          }else if (weight[i-1] > j){
            dp[i][j] = dp[i-1][j];
          }else{
            dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
          }
        }
      }
      maxValue += dp[o][people[a]];
    }
    printf("%d\n", maxValue);
  }
  return 0;
}