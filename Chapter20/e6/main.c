#include <stdio.h>
#include <stdlib.h>

unsigned short swap_bites(unsigned short i) {
    return (i << 8) | (i >> 8);
}

int main()
{
    unsigned short i;
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &i);
    printf("Number with bytes swapped: %hx", swap_bites(i));
    return 0;
}
