#include <stdio.h>
#include <stdlib.h>

#define N 10;

void max_min(int *a, int n, int *max, int *min);

int main()
{
    int max, min;
    int a[10] = {12,43,54,12,34,54,76,-10,0};
    max_min(a, 10, &max, &min);
    printf("Max: %d, min: %d", max, min);
    return 0;
}

void max_min(int *a, int n, int *max, int *min) {
    int *ptr = a;
    *max = *min = *ptr;
    for(;ptr<a+n;ptr++){
        if (*ptr > *max)
            *max = *ptr;
        else if (*ptr < *min)
            *min = *ptr;
    }
}
