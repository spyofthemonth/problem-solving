#include <algorithm>
#include <cstdio>
using namespace std;

int weight[10241];
int dp[10241][200][200];

int main(){
  int tc;
  scanf("%d", &tc);
  while (tc--){
    scanf("");
    int n,t,m;
    scanf("%d %d %d", &n, &t, &m);
    for (int i = 0; i < n; i++){
      scanf("%d", &weight[i]);
      char cm;
      scanf("%c", &cm);
    }
    for (int i = 0; i <= n; i++){
      for (int j = 0; j <= m; j++){
        for (int b = 0; b <= t; b++){
          if (i == 0 || j == 0){
            dp[i][j][b] = 0;
          }else if (b == 0){
            dp[i][j][b] = dp[i][j-1][t];
            //amount of previous cd
          }else if (weight[i-1] > b){
            dp[i][j][b] = max(dp[i-1][j][b], dp[i][j-1][t]);
            //max between without current song or previous cd
          }else{
            dp[i][j][b] = max(dp[i-1][j][b], 1 + dp[i-1][j][b-weight[i-1]]);
            //max between with or without current song
          }
        }
      }
    }
    printf("%d\n", dp[n][m][t]);
    if (tc != 0)
      printf("\n");
  }
  return 0;
}