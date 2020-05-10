#include <stdio.h>
#include <stdlib.h>

#define stringify1(x) #x
#define stringify(x) stringify1(x)

#define LINE_FILE "Line " stringify(__LINE__) " of file " __FILE__


int main()
{
    const char *str = LINE_FILE;
    printf("%s", str);
    return 0;
}
