#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bits(unsigned int n) {
    unsigned int new_n = 0;
    while (n != 0) {
        int m = n & 0x1;
        new_n = new_n | m;
        n >>= 1;
        if (n != 0)
            new_n <<= 1;
    }
    return new_n;
}

int main()
{
    printf("Reversed bits: %d\n", reverse_bits(0b100101));
    return 0;
}
