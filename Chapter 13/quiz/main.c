#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *ptr = "ilike it";
    printf("%c", ++*ptr);
    return 0;
}
