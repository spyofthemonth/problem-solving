#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long int n,m;
    vector<int> trees;
    scanf("%d %d", &n, &m);
    while (n--){
        int tree;
        scanf("%d", &tree);
        trees.push_back(tree);
    }
    sort(trees.begin(), trees.end());
    long long int beg = 0, mid, end = trees.at(trees.size()-1);
    long long int finalCut = 0;
    while (beg <= end){
        mid = (beg + end) / 2;
        long long int cutted = 0;
        for (int i = 0; i < trees.size(); i++){
            if (trees[i] - mid > 0)
                cutted += trees[i] - mid;
        }
        if (cutted > m){
            beg = mid + 1;
            if (mid > finalCut)
                finalCut = mid;
        }else if (cutted < m)
            end = mid - 1;
        else{
            finalCut = mid;
            break;
        }
    }
    printf("%d", finalCut);
    return 0;
}