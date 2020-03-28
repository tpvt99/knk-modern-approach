#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define NUM_DAYS (int) (sizeof(weekend) / sizeof(weekend[0]))

int main()
{
    typedef int bool;
    bool weekend[7] = {[0] = true, [6] = true};
    int i;
    for (i = 0; i< NUM_DAYS; i++)
        printf("Weekend[%d]: %d\n", i, weekend[i]);
    return 0;
}
