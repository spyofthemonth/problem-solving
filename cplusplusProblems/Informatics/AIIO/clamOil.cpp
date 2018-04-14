#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

int n,c,pi,ci,ai;
vector< pair<int, ii> > salesmen; //boss, profit, complains
vector<int> value;
vector<int> weight;
int dp[5001];

ii calcSum(int i){
  if (!salesmen[i].first)
    return make_pair(salesmen[i].second.first, salesmen[i].second.second);
  ii s = make_pair(salesmen[i].second.first, salesmen[i].second.second);
  if (weight[salesmen[i].first] && value[salesmen[i].first]){
    return make_pair(value[salesmen[i].first] + s.first, weight[salesmen[i].first] + s.second);
  }else{
    ii add = calcSum(salesmen[i].first);
    return make_pair(s.first + add.first, s.second + add.second);
  }
}

int main(){
  cin >> n >> c;
  salesmen.resize(n+1);
  value.resize(n+1, 0);
  weight.resize(n+1, 0);
  cin >> pi >> ci;
  salesmen[1].first = 0;
  salesmen[1].second.first = pi;
  salesmen[1].second.second = ci;
  for (int i = 2; i <= n; i++){
    cin >> pi >> ci >> ai;
    salesmen[i].first = ai;
    salesmen[i].second.first = pi;
    salesmen[i].second.second = ci;
  }
  for (int i = 1; i <= n; i++){
    ii sums = calcSum(i);
    value[i] = sums.first;
    weight[i] = sums.second;
    //cout << i << " is " << value[i] << " : " << weight[i] << endl;
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= c; i++){
    for (int j = 1; j <= n; j++){
      dp[i] = (weight[j] > i)? dp[i] : max(dp[i], value[j] + dp[i - weight[j]]);
    }
  }
  cout << dp[c] << endl;

  return 0;
}