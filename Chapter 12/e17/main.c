#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int sum_two_dimensional_array(const int *a, int n);

int main()
{
    int a[3][LEN] = {{1,2,3,4,5},{6,7,8,9,10},{-1,-2,-5,-6,-8}};
    int sum = sum_two_dimensional_array(&a[0][0], 3);
    printf("Sum is: %d", sum);
    return 0;
}

int sum_two_dimensional_array(const int *a, int n) {
    int *p = a;
    int sum = 0;
    for (;p<a+n*LEN;p++)
        sum += *p;
    return sum;
}
