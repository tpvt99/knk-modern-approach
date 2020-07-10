#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: main.c input output\n");
        exit(EXIT_FAILURE);
    }

    FILE *src, *dest;

    if ((src = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1, src);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line(dest);
            return 0;
        }

        if (word_len + 1 > space_remaining()) {
            write_line(dest);
            clear_line();
        }
        add_word(word);
    }

    return 0;
}
