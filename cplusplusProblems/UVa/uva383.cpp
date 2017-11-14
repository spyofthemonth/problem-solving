#include <iostream>
#include <map>
#include <queue>
using namespace std;

int bfs(map< string, vector<string> > *graph, string source, string des){
    queue<string> q;
    map<string, bool> v;
    map<string, int> l;
    q.push(source);
    v[source] = true;
    l[source] = 0;
    while (!q.empty()){
        string p = q.front();
        q.pop();
        for (int i = 0; i < (*graph)[p].size(); i++){
            if (v[(*graph)[p][i]] == false){
                q.push((*graph)[p][i]);
                v[(*graph)[p][i]] = true;
                l[(*graph)[p][i]] = l[p] + 1;
            }
        }
    }
    
    if (v[des]){
        return l[des];
    }else{
        return 0;
    }
}

int main(){
    int numData;
    cin >> numData;
    cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
    for (int i = 0; i < numData; i++){
        int numWarehouses, numLegs, numShipping;
        map< string, vector<string> > graph;
        cin >> numWarehouses >> numLegs >> numShipping;
        while (numWarehouses--){
            string warehouse;
            cin >> warehouse;
            vector<string> wv;
            graph[warehouse] = wv;
        }
        while (numLegs--){
            string s, d;
            cin >> s >> d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        cout << "DATA SET  " << i+1 << endl << endl;
        while (numShipping--){
            int size;
            string source, des;
            cin >> size >> source >> des;
            int legs = bfs(&graph, source, des);
            if (legs){
                cout << "$" << (legs * size * 100) << endl;
            }else{
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}