#include <stdio.h>
#include <stdlib.h>

int count_spaces(const char s[]) {
    int count = 0;
    char *p = s;

    while(*p)
        if (*(p++) == ' ')
            count+=1;

    return count;
}

int main()
{
    printf("%d", count_spaces("Hello world!\n"));
    return 0;
}
