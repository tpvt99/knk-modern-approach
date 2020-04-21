#include <stdio.h>
#include <stdlib.h>

void pay_amount(int dollars, int*, int *, int*, int*);

int main()
{
    int dollars = 134;
    int twenties, tens, fives, ones;
    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars/20;
    dollars = dollars - 20*(*twenties);

    *tens = dollars/10;
    dollars = dollars - 10*(*tens);

    *fives = dollars/5;
    *ones = dollars - 5*(*fives);

}
