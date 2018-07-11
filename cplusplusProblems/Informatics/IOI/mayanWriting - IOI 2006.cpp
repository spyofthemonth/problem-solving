#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int g,sn,tot;
char ci;
set<char> w;
queue<char> q;
vector<int> countInW(128);
vector<int> countInQueue(128);

int main(){
    cin >> g >> sn;
    for (int i = 0; i < g; i++){
        cin >> ci;
        w.insert(ci);
        countInW[ci]++;
    }
    for (int i = 0; i < sn; i++){
        cin >> ci;
        q.push(ci);
        countInQueue[ci]++;
        while (!w.count(ci) || countInQueue[ci] > countInW[ci]){
            if (q.empty()) break;
            countInQueue[q.front()]--;
            q.pop();
        }
        if (q.size() == g) tot++;
    }

    cout << tot << endl;
    return 0;
}