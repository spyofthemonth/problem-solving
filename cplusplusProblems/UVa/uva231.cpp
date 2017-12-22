#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int tc = 0;
    while (1){
        int a, n, tc, arr[1000];
        fill_n(arr, 1000, 0);
        scanf("%d", &a);
        if (a == -1)
            break;
        arr[0] = a;
        n = 0;
        while (1){
            scanf("%d", &a);
            if (a == -1)
                break;
            arr[++n] = a;
        }
        int lis[1000];
        fill_n(lis, 1000, 1);
        for (int i = 1; i < n+1; i++){
            for (int j = 0; j < i; j++){
                if (arr[j] >= arr[i])
                    lis[i] = max(lis[i], lis[j] + 1);
            }       
        }
        
        int intercepts = 0;
        for (int i = 0; i < n+1; i++)
            intercepts = max(lis[i], intercepts);
        if (tc)
            printf("\n");
        printf("Test #%d:\n", ++tc);
        printf("  maximum possible interceptions: %d\n", intercepts);
    }
    return 0;
}