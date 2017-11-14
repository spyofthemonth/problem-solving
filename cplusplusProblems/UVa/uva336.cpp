#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
    int caseNum = 0;
    while (1){
        int numConnections;
        cin >> numConnections;
        if (numConnections == 0)
            break;
        map< int, vector<int> > network;
        while (numConnections--){
            int a, b;
            cin >> a >> b;
            network[a].push_back(b);
            network[b].push_back(a);
        }
        while (1){
            queue<int> q;
            map<int, bool> m;
            map<int, int> l;
            int a, b, c;
            c = 0;
            cin >> a >> b;
            if (a == 0 && b == 0)
                break;
            q.push(a);
            m[a] = true;
            l[a] = 0;
            while (!q.empty()){
                int p = q.front();
                q.pop();
                for (int i = 0; i < network[p].size(); i++){
                    if (m[network[p][i]] == false)
                    {
                        q.push(network[p][i]);
                        m[network[p][i]] = true;
                        l[network[p][i]] = l[p] + 1;
                    }
                }
            }
            for (map<int, int>::iterator it = l.begin(); it != l.end(); ++it){
                if (it->second <= b)
                    c++;
            }
            cout << "Case " << ++caseNum << ": " << (network.size() - c) << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl;
        }
        cin.ignore();
    }
    return 0;
}