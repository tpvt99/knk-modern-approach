#include <stdio.h>
#include <stdlib.h>

int main()
{

    // part a
    struct {
        double real;
        double imaginary;
    } c1 = {0.0, 1.0}, c2 = {.real = 1.0, .imaginary = 0.0}, c3;

    c1 = c2;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    printf("Member of c1: %.2f %.2f\n", c1.real, c1.imaginary);
    printf("Member of c2: %.2f %.2f\n", c2.real, c2.imaginary);
    printf("Member of c3: %.2f %.2f\n", c3.real, c3.imaginary);
    return 0;
}
