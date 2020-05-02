#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[] = "Hsjodi", *p;
    for (p=s; *p; p++)
        --*p;
    puts(s);
    return 0;
}
