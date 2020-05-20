#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point {
    int x, y;
};

struct rectangle{
    struct point upper_left, lower_right;
};

int area(struct rectangle rec) {
    int side1 = rec.lower_right.x - rec.upper_left.x;
    int side2 = rec.upper_left.y - rec.lower_right.y;
    return side1 * side2;
}

struct point center(struct rectangle rec) {
    int x = (rec.lower_right.x - rec.upper_left.x)/2;
    int y = (rec.upper_left.y + rec.lower_right.y)/2;
    return ((struct point) {x=x, y=y});
}

struct rectangle move_r(int x, int y, struct rectangle r) {
    r.upper_left.x += x;
    r.lower_right.x += x;
    r.upper_left.y += y;
    r.lower_right.y += y;
    return r;
};

bool lie_inside(struct rectangle rec, struct point p) {
    if (rec.upper_left.x <= p.x && p.x <= rec.lower_right.x && rec.lower_right.y <= p.y && p.y <= rec.upper_left.y)
        return true;
    return false;
}


int main()
{
    struct point x = {1, 5};
    struct point y = {10, 1};
    struct rectangle rec = {x, y};
    printf("Area: %d\n", area(rec));
    struct point c = center(rec);
    printf("Center point: x:%d, y:%d\n", c.x, c.y);
    struct rectangle rec_move = move_r(5, 7, rec);
    printf("New upper left: %d %d, New lower right: %d %d", rec_move.upper_left.x, rec_move.upper_left.y, rec_move.lower_right.x, rec_move.lower_right.y);
    struct point p1 = {2, 19};
    printf("Point p1 inside rec: %d\n", lie_inside(rec, p1));
    struct point p2 = {2, 4};
    printf("Point p2 inside rec: %d", lie_inside(rec, p2));
    return 0;
}
