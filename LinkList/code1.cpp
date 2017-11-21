#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

    int GetJumpCount(int input1,int input2,int input3_size, int* input3)
    {

        int attempts = 0;

        for (int i = 0 ; i < input3_size ; i++ ) {

            int target = input3[i] ;
           // cout << target << endl;
            if( target <= input1 )
                attempts += 1;

            else if( target > input1 ) {
                int climbed = 0;
                while( target > climbed ) {
                    climbed += input1;

                    attempts++;
                    if( target == climbed ) {
                        continue;
                    }
                }
            }
        //cout << "A-" <<" "<< target << attempts << endl;
        }
    return attempts+1;

    }
   // ip1 - X
   //ip2 - Y
   //ip3 - Number of Walls

int main() {
    int output = 0;
    int ip1;
    scanf("%d", &ip1);
    int ip2;
    scanf("%d", &ip2);
    int ip3_size = 0;
    int ip3_i;
    scanf("%d\n", &ip3_size);
    int ip3[ip3_size];
    for(ip3_i = 0; ip3_i < ip3_size; ip3_i++) {
        int ip3_item;
        scanf("%d", &ip3_item);

        ip3[ip3_i] = ip3_item;
    }
    output = GetJumpCount(ip1,ip2,ip3_size,ip3);
    printf("%d\n", output);
    return 0;
}
