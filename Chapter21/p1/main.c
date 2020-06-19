#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct s{
    char a;
    int b[2];
    float c;
};

int main()
{
    printf("Offset s vs a: %d\n", offsetof(struct s, a));
    printf("Offset s vs b: %d\n", offsetof(struct s, b));
    printf("Offset s vs c: %d\n", offsetof(struct s, c));
    return 0;
}
