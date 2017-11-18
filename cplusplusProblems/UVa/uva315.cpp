#include <iostream>
#include <map>
#include <vector>
using namespace std;

int t = 0;

void apSearch(int u, map<int, bool> *visited, map<int, int> *disc, map<int, int> *low, map<int, int> *parent, map<int, bool> *ap, map< int, vector<int> > *network){
    int children = 0;
    (*visited)[u] = true;
    (*disc)[u] = (*low)[u] = ++t;
    for (int i = 0; i < (*network)[u].size(); i++){
        int v = (*network)[u][i];
        if (!(*visited)[v])
        {
            children++;
            (*parent)[v] = u;
            apSearch(v, visited, disc, low, parent, ap, network);
            (*low)[u] = min((*low)[u], (*low)[v]);
            
            if ((*parent)[u] == 0 && children > 1)
                (*ap)[u] = true;
            else if ((*parent)[u] != 0 && (*low)[v] >= (*disc)[u])
                (*ap)[u] = true;
            
        }else if (v != (*parent)[u])
            (*low)[u] = min((*low)[u], (*disc)[v]);
    }
}

int main(){
    while (1){
        int nPlaces;
        cin >> nPlaces;
        if (nPlaces == 0)
            break;
        map< int, vector<int> > network;
        int first;
        ++nPlaces;
        while (nPlaces--){
            int place, rPlace;
            cin >> rPlace;
            if (rPlace == 0)
                break;
            while (cin >> place){
                network[rPlace].push_back(place);
                network[place].push_back(rPlace);
                first = rPlace;
                if (cin.get() == '\n')
                    break;
            }
        }
        
        map<int, bool> visited;
        map<int, int> disc;
        map<int, int> low;
        map<int, int> parent;
        map<int, bool> ap;
        apSearch(first, &visited, &disc, &low, &parent, &ap, &network);
        int nAps = 0;
        for (map<int, bool>::iterator it = ap.begin(); it != ap.end(); ++it){
            if(it->second == true)
                ++nAps;
        }
        cout << nAps << endl;
    }
    
    return 0;
}