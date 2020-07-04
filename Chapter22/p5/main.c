#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: xor input output\n");
        exit(EXIT_FAILURE);
    }

    FILE *source, *dest;

    if ((source = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int ch, new_char;
    while((ch = fgetc(source)) != EOF) {
        new_char = ch ^ KEY;
        if ((fputc(new_char, dest)) == EOF) {
            fprintf(stderr, "Cannot write to file %s", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    fclose(source);
    fclose(dest);

    return 0;
}
