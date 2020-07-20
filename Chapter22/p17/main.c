#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: main.c input\n");
        exit(EXIT_FAILURE);
    }

    FILE *src;

    if ((src = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    char ch, c[10];
    while((ch=fgetc(src)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            if (counter < 10)
                c[counter++] = ch;
            else {
                fprintf(stderr, "Each line might contain more than 10 digits. Discard the exceeding numbers\n");
            }
        } else if (ch == '\n') {
            counter = 0;
            printf("(%c%c%c) %c%c%c-%c%c%c%c\n", c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9]);
        }

    }
    fclose(src);
    return 0;
}
