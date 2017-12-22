#include <cstdio>
#include <string.h>
#include <algorithm>

int dp[1100][1100];
char s[1100], sTwo[1100];
int main(){
    while (gets(s)){
        gets(sTwo);
        for (int i = 0; i <= strlen(s); i++){
            for (int j = 0; j <= strlen(sTwo); j++){
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s[i-1] == sTwo[j-1])
                    dp[i][j] = (1 + dp[i-1][j-1]);
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }    
        }
        printf("%d\n", dp[strlen(s)][strlen(sTwo)]);
    }
    return 0;
}