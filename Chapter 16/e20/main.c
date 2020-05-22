#include <stdio.h>
#include <stdlib.h>

enum {NORTH, SOUTH, EAST, WEST} direction;

int main()
{
    int x = 10, y = 20;
    direction = NORTH;
    switch(direction) {
        case NORTH: y-= 1;break;
        case SOUTH: y+= 1;break;
        case EAST: x+= 1;break;
        case WEST: x-= 1;break;
        default: break;
    }
    printf("x: %d, y:%d\n", x, y);
    return 0;
}
