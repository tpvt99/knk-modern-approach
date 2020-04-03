#include <stdio.h>
#include <stdlib.h>

#define N (int) (sizeof(a) / sizeof(a[0]))

int main()
{
    int a[5], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i<N;i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");
    for (i = N-1; i>= 0; i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
