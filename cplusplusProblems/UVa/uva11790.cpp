#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int tc, c = 0;
    scanf("%d", &tc);
    while (tc--){
        int nb, h[10000], w[10000], lis[10000], lds[10000];
        scanf("%d", &nb);
        for (int i = 0; i < nb; i++)
            scanf("%d", &h[i]);
        for (int i = 0; i < nb; i++){
            scanf("%d", &w[i]);
            lis[i] = w[i];
            lds[i] = w[i];
        }
        for (int i = 1; i < nb; i++){
            for (int j = 0; j < i; j++){
                if (h[i] > h[j])
                    lis[i] = max(lis[i], lis[j] + w[i]);
                if (h[i] < h[j])
                    lds[i] = max(lds[i], lds[j] + w[i]);
            }
            
        }
        int mi = 0, md = 0;
        for (int i = 0; i < nb; i++){
            mi = max(lis[i], mi);
            md = max(lds[i], md);
        }
        if (mi >= md)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",++c,mi,md);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",++c,md,mi);
    }
    return 0;
}