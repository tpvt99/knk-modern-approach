#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    int a[N] = {1,2,3,4,5,6,7,8,9,10};
    int *p, *q, temp;
    p = &a[0];
    q = &a[N-1];
    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
    printf("Array after modified: ");
    p = &a[0];
    while (p < &a[N])
        printf("%d ", *p++);
    return 0;
}
