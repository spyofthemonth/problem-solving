#include <stdio.h>

int main(){
    int numOfTestCases;
    scanf("%d", &numOfTestCases);
    while (numOfTestCases--){
        int numOfCarriages;
        int numOfSwitches = 0;
        int trains[50] = {0};
        scanf("%d", &numOfCarriages);
        for (int i = 0; i < numOfCarriages; i++)
            scanf("%d", &trains[i]);
        bool switched = true;
        while (switched){
            switched = false;
            for (int i = 0; i < (numOfCarriages-1); i++)
            {
                if (trains[i] > trains[i+1])
                {
                    int temp = trains[i];
                    trains[i] = trains[i+1];
                    trains[i+1] = temp;
                    switched = true;
                    ++numOfSwitches;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", numOfSwitches);
    }
    return 0;
}