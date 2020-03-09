#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Enter a two-digit number: ");
    scanf("%d", &i);
    int a;
    a = i / 10;
    i -= a*10;
    printf("The reversal is: %1d%1d\n", i,a);
    return 0;
}
