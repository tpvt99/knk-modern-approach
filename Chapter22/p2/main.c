#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2) {
        printf("usage: main file\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        ch = toupper(ch);
        fprintf(stdout, "%c", ch);
    }

    fclose(fp);

    return 0;
}
