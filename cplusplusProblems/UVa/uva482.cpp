#include <iostream>
#include <vector>
using namespace std;


int main(){
    int numOfQueries;
    cin >> numOfQueries;
    for (int i = 0; i < numOfQueries; i++)
    {
        int count = 0;
        cin.ignore();
        int intInput;
        vector<int> indices;
        while (cin >> intInput){
            indices.push_back(intInput);
            ++count;
            if (cin.get() == '\n')
                break;
        }
        string floatInput;
        vector<string> floatVector;
        while (cin >> floatInput){
            floatVector.push_back(floatInput);
            if (cin.get() == '\n')
                break;
        }
        string nArr[100000];
        for (int b = 0; b < floatVector.size(); b++)
            nArr[indices.at(b)] = floatVector.at(b);

        for (int c = 1; c <= count; c++)
            cout << nArr[c] << endl;
        if (i != (numOfQueries - 1))
            cout << endl;
    }

    return 0;
}