#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define INF 1000000000

int main(){
    int nCase = 0;
    while (1){
        int u,v;
        cin >> u >> v;
        if (u == 0 && v == 0)
            break;
        vector<int> tmp(101, INF);
        vector< vector<int> > adjMatrix(101, tmp);
        adjMatrix[u][v] = 1;
        while (1){
            cin >> u >> v;
            if (u == 0 && v == 0)
                break;
            adjMatrix[u][v] = 1;
        }
        for (int k = 0; k < 101; k++){
            for (int i = 0; i < 101; i++){
                for (int j = 0; j < 101; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
        int sum = 0, count = 0;
        for (int i = 0; i < 101; i++){
            for (int j = 0; j < 101; j++){
                if (i != j && adjMatrix[i][j] != INF){
                    sum += adjMatrix[i][j];
                    ++count;
                }
            }
        }
        cout << "Case " << ++nCase << ": average length between pages = " << setprecision(3) << fixed << (double)sum / count << " clicks" << endl;   
    }
    return 0;
}