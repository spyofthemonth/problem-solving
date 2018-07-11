#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[2][4][4][4][4];
int n;
char ni;
vector<int> shipments;

int convert(char c){
    if (c == 'M') return 1;
    else if (c == 'F') return 2;
    else return 3;
}

int calcCoal(int incoming, int one, int two){
    int coal = 0;
    for (int i = 1; i < 4; i++){
        if (incoming == i || one == i || two == i)
            coal++;
    }
    return coal;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ni;
        shipments.push_back(convert(ni));
    }
    int s = 0, otherS = 1;
    for (int i = n-1; i >= 0; i--){
        swap(s, otherS);
        for (int one = 0; one < 4; one++){
            for (int two = 0; two < 4; two++){
                for (int three = 0; three < 4; three++){
                    for (int four = 0; four < 4; four++){
                        dp[otherS][one][two][three][four] = max(dp[s][two][shipments[i]][three][four] + calcCoal(shipments[i], one, two), dp[s][one][two][four][shipments[i]] + calcCoal(shipments[i], three, four));
                    }
                }
            }
        }
    }
    cout << dp[otherS][0][0][0][0] << endl;

    return 0;
}