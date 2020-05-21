#include <stdio.h>
#include <stdlib.h>

#define RECTANGLE 1
#define CIRCLE 2

struct point {
    int x;
    int y;
};

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

int main()
{
    s.shape_kind = RECTANGLE;
    s.center.x = 10;
    s.u.rectangle.height = 100;
    s.u.rectangle.width = 20;
    s.u.circle.radius = 4;
    return 0;
}
