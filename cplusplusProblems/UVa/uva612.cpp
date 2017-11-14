#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int inversionCount(string dna){
    /*set<char> dnaSet;
    set<char>::iterator it;
    dnaSet.insert(dna[0]);
    int invCount = 0;
    for (int i = 1; i < dna.length(); i++)
    {
        dnaSet.insert(dna[i]);
        it = dnaSet.upper_bound(dna[i]);
        cout << distance(it, dnaSet.end()) << endl;
        invCount += distance(it, dnaSet.end());
    }*/
    int invCount = 0;
    for (int i = 0; i < (dna.length()-1); i++)
    {
        for (int b = i + 1; b < dna.length(); b++)
        {
            if (dna[i] > dna[b])
                ++invCount;
        }
    }
    return invCount;
}

bool aGreaterThanB(const string a, const string b){
    return inversionCount(a) < inversionCount(b);
}

int main(){
    int numSets;
    cin >> numSets;
    cin.ignore();
    while (numSets--){
        int length, num;
        scanf("%d %d", &length, &num);
        vector<string> dVector;
        while (num--){
            string dna;
            cin >> dna;
            dVector.push_back(dna);
        }
        stable_sort(dVector.begin(), dVector.end(), aGreaterThanB);
        for (int i = 0; i < dVector.size(); i++)
            cout << dVector.at(i) << endl;
        if ((numSets - 1) != -1)
            cout << endl;
    }
    
    return 0;
}