#include <stdio.h>
#include <stdlib.h>

void store_zero(int a[], int n) {
    int *p;
    for (p=a;p<a+n;p++)
        *p = 0;
}

int main()
{
    int a[10];
    store_zero(a, 10);
    printf("Elements of array: ");
    int *p = a;
    while(p <a+10)
        printf("%d ", *p++);
    return 0;
}
