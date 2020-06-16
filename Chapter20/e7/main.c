#include <stdio.h>
#include <stdlib.h>

unsigned int rotate_left(unsigned int i, int n) {
    return (i<< n) | (i >> (sizeof(unsigned int)*8 - n));
}

unsigned int rotate_right(unsigned int i, int n) {
    return (i >> n) | (i << (sizeof(unsigned int)*8 - n));
}

int main()
{
    printf("Enter a hexadecimal number (up to 8 digits): ");
    unsigned int i;
    scanf("%x", &i);
    printf("Number with bytes rotate_left: %x\n", rotate_left(i, 8));
    printf("Number with bytes rotate_right: %x\n", rotate_right(i, 8));
    return 0;
}
