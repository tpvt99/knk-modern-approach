#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter a dollar amount: ");
    scanf("%d", &x);
    int amount20 = x/20;

    x = x - 20*amount20;
    int amount10 = x/10;

    x = x - 10*amount10;
    int amount5 = x/5;

    x = x - 5*amount5;

    printf("$20 bills: %d\n", amount20);
    printf("$10 bills: %d\n", amount10);
    printf("$5 bills: %d\n", amount5);
    printf("$1 bills: %d\n", x);

}
