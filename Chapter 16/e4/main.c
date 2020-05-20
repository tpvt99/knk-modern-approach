#include <stdio.h>
#include <stdlib.h>

typedef struct complex{
    double real;
    double imaginary;
} Complex;

Complex make_complex(double real, double imaginary) {
    Complex c = {.real = real, .imaginary = imaginary};
    return c;
};

Complex add_complex(struct complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
};

int main()
{
    Complex c1 = {1,2}, c2, c3;
    Complex x = make_complex(10, 20);
    printf("Member of x: %.2f %.2f\n", x.real, x.imaginary);
    Complex b = add_complex(c1, x);
    printf("Member of b: %.2f %.2f\n", b.real, b.imaginary);
    struct complex c = b ;
    printf("Member of c: %.2f %.2f\n", c.real, c.imaginary);
    return 0;
}
