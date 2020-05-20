#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
    int numerator;
    int denominator;
} Fraction;

int gcd(int m, int n) {
    while (n != 0) {
        int re = m % n;
        m = n;
        n = re;
    }
    return m;
}

Fraction reduce_fraction(struct fraction f) {
    int g = gcd(f.numerator, f.denominator);
    f.numerator = f.numerator / g;
    f.denominator = f.denominator / g;
    return f;
}

Fraction add_fraction(Fraction f1, Fraction f2) {
    int new_numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int new_denominator = f1.denominator * f2.denominator;
    Fraction f = reduce_fraction((Fraction) {new_numerator, new_denominator});
    return f;
}

Fraction subtract_fraction(Fraction f1, Fraction f2) {
    int new_numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    int new_denominator = f1.denominator * f2.denominator;
    Fraction f = reduce_fraction((Fraction) {new_numerator, new_denominator});
    return f;
}

Fraction multiply_fraction(Fraction f1, Fraction f2) {
    int new_numerator = f1.numerator * f2.numerator;
    int new_denominator = f1.denominator * f2.denominator;
    Fraction f = reduce_fraction((Fraction) {new_numerator, new_denominator});
    return f;
}

Fraction divide_fraction(Fraction f1, Fraction f2) {
    int new_numerator = f1.numerator * f2.denominator;
    int new_denominator = f1.denominator * f2.numerator;
    Fraction f = reduce_fraction((Fraction) {new_numerator, new_denominator});
    return f;
}

int main()
{
    Fraction a = {5, 15};
    Fraction b = {14,9};
    Fraction x = reduce_fraction(a);
    printf("Fraction a after reduced: %d/%d\n", x.numerator, x.denominator);
    Fraction c = add_fraction(a,b);
    printf("Sum of %d/%d and %d/%d: %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, c.numerator, c.denominator);
    Fraction d = subtract_fraction(a,b);
    printf("Subtract of %d/%d by %d/%d: %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, d.numerator, d.denominator);
    Fraction e = multiply_fraction(a,b);
    printf("Multiply of %d/%d and %d/%d: %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, e.numerator, e.denominator);
    Fraction f = divide_fraction(a,b);
    printf("Divide of %d/%d by %d/%d: %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, f.numerator, f.denominator);
    return 0;
}
