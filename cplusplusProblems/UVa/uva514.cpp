#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool organise(stack<int> target, stack<int> entry, stack<int> station){
    if (station.size() == 0){
        station.push(entry.top());
        entry.pop();   
    }
    if (station.top() == target.top())
    {
        target.pop();
        station.pop();
        if (target.size() == 0)
            return true;
    }else if (entry.size() != 0){
        station.push(entry.top());
        entry.pop();
    }else if (entry.size() == 0)
        return false;
    return organise(target, entry, station);
}

int main(){
    while (1){
        int inputSize;
        cin >> inputSize;
        cin.ignore();
        if (inputSize == 0)
            break;
        string train;
        while (getline(cin, train)){
            int s = inputSize;
            if (train == "0")
                break;
            istringstream iss(train);
            int coach;
            vector<int> tv;
            stack<int> targetStack;
            stack<int> entryStack;
            stack<int> stationStack;
            while (iss >> coach)
                tv.push_back(coach);
            for (int i = (tv.size()-1); i >= 0; i--)
                targetStack.push(tv.at(i));
            while (s--)
                entryStack.push(s+1);
            if (organise(targetStack, entryStack, stationStack))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}