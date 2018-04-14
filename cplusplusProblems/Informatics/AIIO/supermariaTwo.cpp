#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000

int n,hi,li,ri,ci,maxHeight = 0;
vector<int> value;
vector< pair<int, int> > lr;
vector< pair<int, int> > height;
int dp[1001][1001];

int compAB(const pair<int, int> &a, const pair<int, int> &b){
  return a.first > b.first;
}

int coins(int i, int j){ //i is considering and j is current
  if (i == n)
    return 0;

  if (dp[i][j] != -1) return dp[i][j];
  if (!i) //first one
    return dp[i][j] = value[height[i].second] + coins(i + 1, j);

  if (height[i].first >= height[j].first)
    return dp[i][j] = coins(i + 1, j);

  if (lr[height[i].second].first > lr[height[j].second].first - 1 || lr[height[j].second].first - 1 > lr[height[i].second].second){
    if (lr[height[i].second].first > lr[height[j].second].second + 1 || lr[height[j].second].second + 1 > lr[height[i].second].second)
      return dp[i][j] = coins(i + 1, j);
  }
  return dp[i][j] = max(coins(i + 1, j), value[height[i].second] + coins(i + 1, i));

}

int main(){
  memset(dp, -1, sizeof(dp));
  cin >> n;
  value.resize(n);
  lr.resize(n);
  height.resize(n + 1);
  for (int i = 0; i < n; i++){
    cin >> hi >> li >> ri >> ci;
    value[i] = ci;
    lr[i].first = li;
    lr[i].second = ri;
    height[i].first = hi;
    height[i].second = i;
    maxHeight = max(maxHeight, hi);
  }
  height[n].first = -INF;
  height[n].second = INF;

  sort(height.begin(), height.end(), compAB);
  cout << coins(0, 0) << endl;;

  return 0;
}