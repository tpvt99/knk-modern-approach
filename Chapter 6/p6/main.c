#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number n: ");
    scanf("%d", &n);
    for (int i = 1; i*i <= n; i++) {
        if (i%2==0)
            printf("%d\n",i*i);
    }
    return 0;
}
