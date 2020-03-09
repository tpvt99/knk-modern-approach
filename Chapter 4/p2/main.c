#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a three-digit number: ");
    scanf("%d", &a);
    int i;
    i = a/100;
    a -= i*100;
    printf("The reversal is: %d%d%d\n", a%10, a/10, i);
    return 0;
}
