#include <stdio.h>
#include <stdlib.h>

int find_largest(int n, int (*)[*]);

int main()
{
    int temperature[7][24] = {  {12,43,21,12},
                                {12,13,14,15},
                                {43,54,65,76},
                                {12,23,43,54}};

    for (int (*p)[24] = &temperature[0];p < &temperature[0] + 7; p++) {
        int largest = find_largest(24, p);
        printf("Largest of day: %d\n", largest);
    }

    return 0;
}

int find_largest(int n, int (*ptr)[n]) {

    int largest = 0;
    for (int *p = *ptr;p<*(ptr)+n;p++) {
        if (*p > largest)
            largest = *p;
    }
    return largest;
}
