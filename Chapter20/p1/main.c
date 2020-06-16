#include <stdio.h>
#include <stdlib.h>

union float_type {
    float number;
    struct {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } elements;
};


int main()
{
    union float_type x;
    printf("%d\n", sizeof(union float_type));
    x.elements.sign = 1;
    x.elements.exponent = 128;
    x.elements.fraction = 0;
    unsigned char *ptr = (unsigned char *) &(x.elements);
    printf("%.2x %.2x %.2x %.2x\n", *( ptr), *(ptr+1), *(ptr+2), *(ptr+3) );
    printf("Floating point number: %f\n", x.number);
    return 0;
}
