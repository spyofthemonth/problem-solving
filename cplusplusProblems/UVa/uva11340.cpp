#include <iostream>
using namespace std;

int hashLetter(char letter){
    return (letter * 'a') % 100003;
}

int main(){
    int numOfTests;
    cin >> numOfTests;
    for (int i = 0; i < numOfTests; i++)
    {
        int hashTable[1000000];
        fill_n(hashTable, 1000000, 0);
        int accumCost = 0;
        int numOfPaidChars;
        cin >> numOfPaidChars;
        for (int b = 0; b < numOfPaidChars; b++)
        {
            char letter;
            int price;
            cin >> letter >> price;
            hashTable[hashLetter(letter)] = price;
        }
        int lines;
        cin >> lines;
        for (int c = 0; c <= lines; c++)
        {
            string line;
            getline(cin, line);
            for (int s = 0; s < line.length(); s++){
                accumCost += hashTable[hashLetter(line[s])];
            }
        }
        string output = to_string(accumCost);
        if (output.length() == 1)
            output.insert(0, "0.0");
        else if (output.length() < 3)
            output.insert(0, "0.");
        else
            output.insert(output.length() - 2, ".");
        cout << output  << "$" << endl;
    }
    return 0;
}