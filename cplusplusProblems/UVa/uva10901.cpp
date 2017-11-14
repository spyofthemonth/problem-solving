#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int numCases;
    scanf("%d", &numCases);
    while (numCases--){
        queue<int> leftB;
        queue<int> rightB;
        queue<int> *currentBank;
        int carLimit, travelTime, numCars, currentTime, currentPos, carryingCount;
        currentTime = 0;
        currentBank = &leftB;
        carryingCount = 0;
        scanf("%d %d %d", &carLimit, &travelTime, &numCars);
        while (numCars--){
            int time;
            char bank[6] = {0};
            scanf("%d %s", &time, bank);
            //printf("%d INIT \n", time);
            if (bank[0] == 'l')
                leftB.push(time);
            else if (bank[0] == 'r')
                rightB.push(time);
        }
        int cars = (leftB.size() + rightB.size());
        //cout << cars << endl;
        while (cars != 0){
            //cout << currentBank->front() << " : " << currentTime << endl;
            if (currentBank->front() <= currentTime && currentBank->size() != 0 && carryingCount <= carLimit)
            {
                //cout << "pick up " << currentBank->front() << endl;
                currentBank->pop();
                ++carryingCount;
            }else if (carryingCount){
                if (*currentBank == leftB)
                    currentBank = &rightB;
                else if (*currentBank == rightB)
                    currentBank = &leftB;
                currentTime += travelTime;
                while (carryingCount--){
                    printf("%d\n", currentTime);
                    --cars;
                }
                carryingCount = 0;
                //cout << "drop off" << endl;
            }else{
                //cout << "waiting" << endl;
                int l = (leftB.size() == 0)? 1000000 : leftB.front();
                int r = (rightB.size() == 0)? 1000000 : rightB.front();
                if (l < r)
                {
                    currentTime += (l - currentTime) + travelTime;
                    currentBank = &leftB;
                }else if (l > r)
                {
                    currentTime += (r - currentTime) + travelTime;
                    currentBank = &rightB;
                }else if (l == r)
                {
                    currentTime += (currentBank->front() - currentTime) + travelTime;
                }
            }
        }
        if ((numCases - 1) != -1)
            printf("\n");
    }
    return 0;
}