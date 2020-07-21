#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    if (argc != 2) {
        fprintf(stderr, "usage: main.c file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "cannot open the file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch;
    int new_line = 1;
    while(1) {
        ch = fgetc(fp);
        if (ch == '\n') {
            if (new_line==0)
                fputc(ch, stdout);
            new_line = 1;
            continue;
        }
        if (ch == EOF)
            break;
        if (new_line) {
            if (strchr(" \t", ch) == NULL) {
                new_line = 0;
                fputc(ch, stdout);
            }
        } else {
            fputc(ch, stdout);
        }
    }
    fclose(fp);
    return 0;
}
