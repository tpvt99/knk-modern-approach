#include <stdio.h>
#include <stdlib.h>

int *find_middle(int a[], int n) {
    return a + n/2;
}

int main()
{
    int a[4] = {12,43,54,23};
    int *p = find_middle(a, 4);
    printf("Return value is: %d", *p);
    return 0;
}
