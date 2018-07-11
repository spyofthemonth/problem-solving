#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void find_subset(int n, int l, int u, vector<int> w){
    vector<ii> v;
    for (int i = 0; i < n; i++){
        v.push_back(make_pair(w[i], i));
    }
    sort(v.begin(), v.end());
    vector<ii> molecules;
    ll sum = 0;
    int x = -1;
    for (int i = 0; i < n; i++){
        if (x != -1){
            if (sum >= l){
                break;
            }else{
                sum += v[i].first;
                molecules.push_back(v[i]);
                sum -= molecules.front().first; //lose the back
                molecules.erase(molecules.begin());
            }
        }else if (sum + v[i].first > u){
            x = i;
            i--;
        }else{
            sum += v[i].first;
            molecules.push_back(v[i]);
        }
    }

    if (sum >= l && sum <= u){
        cout << molecules.size() << endl;
        for (int i = 0; i < molecules.size(); i++){
            if (i != molecules.size() - 1)
                cout << molecules[i].second << " ";
            else
                cout << molecules[i].second << endl;
        }
    }else{
        cout << "0" << endl;
    }
}

int main(){
    int n,l,u;
    cin >> n >> l >> u;
    vector<int> w(n);
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    find_subset(n, l, u, w);
}