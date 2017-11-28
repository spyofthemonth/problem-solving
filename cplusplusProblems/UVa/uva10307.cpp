#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int x,y;
priority_queue< pair< int, pair<int, int> > > edges;
map< pair<int, int>, int > aliens;

void bfs(pair<int, int> p, vector< vector<char> > *m){
    queue< pair<int, int> > q;
    map< pair<int, int>, bool > v;
    map< pair<int, int>, int> l;
    q.push(p);
    v[p] = true;
    l[p] = 0;
    vector< pair<int, int> > neighbours;
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        if (current.first != 0) neighbours.push_back(make_pair(current.first-1, current.second));
        if (current.second != 0) neighbours.push_back(make_pair(current.first, current.second-1));
        if (current.first != y-1) neighbours.push_back(make_pair(current.first+1, current.second));
        if (current.second != x-1) neighbours.push_back(make_pair(current.first, current.second+1));
        for (int i = 0; i < neighbours.size(); i++){
            pair<int, int> n = neighbours.at(i);
            if (v[n] == false && m->at(n.first).at(n.second) != '#')
            {
                q.push(n);
                v[n] = true;
                l[n] = l[current] + 1;
                if (m->at(n.first).at(n.second) != ' ')
                    edges.push(make_pair(-l[n], make_pair(aliens[p], aliens[n])));
            }
        }
        neighbours.clear();
    }
}

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

int mst(){
   vector<int> parent(aliens.size()+1, -1);
   int totalDistance = 0;
   while (!edges.empty()){
       pair< int, pair<int, int> > edge = edges.top();
       edges.pop();
       if (!isCycle(&parent, edge.second.first, edge.second.second)){
           totalDistance += (-edge.first);
           un(&parent, edge.second.first, edge.second.second);
       }
   }
   return totalDistance;
}

int main(){
    int nTestCases;
    cin >> nTestCases;
    while (nTestCases--){
        cin >> x >> y;
        cin.ignore();
        vector<char> tmp(x);
        vector< vector<char> > matrix(y, tmp);
        int alienCounter = 0;
        for (int i = 0; i < y; i++)
        {
            string a;
            getline(cin, a);
            for (int b = 0; b < x; b++){
                matrix[i].at(b) = a[b];
                if (a[b] == 'A')
                    aliens[make_pair(i, b)] = ++alienCounter;
                else if (a[b] == 'S')
                    aliens[make_pair(i, b)] = 0;
            }
        }
        for (map< pair<int, int>, int >::iterator it = aliens.begin(); it != aliens.end(); ++it)
            bfs(it->first, &matrix);
            
        cout << mst() << endl;
        aliens.clear();
    }
    return 0;
}