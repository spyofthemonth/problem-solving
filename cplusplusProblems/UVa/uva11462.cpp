#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while (1){
        int caseSize;
        scanf("%d", &caseSize);
        if (caseSize == 0)
            break;
        vector<int> v;
        while (caseSize--){
            int num;
            scanf("%d", &num);
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (i != (v.size()-1))
                printf("%d ", v.at(i));
            else
                printf("%d", v.at(i));
        }
        printf("\n");
    }
    return 0;
}