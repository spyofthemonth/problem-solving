#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INF 1000000000

vector<int> cards;
vector< set<int> > lists;

int main(){
  int n,c,previous = 0, currentList = 0, smallestStraight = INF, original = 0, indexMinLength;
  cin >> n;
  lists.resize(n);
  for (int i = 0; i < n; i++){
    cin >> c;
    cards.push_back(c);
  }
  if (!n){
    cout << "0" << endl;
    return 0;
  }
  sort(cards.begin(), cards.end());
  for (int i = 0; i < n; i++){
    if (!i){
      previous = cards[i];
      lists[currentList].insert(cards[i]);
    }else if (cards[i] - previous == 1){
      previous = cards[i];
      lists[currentList].insert(cards[i]);
    }else if (cards[i] == previous){
      original = currentList;
      currentList = 0;
      indexMinLength = INF;

      while (true){
        set<int>::reverse_iterator rit = lists[currentList].rbegin();
        if (!lists[currentList].count(cards[i]) && lists[currentList].size() <= ((indexMinLength == INF)? INF : lists[indexMinLength].size()) && cards[i] - *rit == 1){
          indexMinLength = currentList;
        }
        if (currentList == original && indexMinLength == INF){
          lists[++currentList].insert(cards[i]);
          break;
        }
        else if (currentList == original && indexMinLength != INF){
          lists[indexMinLength].insert(cards[i]);
          break;
        }
        else
          currentList++;
      }

    }else{
      previous = cards[i];
      lists[++currentList].insert(cards[i]);
    }
  }
  for (int i = 0; i <= currentList; i++){
    if (lists[i].size() < smallestStraight)
      smallestStraight = lists[i].size();
  }
  cout << smallestStraight << endl;
  return 0;
}