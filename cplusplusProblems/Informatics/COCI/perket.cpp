#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

int n,s,b,minDiff = INF;
vector<int> sour;
vector<int> bitter;

void sourBitterDiff(int i, int sourness, int bitterness){
	if (i == n){
		if (abs(sourness - bitterness) < minDiff && bitterness) minDiff = abs(sourness - bitterness);
	}
	else{
		sourBitterDiff(i+1, sourness, bitterness);
		sourBitterDiff(i+1, sourness * sour[i], bitterness + bitter[i]);
	}
}

int main(){
	cin >> n;
	sour.resize(n);
	bitter.resize(n);
	for (int i = 0; i < n; i++){
		cin >> s >> b;
		sour[i] = s;
		bitter[i] = b;
	}
	sourBitterDiff(0, 1, 0);
	cout << minDiff << endl;
	return 0;
}