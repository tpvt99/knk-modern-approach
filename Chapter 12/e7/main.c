#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(const int [], int n, int key);

int main()
{
    int a[5] = {12,43,-2,0,23};
    int key = 13;
    if (search(a,5,key))
        printf("%d is inside the array\n", key);
    else
        printf("%d is not inside the array\n", key);
    return 0;
}

bool search(const int a[], int n, int key) {
    int *p = a;
    while (p<a+n) {
        if (*p++ == key)
            return true;
        //printf("Relative position: %d", p-a);
    }
    return false;
}
