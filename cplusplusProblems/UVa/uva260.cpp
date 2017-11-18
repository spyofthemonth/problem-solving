#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool found = false;

void dfs(vector < vector<char> > *game, vector < vector<bool> > *visited, int x, int y){
    if (x < 0 || y < 0 || (x+1) > game->size() || (y+1) > game->size())
        return;
    if (visited->at(y).at(x) == true)
        return;
    if (game->at(y).at(x) != 'b')
        return;   
    if ((y+1) == game->size())
    {
        found = true;
        return;
    }
    visited->at(y).at(x) = true;
    dfs(game, visited, x-1, y-1);
    dfs(game, visited, x-1, y);
    dfs(game, visited, x, y-1);
    dfs(game, visited, x, y+1);
    dfs(game, visited, x+1, y);
    dfs(game, visited, x+1, y+1);
}

int main(){
    int gameNum = 0;
    while (1){
        int numRows;
        cin >> numRows;
        if (numRows == 0)
            break;
        vector< vector<char> > game;
        vector< vector<bool> > visited;
        
        vector<bool> tmp;
        tmp.resize(numRows, false);
        visited.resize(numRows, tmp);
        
        for (int i = 0; i < numRows; i++){
            vector<char> r;  
            char a;
            int numCols = numRows;
            while (numCols--){
                cin >> a;
                r.push_back(a);
            }
            game.push_back(r);
        }
        
        for (int i = 0; i < numRows; i++){
            if (game.at(0).at(i) == 'b')
            {
                dfs(&game, &visited, i, 0);
                if (found){
                    break;
                }
                visited.resize(numRows, tmp);
                found = false;
            }
        }
        
        if (!found)
            cout << ++gameNum << " W" << endl;
        else
            cout << ++gameNum << " B" << endl;
        found = false;
        
    }
    
    return 0;
}