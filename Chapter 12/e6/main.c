#include <stdio.h>
#include <stdlib.h>

int sum_array(const int *a, int n) {
    int sum = 0;
    int *p;
    for (p = a; p<a + n; p++) {
        sum += *p;
    }
    return sum;
}

int main()
{
    int a[5] = {1,2,3,4,5};
    int sum = sum_array(a, 5);
    printf("Sum of array is: %d", sum);
    return 0;
}
