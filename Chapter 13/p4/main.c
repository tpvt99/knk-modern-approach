#include <stdio.h>
#include <stdlib.h>

int main(int argc, char  *argv[])
{
    char **p;
    for (p = &argv[argc-1]; p>= &argv[1]; p--)
        printf("%s ", *p);
    return 0;
}
