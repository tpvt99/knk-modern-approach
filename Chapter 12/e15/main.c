#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temperature[7][24] = {  {12,43,21,12},
                                {12,13,14,15},
                                {43,54,65,76},
                                {12,23,43,54}};

    int row = 1;
    int *q = *(temperature+row);
    for(;q<*(temperature+row)+24;q++)
        printf("%d ", *q);

    int *k = &temperature[1][2];
    int *i = temperature[1] + 2;
    //&(temperature[1]+2) wrong because of & is not used before l-value
    int (*j)[24] = &(temperature[1]); // Must be first element of array
    int (*t)[24] = temperature+1;
    // int (*a)[7][24] = &(temperature+1); wrong because of & is not used before l-value
    int (*a)[7][24] = &(temperature); // Must be first element of array
    return 0;
}
