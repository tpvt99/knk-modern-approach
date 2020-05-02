#include <stdio.h>
#include <stdlib.h>

int strcmp(char *s, char *t);

int main()
{
    printf("%d", strcmp("acdsds", "acd"));
    return 0;
}

int strcmp(char *s, char *t) {
    for (;*s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}
