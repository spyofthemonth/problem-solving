#include <iostream>
#include <stack>
using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    cin.ignore();
    while (nCases--){
        string seq;
        getline(cin, seq);
        if (seq.length()  == 0){
            cout << "Yes" << endl;
            continue;
        }
        stack<char> s;
        for (int i = 0; i < seq.length(); i++){
            if (seq[i] == '(' || seq[i] == '[')
                s.push(seq[i]);
            else if (s.size()){
                if (seq[i] == ')' && s.top() == '(')
                    s.pop();
                else if (seq[i] == ']' && s.top() == '[')
                    s.pop();
                else{
                    s.push('0');
                    break;
                }
            }else{
                s.push('0');
                break;
            }
        }
        if (!s.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}