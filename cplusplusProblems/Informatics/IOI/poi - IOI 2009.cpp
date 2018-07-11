#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Contestant{
    int points,nTasksSolved,id;
    bool tasks[2001];
};

int n,t,p,ki;
vector<int> taskValue;
vector<Contestant> c;

bool customComp(const Contestant &a, const Contestant &b){ //top first, worst last
    if (a.points != b.points){
        return a.points > b.points;
    }else if (a.nTasksSolved != b.nTasksSolved){
        return a.nTasksSolved > b.nTasksSolved;
    }else{
        return a.id < b.id;
    }
}

int main(){
    cin >> n >> t >> p;
    c.resize(n+1);
    taskValue.resize(t);
    for (int i = 1; i <= n; i++){
        c[i].id = i;
        for (int j = 0; j < t; j++){
            cin >> ki;
            if (!ki)
                taskValue[j]++;
            else{
                c[i].nTasksSolved++;
                c[i].tasks[j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < t; j++){
            if (c[i].tasks[j])
                c[i].points += taskValue[j];
        }
    }

    sort(c.begin(), c.end(), customComp);
    for (int i = 0; i < c.size(); i++){
        if (c[i].id == p){
            cout << c[i].points << " " << (i+1) << endl;
            break;
        }
    }


    return 0;
}