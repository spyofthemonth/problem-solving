#include <cstdio>
#include <algorithm>
using namespace std;

int n,lisMax = 0,ldsMax = 0;
int arr[30001];
int lis[30001];
int lds[30001];

int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int l;
    scanf("%d", &l);
    arr[i] = l;
  }

  fill_n(lis, n, 1);
  fill_n(lds, n, 1);
  for (int i = 1; i < n; i++){
    for (int j = 0; j < i; j++){
      if (arr[i] >= arr[j])
        lis[i] = max(lis[i], lis[j] + 1);
      if (arr[i] <= arr[j])
        lds[i] = max(lds[i], lds[j] + 1);
    }
  }

  for (int i = 0; i < n; i++){
    lisMax = max(lisMax, lis[i]);
    ldsMax = max(ldsMax, lds[i]);
  }

  printf("%d\n", min(n - lisMax, n - ldsMax));

  return 0;
}