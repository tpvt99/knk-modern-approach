#include <stdio.h>
#include <stdlib.h>

int count_characters(FILE *fp) {
    int ch;
    int count = 0;
    while((ch = fgetc(fp)) != EOF) {
        if (ch != '\n')
            count += 1;
    }
    return count;
}

int count_words(FILE *fp) {
    int ch;
    int count = 0;
    int in_word = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n')
            in_word = 0;
        else {
            if (in_word == 0) {
                in_word = 1;
                count += 1;
            }
        }
    }
    return  count;
}

int count_lines(FILE *fp) {
    int  ch;
    int count = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n')
            count += 1;
    }
    return count;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: count files\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("Number of characters: %d\n", count_characters(fp));
    fseek(fp, 0L, SEEK_SET);
    printf("Number of words: %d\n", count_words(fp));
    fseek(fp, 0L, SEEK_SET);
    printf("Number of lines: %d\n", count_lines(fp));
    fclose(fp);

    return 0;
}
