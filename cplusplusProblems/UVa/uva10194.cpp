#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <locale>
using namespace std;

struct team{
    string name;
    int pointsEarned, gamesPlayed, wins, ties, losses, gScored, gAgainst;
    void readGame(int goals, int goalsAgainst){
        gamesPlayed++;
        gScored += goals;
        gAgainst += goalsAgainst;
        if (goals == goalsAgainst)
        {
            pointsEarned++;
            ties++;
        }else if (goals > goalsAgainst)
        {
            pointsEarned += 3;
            wins++;
        }else
            losses++;
            
    }
    
    team(){
        pointsEarned = gamesPlayed = wins = ties = losses = gScored = gAgainst = 0;
    }
};

bool aGreaterThanB(const team& a, const team& b){
    if (a.pointsEarned != b.pointsEarned)
        return a.pointsEarned > b.pointsEarned;
    else if (a.wins != b.wins)
        return a.wins > b.wins;
    else if ((a.gScored - a.gAgainst) != (b.gScored - b.gAgainst))
        return (a.gScored - a.gAgainst) > (b.gScored - b.gAgainst);
    else if (a.gScored != b.gScored)
        return a.gScored > b.gScored;
    else if (a.gamesPlayed != b.gamesPlayed)
        return a.gamesPlayed < b.gamesPlayed;
    else{
        //return true;
        locale loc;
        size_t len;
        if (a.name.length() > b.name.length())
            len = a.name.length();
        else
            len = b.name.length();
        for (int i = 0; i < len; i++)
        {
            if (tolower(a.name[i], loc) != tolower(b.name[i], loc)){
                return tolower(a.name[i], loc) < tolower(b.name[i], loc);
        }
                
    }
}

int main(){
    int numOfTourn;
    cin >> numOfTourn;
    cin.ignore();
    while (numOfTourn--){
        string tournName;
        getline(cin, tournName);
        int numOfTeams;
        cin >> numOfTeams;
        cin.ignore();
        map<string, team> teams;
        //cout << teams["D"].pointsEarned << endl;
        while (numOfTeams--){
            team t;
            //cout << t.gScored << endl;
            getline(cin, t.name);
            teams[t.name] = t;
        }
        int numOfGames;
        cin >> numOfGames;
        cin.ignore();
        while (numOfGames--){
            string game;
            getline(cin, game);
            size_t pos = game.find("@");
            string p1 = game.substr(0, pos);
            string p2 = game.substr(pos+1);
            //cout << p1 << endl << p2 << endl;
            size_t hashP1 = p1.find("#");
            size_t hashP2 = p2.find("#");
            teams[p1.substr(0, hashP1)].readGame(stoi(p1.substr(hashP1+1)), stoi(p2.substr(0, hashP2)));
            teams[p2.substr(hashP2+1)].readGame(stoi(p2.substr(0, hashP2)), stoi(p1.substr(hashP1+1)));
        }
        cout << tournName << endl;
        vector<team> v;
        for (map<string, team>::iterator it=teams.begin(); it != teams.end(); ++it)
            v.push_back(it->second);
        sort(v.begin(), v.end(), aGreaterThanB);
        
        for (int i = 0; i < v.size(); i++){
            team current = v.at(i);
            cout << i+1 << ") " << current.name << " " << current.pointsEarned << "p, " << current.gamesPlayed << "g (" << current.wins << "-" << current.ties << "-" << current.losses << "), " << (current.gScored - current.gAgainst) << "gd (" << current.gScored << "-" << current.gAgainst << ")" << endl;
        }
        if ((numOfTourn - 1) != -1)
            cout << endl;
    }
    return 0;
}