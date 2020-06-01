#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main()
{
    char word[MAX_WORD_LEN+2];
    int word_len;
    clear_line();
    for (;;) {
        print_line();
        read_word(word, MAX_WORD_LEN+1);
        puts(word);
        puts("Top 1");
        word_len = strlen(word);
        puts("Top 1");
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';

        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
        print_line();
    }
}
