#include <stdio.h>
#include <stdlib.h>

struct float_type {
    unsigned int sign: 1;
    unsigned int exponent: 8;
    unsigned int fraction: 23;
};

int main()
{
    struct float_type x = {.sign = 1, .exponent = 3, .fraction = 10};
    printf("sign: %d, ex: %d, frac: %d\n", x.sign, x.exponent, x.fraction);
    return 0;
}
