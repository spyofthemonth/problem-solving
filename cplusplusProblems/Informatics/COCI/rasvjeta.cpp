#include <iostream>
#include <set>
using namespace std;

int n,m,k;
set<int> street;

int lightUp(int pos, bool real){
  int i,j,newlyLighted = 0;
  for (i = pos + 1, j = pos - 1; i <= pos + k; i++, j--){
    if (!street.count(i) && i <= n){
      newlyLighted++;
      if (real) 
        street.insert(i);
    }
    if (!street.count(j) && j >= 1){
      newlyLighted++;
      if (real)
        street.insert(j);
    }
  }
  return newlyLighted;
}

int minLampsNeeded(int metresLeft){
  if (!metresLeft)
    return 0;
  int maxLighted = 0, maxPos;
  for (int i = 1; i <= n; i++){
    if (!street.count(i)){
      int m = lightUp(i, false);
      if (m + 1 > maxLighted){
        maxLighted = m;
        maxPos = i;
      }
    }
  }
  street.insert(maxPos);
  return 1 + minLampsNeeded(metresLeft - (lightUp(maxPos, true) + 1));
}

int main(){
  cin >> n >> m >> k;
  int tl = 0;
  while (m--){
    int lamp;
    cin >> lamp;
    if (!street.count(lamp)){
      street.insert(lamp);
      tl++;
    }
    tl += lightUp(lamp, true);
  }
  cout << ((tl != n)? minLampsNeeded(n - tl) : 0) << endl;
  return 0;
}