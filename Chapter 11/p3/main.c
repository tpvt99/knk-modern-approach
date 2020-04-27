#include <stdio.h>
#include <stdlib.h>

void reduce(int numerator, int denominator, int *, int *);

int main()
{
    printf("Enter a fraction: ");
    int numerator, denominator;
    scanf("%d/%d", &numerator, &denominator);
    int reduced_numerator, reduced_denominator;
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
    printf("In lowest terms: %d/%d", reduced_numerator, reduced_denominator);
    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int a = numerator, b = denominator;
    while (denominator != 0) {
        int re = numerator % denominator;
        numerator = denominator;
        denominator = re;
    }
    *reduced_numerator = a / numerator;
    *reduced_denominator = b / numerator;
}
