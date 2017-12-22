#include <cstdio>

int coins[5] = {1, 5, 10, 25, 50};
int dp[7490];

int main(){
    dp[0] = 1;
    for (int i = 0; i < 5; i++){
        for (int j = coins[i]; j < 7490; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    int n;
    while (scanf("%d", &n) == 1){
        printf("%d\n", dp[n]);
    }
    return 0;
}