#include <stdio.h>
#include <stdlib.h>

int find_largest(int *, int );

int main()
{
    int a[5] = {-12,0,43,67,100};
    int largest = find_largest(a, 5);
    printf("Largest value: %d", largest);
    return 0;
}

int find_largest(int *a, int n) {
    int *p = a;
    int largest = *p++;
    while (p < a + n) {
        if (*p > largest)
            largest = *p;
        p++;
    }
    return largest;
}
