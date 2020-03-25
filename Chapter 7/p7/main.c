#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter two fractions: ");
    int a, b;
    char c;
    int d, e;
    scanf("%d /%d %c%d/%d", &a, &b, &c, &d, &e);
    printf("a: %d, b:%d, c:%c, d:%d, e:%d\n", a, b, c, d, e);
    int nom, denom;
    if (c == '+') {
        nom = a * e + d * b;
        denom = b * e;
    } else if (c == '-') {
        nom = a * e - d * b;
        denom = b * e;
    } else if (c == '*') {
        nom = a * d;
        denom = b * e;
    } else if (c == '/') {
        nom = a * e;
        denom = b * d;
    }
    printf("The result is: %d/%d\n", nom, denom);
    return 0;
}
