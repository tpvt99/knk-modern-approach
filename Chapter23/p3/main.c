#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int ch;
    int is_word = 0;
    while((ch = getchar()) != EOF) {

        if (isspace(ch)) {
            is_word = 0;
        }
        if (is_word == 0 && !isspace(ch)) {
            ch = toupper(ch);
            is_word = 1;
        }

        putchar(ch);
    }
    return 0;
}
