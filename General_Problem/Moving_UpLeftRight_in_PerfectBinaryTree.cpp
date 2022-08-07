#include <stdio.h>
#include <math.h>

int main() {
    long long int n,testCase;
    scanf("%lld %lld",&n,&testCase);
    long long int nextPowerof2 = n+1;
    long long int level = 0;

    while(nextPowerof2 != 1) {
        nextPowerof2 = nextPowerof2/2;
        level++;
    }

    while(testCase--) {
        long long int startNum;
        char str[1000000];
        scanf("%lld %s",&startNum,str);


        long long int idx = 0;

        //Iterating until the string get finished
        while(str[idx] != '\0') {
                long long int currLevel = level;
                while(startNum%((long long int)1<<(currLevel-1)) != 0) {
                    currLevel--;
                }

            if(str[idx] == 'L' || str[idx] == 'R') {
                if(currLevel == 1) {
                    idx++;
                    continue;
                }
                if(str[idx] == 'L') {
                    startNum = startNum-((long long int)1<<(currLevel-2));
                }
                else if(str[idx] == 'R') {
                    startNum = startNum+((long long int)1<<(currLevel-2));
                }
            }
            else if(str[idx] == 'U') {
                if(currLevel == level) {
                    idx++;
                    continue;
                }
                    if((startNum/(long long int)pow(2,currLevel))%2 == 0) {
                        startNum = startNum+((long long int)1<<(currLevel-1));
                    }
                    else {
                        startNum = startNum-((long long int)1<<(currLevel-1));
                    }
            }
            idx++;
        }
        printf("%lld\n",startNum);
    }
}