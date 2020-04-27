#include <stdio.h>
#include <stdlib.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main()
{
    int a[10] = {12,-43,23,54,65,23,12,11,100};
    int l, sl;
    find_two_largest(a, 10, &l, &sl);
    printf("Largest: %d and second_largest: %d", l, sl);
    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    int *p = a;
    if (*p > *(p+1)) {
        *largest = *p;
        *second_largest = *(p+1);
    } else {
        *largest = *(p+1);
        *second_largest = *p;
    }
    p = p + 2;
    while (p < a + n) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest)
            *second_largest = *p;
        p++;
    }

}
