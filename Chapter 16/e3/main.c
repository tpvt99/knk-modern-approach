#include <stdio.h>
#include <stdlib.h>

struct complex {
    double real;
    double imaginary;
};

struct complex make_complex(double real, double imaginary) {
    struct complex c = {.real = real, .imaginary = imaginary};
    return c;
};

struct complex add_complex(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
};

int main()
{
    struct complex c1 = {1,2}, c2, c3;
    struct complex x = make_complex(10, 20);
    printf("Member of x: %.2f %.2f\n", x.real, x.imaginary);
    struct complex b = add_complex(c1, x);
    printf("Member of b: %.2f %.2f\n", b.real, b.imaginary);
    return 0;
}
