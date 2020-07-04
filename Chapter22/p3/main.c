#include <stdio.h>
#include <stdlib.h>

void fcat(FILE *fp);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: fcat [files]\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp;
    for (int i = 1;i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "cannot open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        fcat(fp);
        fclose(fp);
    }
    return 0;
}

void fcat(FILE *fp) {
    int ch;
    while((ch = fgetc(fp)) != EOF)
        fputc(ch, stdout);
}
