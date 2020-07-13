#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: main.c input output\n");
        exit(EXIT_FAILURE);
    }

    FILE *src, *dest;

    if ((src = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest = fopen(argv[2], "ww")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    unsigned char *a = malloc(sizeof(unsigned char) * 512);
    while (fread(a, 512, 1, src) == 1) {
        fwrite(a, 512, 1, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}
