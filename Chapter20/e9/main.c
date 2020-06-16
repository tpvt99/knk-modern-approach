#include <stdio.h>
#include <stdlib.h>

int count_ones(unsigned char ch) {
    if (ch == 0)
        return 0;
    return (ch & 0x1) + count_ones(ch >> 1);

}

int main()
{
    printf("Ones' times are: %d\n", count_ones(0b10101111));
    return 0;
}
