#include "word.h"
#include <stdio.h>

int read_char(FILE *fp) {
    int ch = fgetc(fp);

    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len, FILE *fp) {
    int ch, pos = 0;
    while((ch=fgetc(fp)) == ' ' || (ch == '\t'))
        ;

    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++]=ch;
        ch=read_char(fp);
    }
    if (pos == len)
        word[pos-1] = '*';
    word[pos] = '\0';
}

