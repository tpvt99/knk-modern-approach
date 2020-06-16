#include <stdio.h>
#include <stdlib.h>

#define MK_COLOR(r, g, b) ( ((long) (b) << 16) | ( (g) << 8) | (r))

int main()
{

    int r = 10, g = 7, b = 25;
    long result = MK_COLOR(r, g, b);
    int new_r = (result) & 0x00ff;
    int new_g = (result >> 8) & 0x00ff;
    int new_b = (result >> 16) & 0x00ff;
    printf("r: %d, g: %d, b: %d\n", new_r, new_g, new_b);
    return 0;
}
