#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &a);
    printf("In octal, your number is: ");
    int x,y,z,m,k;
    x = a % 8;

    a = a / 8;
    y = a % 8;

    a = a/8;
    z = a % 8;

    a = a/8;
    m = a % 8;

    a = a/8;
    k = a % 8;
    printf("%d%d%d%d%d\n", k,m,z,y,x);
    return 0;
}
