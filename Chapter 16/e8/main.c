#include <stdio.h>
#include <stdlib.h>

struct color {
    int red;
    int green;
    int blue;
};

int main()
{
    const struct color MAGNETA = {.red = 255, .blue = 255};
    return 0;
}
