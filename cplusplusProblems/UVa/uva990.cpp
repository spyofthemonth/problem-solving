#include <cstdio>

int dp[31][1001];
int weight[31];
int oriWeight[31];
int value[31];
bool treasures[31];

int main(){
  int t,w,nt,c;
  bool first = true;
  while (scanf("%d %d", &t, &w) == 2){
    c = 0;
    scanf("%d", &nt);
    for (int i = 0; i < nt; i++){
      int d;
      scanf("%d %d", &d, &value[i]);
      oriWeight[i] = d;
      weight[i] = (w * d) + (2 * w * d);
    }
    for (int i = 0; i <= nt; i++){
      for (int j = 0; j <= t; j++){
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (weight[i-1] > j){
          dp[i][j] = dp[i-1][j];
        }else{
          if (dp[i-1][j] < value[i-1] + dp[i-1][j-weight[i-1]])
            dp[i][j] = value[i-1] + dp[i-1][j-weight[i-1]];
          else
            dp[i][j] = dp[i-1][j];
        }
      }
    }
    int i, j = t;
    for (i = nt; i > 0; i--){
      if (dp[i][j] != dp[i-1][j] || dp[i][j] != dp[i][j-1]){
        treasures[i] = true;
        c++;
        j -= weight[i-1];
      }
    }
    if (!first)
      printf("\n");
    else
      first = false;
    printf("%d\n%d\n", dp[nt][t], c);
    for (int i = 0; i <= nt; i++){
      if (treasures[i]){
        printf("%d %d\n", oriWeight[i-1], value[i-1]);
        treasures[i] = false;
      }
    }
  }
  return 0;
}