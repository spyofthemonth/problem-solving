#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define INF 1000000000
typedef vector< vector<int> > vvi;

int n,m;
vvi raisins;
vvi choc;
int dp[51][51][51][51];

int minRaisins(int rowOne, int colOne, int rowTwo, int colTwo){ //min raisins needed to cut rectangle from these two points (top left, bottom right)
    if (rowOne == rowTwo && colOne == colTwo) return 0;
    if (dp[rowOne][colOne][rowTwo][colTwo] != -1) return dp[rowOne][colOne][rowTwo][colTwo];
    int best = INF;
    for (int i = rowOne; i < rowTwo; i++){
        best = min(best, minRaisins(rowOne, colOne, i, colTwo) + minRaisins(i + 1, colOne, rowTwo, colTwo));
    }
    for (int j = colOne; j < colTwo; j++){
        best = min(best, minRaisins(rowOne, colOne, rowTwo, j) + minRaisins(rowOne, j + 1, rowTwo, colTwo));
    }

    int currentRaisins = raisins[rowTwo][colTwo];
    if (rowOne) currentRaisins -= raisins[rowOne-1][colTwo];
    if (colOne) currentRaisins -= raisins[rowTwo][colOne-1];
    if (rowOne && colOne) currentRaisins += raisins[rowOne-1][colOne-1];

    return dp[rowOne][colOne][rowTwo][colTwo] = (best + currentRaisins);
}

int main(){
    cin >> n >> m;
    choc.resize(n, vector<int>(m));
    raisins.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> choc[i][j];
        }
    }

    raisins[0][0] = choc[0][0];
    for (int i = 1; i < n; i++){ //first col going down
        raisins[i][0] = choc[i][0] + raisins[i-1][0];
    }

    for (int j = 1; j < m; j++){
        raisins[0][j] = choc[0][j] + raisins[0][j-1];
        for (int i = 1; i < n; i++){
            raisins[i][j] = choc[i][j] + raisins[i-1][j] + raisins[i][j-1] - raisins[i-1][j-1];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << minRaisins(0, 0, n-1, m-1) << endl;

    return 0;
}