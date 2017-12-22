#include <cstdio>
#include <algorithm>
using namespace std;

int dp[101][50001];
int coins[100];

int main(){
    int tc,m,c,w;
    scanf("%d", &tc);
    while (tc--){
        int sum = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            scanf("%d", &c);
            coins[i] = c;
            sum += c;
        }
        w = sum/2;
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= w; j++){
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (coins[i-1] > j)
                    dp[i][j] = dp[i-1][j]; 
                else
                    dp[i][j] = max(coins[i-1] + dp[i-1][j - coins[i-1]], dp[i-1][j]);
            }
        }
        printf("%d\n", sum - (dp[m][w])*2);
    }
    return 0;
}