#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main()
{
    char s[50], d[50];
    strcpy(s, "abcd");
    strcpy(d, "0123");
    int i =0;
    putchar(TOUPPER(s[++i]));
    i = 0;
    putchar(TOUPPER(d[++i]));
    return 0;
}
