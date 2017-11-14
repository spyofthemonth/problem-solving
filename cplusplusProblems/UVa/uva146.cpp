#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> sequences;
    while (true){
        string seqInput;
        cin >> seqInput;
        if (seqInput == "#")
            break;
        sequences.push_back(seqInput);
    }
    for (int i = 0; i < sequences.size(); i++)
    {
        string seq = sequences.at(i);
        if ((next_permutation(seq.begin(), seq.end())))
            cout << seq << endl;
        else
            cout << "No Successor" << endl;
    }
    return 0;
}