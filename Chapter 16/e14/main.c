#include <stdio.h>
#include <stdlib.h>

#define RECTANGLE 1
#define CIRCLE 2
#define PI 3.1418

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

int area(struct shape s) {
    int a;
    if (s.shape_kind == RECTANGLE) {
        a = s.u.rectangle.height * s.u.rectangle.width;
    } else if (s.shape_kind == CIRCLE) {
        a = PI * s.u.circle.radius * s.u.circle.radius;
    }
    return a;
}

struct shape move(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;
    return s;
};

struct shape scale(struct shape s, double scaler) {
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height = s.u.rectangle.height * scaler;
        s.u.rectangle.width = s.u.rectangle.width * scaler;
    } else if (s.shape_kind == CIRCLE) {
        s.u.circle.radius = s.u.circle.radius * scaler;
    }
    return s;
};

int main()
{
    struct shape rec = {.shape_kind = RECTANGLE, .center = {.x = 5, .y = 5}, .u.rectangle.height = 5, .u.rectangle.width=5};
    struct shape cir = {.shape_kind = CIRCLE, .center = {.x = 5, .y = 5}, .u.circle.radius = 5};
    printf("Area of rec: %d\n", area(rec));
    printf("Area of cir: %d\n", area(cir));
    struct shape new_rec = move(rec, 3, 5);
    struct shape new_cir = move(cir, 3, 5);
    printf("Center of rec after move 3 x and 5 y: %d %d\n", new_rec.center.x, new_rec.center.y);
    printf("Center of cir after move 3 x and 5 y: %d %d\n", new_cir.center.x, new_cir.center.y);

    new_rec = scale(rec, 3.4);
    new_cir = scale(cir, 5.2);
    printf("New height: %d New width: %d\n", new_rec.u.rectangle.height, new_rec.u.rectangle.width);
    printf("New radius: %d\n", new_cir.u.circle.radius);
    return 0;
}
