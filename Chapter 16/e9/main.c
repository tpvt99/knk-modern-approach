#include <stdio.h>
#include <stdlib.h>

struct color {
    int red;
    int green;
    int blue;
};

typedef int bool;

int check_color(int x) {
    if (x > 255)
        return 255;
    else if (x < 0)
        return 0;
    else
        return x;
}

struct color make_color(int red, int green, int blue) {
    struct color c;
    c.red = check_color(red);
    c.green = check_color(green);
    c.blue = check_color(blue);
    return c;
};

int getRed(struct color c) {
    return c.red;
}

bool equal_color(struct color color1, struct color color2) {
    return (color1.red == color2.red) ? ((color1.green == color2.green) ? ((color1.blue == color2.blue) ? 1 : 0) : 0) : 0;
}

struct color brighter(struct color c) {
    struct color x;
    if (c.red == 0 && c.green == 0 && c.blue == 0)
        return (struct color) {3, 3, 3};
    x = c;
    if (x.blue >= 0 && x.blue <= 3)
        x.blue = 3;
    if (x.green >= 0 && x.green <= 3)
        x.green = 3;
    if (x.red >= 0 && x.red <= 3)
        x.red = 3;
    x.red /= 0.7;
    x.green /= 0.7;
    x.blue /= 0.7;
    x.red = check_color(x.red);
    x.green = check_color(x.green);
    x.blue = check_color(x.blue);
    return x;
};

struct color darker(struct color c) {
    c.red *= 0.7;
    c.green *= 0.7;
    c.blue *= 0.7;
    c.red = check_color(c.red);
    c.green = check_color(c.green);
    c.blue = check_color(c.blue);
    return c;
};

int main()
{
    struct color c = make_color(145, 903, -12);
    struct color d = make_color(145, 225, 0);
    printf("Red %d Green %d Blue %d\n", c.red, c.green, c.blue);
    printf("%d\n", equal_color(c,d));
    struct color x = brighter(c);
    printf("Red %d Green %d Blue %d\n", x.red, x.green, x.blue);
    struct color f = darker(c);
    printf("Red %d Green %d Blue %d\n", f.red, f.green, f.blue);
    return 0;
}
