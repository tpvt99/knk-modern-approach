#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("Enter text: ");
    int ch;
    while((ch = getchar())!='\n') {
        if (iscntrl(ch)) {
            printf("%c", '?');
        } else {
            printf("%c", ch);
        }
    }
    return 0;
}
