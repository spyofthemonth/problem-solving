#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool moveCard(int left, vector<stack<string>> *piles, int i){
    string card = piles->at(i).top();
    string des = piles->at(i-left).top();
    if (card[0] == des[0] || card[1] == des[1])
    {
        piles->at(i-left).push(card);
        piles->at(i).pop();
        if (piles->at(i).size() == 0)
            piles->erase(piles->begin()+(i));
        return true;
    }
    return false;
}

int main(){
    while (1){
        bool eoi = false;
        vector<stack<string>> piles;
        for (int i = 0; i < 52; i++){
            string card;
            cin >> card;
            if (card == "#"){
                eoi = true;
                break;
            }
            stack<string> cStack;
            cStack.push(card);
            piles.push_back(cStack);
        }
        if (eoi)
            break;
        bool noShifts = false;
        while (!noShifts){
            noShifts = true;
            for (int i = 0; i < piles.size(); i++)
            {
                if (i > 2){
                    if(moveCard(3, &piles, i))
                    {
                        noShifts = false;
                        break;
                    }
                }
                if (i >= 1){
                    if (moveCard(1, &piles, i))
                    {
                        noShifts = false;
                        break;
                    }
                }
            }
        }
        cout << piles.size() << ((piles.size() != 1)? " piles remaining: " : " pile remaining: ");
        for (int i = 0; i < piles.size(); i++)
        {
            cout << piles.at(i).size();
            if ((i + 1) != piles.size())
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}