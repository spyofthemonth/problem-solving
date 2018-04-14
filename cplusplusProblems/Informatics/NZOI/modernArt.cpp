#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int n,k,x,y,current = 0,tmp;
vector<ii> pos; //left, right

int main(){
  scanf("%d %d", &n, &k);
  pos.resize(n+2);

  for (int i = 0; i <= n; i++){
    pos[i].first = i - 1;
    pos[i].second = i + 1;
  }

  for (int i = 1; i <= k; i++){
    scanf("%d %d", &x, &y);

    pos[pos[x].first].second = pos[x].second;
    pos[pos[x].second].first = pos[x].first;
    //swap left and right of x of its original position

    pos[x].second = pos[y].second;
    pos[pos[y].second].first = x;
    pos[y].second = x;
    pos[x].first = y;
  }

  while (pos[current].second <= n){
    printf("%d\n", pos[current].second);
    current = pos[current].second;
  }

  return 0; 
}