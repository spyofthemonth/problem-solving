#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Player{
    int num, numSolvedProblems;
    int problems[10];
    Player(){
        num = numSolvedProblems = 0;
        fill_n(problems, 11, 0);
    }
    int penaltyTime(){
        int time = 0;
        for (int i = 1; i < 11; i++)
        {
            if (problems[i] > 0)
                time += problems[i];
        }
        return time;
    }
};

bool aGreaterThanB(Player &a, Player &b){
    if (a.numSolvedProblems != b.numSolvedProblems)
        return a.numSolvedProblems > b.numSolvedProblems;
    else if (a.penaltyTime() != b.penaltyTime())
        return a.penaltyTime() > b.penaltyTime();
    else
        return a.num > b.num;
}

int main(){
    int numTestCases;
    cin >> numTestCases;
    cin.ignore();
    //scanf("%d", &numTestCases);
    while (numTestCases--){
        cin.ignore();
        map<int, Player> players;
        int playerNum, probNum, time;
        char type;
        string buffer;
        while (getline(cin, buffer)){
            if (buffer == "")
                break;
            //cout << buffer << endl;
            istringstream iss(buffer);
            iss >> playerNum >> probNum >> time >> type;
            //scanf("%d %d %d %c", &playerNum, &probNum, &time, &type);
            //printf("%d %d %d %c \n", playerNum, probNum, time, type);
            if (type == 'C' || type == 'I')
            {
                if (!players.count(playerNum))
                {
                    Player temp;
                    temp.num = playerNum;   
                    players[playerNum] = temp;
                }
                if (type == 'C')
                {
                    players[playerNum].problems[probNum] -= time;
                    players[playerNum].problems[probNum] *= -1;
                    players[playerNum].numSolvedProblems++;
                }else if (type == 'I')
                {
                    players[playerNum].problems[probNum] -= 20;
                }
            }
            
            
        }
        vector<Player> pVector;
        for (map<int, Player>::iterator it=players.begin(); it != players.end(); ++it)
            pVector.push_back(it->second);
        sort(pVector.begin(), pVector.end(), aGreaterThanB);
        for (int i = 0; i < pVector.size(); i++)
        {
            Player player = pVector.at(i);
            printf("%d %d %d \n", player.num, player.numSolvedProblems, player.penaltyTime());
        }
        if ((numTestCases - 1) != -1)
            printf("\n");
    }
    return 0;
}