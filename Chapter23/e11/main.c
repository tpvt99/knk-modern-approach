#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[] = "i just like it much";
    int n = 3;
    memset(s+strlen(s)-n, '!', n);
    printf("String: %s\n", s);
    return 0;
}
