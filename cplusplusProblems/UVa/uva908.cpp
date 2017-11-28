#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

priority_queue< pair< int, pair<int,int> > > pq;
bool first = true;

int find(vector<int> *parent, int i){
    if (parent->at(i) == -1)
        return i;
    return find(parent, (*parent)[i]);
}

void un(vector<int> *parent, int x, int y){
    int xParent = find(parent, x);
    int yParent = find(parent, y);
    parent->at(xParent) = yParent;
}

bool isCycle(vector<int> *parent, int x, int y){
    int a, b;
    a = find(parent, x);
    b = find(parent, y);
    return a == b;
}

void initEdgesQueue(int n){
    while (n--){
        int a,b,c;
        cin >> a >> b >> c;
        pq.push(make_pair(-c, make_pair(a, b)));
    }
}

int cost(int n){
    vector<int> parent(n+1, -1);
    int c = 0;
    while (!pq.empty()){
        pair< int, pair<int,int> > edge = pq.top();
        pq.pop();
        if (!isCycle(&parent, edge.second.first, edge.second.second))
        {
            c += (-edge.first);
            un(&parent, edge.second.first, edge.second.second);
        }
    }
    return c;
}

int main(){
    while (1){
        string nComSites;
        getline(cin, nComSites);
        if (nComSites == "")
        {
            getline(cin, nComSites);
            getline(cin, nComSites);
            if (nComSites == "")
                break;
        }
        if (!first)
            cout << endl;
        else
            first = false;
        int i = stoi(nComSites);
        initEdgesQueue(i-1);
        cout << cost(i) << endl;
        int nNewLines;
        cin >> nNewLines;
        initEdgesQueue(nNewLines);
        int nOriginalLines;
        cin >> nOriginalLines;
        initEdgesQueue(nOriginalLines);
        cout << cost(nNewLines + nOriginalLines) << endl;
    }
    return 0;
}