#include <iostream>
#include <vector>
using namespace std;

vector<int> st;
vector<int> val = {4, 6, 12, 2, 1, 8};

int left(int p){ return p << 1; }
int right(int p){ return (p << 1) + 1; }

void build(int p, int l, int r){
	if (l == r){
		st[p] = l;
	}
	else{
		build(left(p), l, (l + r) / 2);
		build(right(p), ((l + r) / 2) + 1, r);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = (val[p1] <= val[p2])? p1 : p2;
	}
}

int rmq(int p, int l, int r, int i, int j){
	if (i > r || j < l) return -1;
	if (l >= i && r <= j) return st[p];
	int p1 = rmq(left(p), l, (l + r) / 2, i, j), p2 = rmq(right(p), ((l + r) / 2) + 1, r, i, j);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return (val[p1] <= val[p2])? p1 : p2;
}

void updatePoint(int p, int l, int r, int newVal, int i, int j){
	if (i > r || j < l || l > r)
		return;
	if (l == r){
		val[st[p]] = newVal;
		return;
	}
	updatePoint(left(p), l, (l + r) / 2, newVal, i, j);
	updatePoint(right(p), ((l + r) / 2) + 1, r, newVal, i, j);
	int p1 = st[left(p)], p2 = st[right(p)];
	st[p] = (val[p1] <= val[p2])? p1 : p2;
}



int main(){
	st.resize(4 * 6, 0);
	build(1, 0, 5);
	cout << rmq(1, 0, 5, 0, 3) << endl; //outputs 3
	updatePoint(1, 0, 5, 20, 1, 3);
	cout << rmq(1, 0, 5, 0, 3) << endl; //outputs 0
	//returns index
	return 0;
}