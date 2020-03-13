#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* First method
    int b, a;
    printf("Enter a number: ");
    scanf("%d", &b);
    int counter = 0;
    if (b != 0)
        counter += 1;
    a = b / 10;
    if (a!=0)
        counter += 1;
    a = a/10;
    if (a!= 0)
        counter += 1;
    a = a/10;
    if (a!= 0)
        counter += 1;
    a = a/10;
    if (a!=0)
        counter += 1;
    printf("The number %d has %d digits\n", b, counter); */
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int x = 0;
    if (a >= 0 && a <= 9)
        x = 1;
    else if (a >= 10 && a <= 99)
        x = 2;
    else if (a >= 100 && a <= 999)
        x = 3;
    else if (a >= 1000 && a <= 9999)
        x = 4;
    printf("The number %d has %d digits\n", a, x);
    return 0;
}
