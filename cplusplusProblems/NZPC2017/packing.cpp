#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int p,n,w1,w2,wi,vi;
vector<int> value;
vector<int> weight;
int dp[1000][1000];

int main(){
  cin >> p;
  value.resize(100);
  weight.resize(100);
  for (int j = 1; j <= p; j++){
    cin >> n >> w1 >> w2;
    for (int i = 0; i < n; i++){
      cin >> wi;
      weight[i] = wi;
    }
    for (int i = 0; i < n; i++){
      cin >> vi;
      value[i] = vi;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++){
      for (int j = w1; j >= 0; j--){
        for (int k = w2; k >= 0; k--){
          if (weight[i] > j && weight[i] > k) continue;
          else if (weight[i] > j) dp[j][k] = max(dp[j][k], dp[j][k-weight[i]] + value[i]);
          else if (weight[i] > k) dp[j][k] = max(dp[j][k], dp[j-weight[i]][k] + value[i]);
          else dp[j][k] = max(max(dp[j][k], dp[j][k-weight[i]] + value[i]), dp[j-weight[i]][k] + value[i]);
        }
      }
    }
    cout << "Problem " << j << ": " << dp[w1][w2] << endl;
  }

  return 0;
}