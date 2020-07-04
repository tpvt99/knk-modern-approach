#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char BYTE;

#define OFFSET 10


int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: main file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s file cannot open\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    int ch, j;
    for (int i = 0;;i+=OFFSET) {
        printf("%6d ", i);
        int is_end = 0;

        for (j = 0; j < OFFSET; j++) {
            ch = fgetc(fp);
            if (ch != EOF) {
                printf(" %02X", ch);
            } else {
                break;
            }
        }

        for (int t= j;t<OFFSET;t++) // print space if not take the whole 10 bytes
            printf("   ");

        fseek(fp, -(long) j, SEEK_CUR);
        printf("  ");
        for (j = 0; j < OFFSET; j++) {
            ch = fgetc(fp);
            if (ch != EOF) {
                if (isprint(ch))
                    printf("%c", ch);
                else
                    printf(".");
            } else if (ch == EOF) {
                is_end = 1;
                break;
            }
        }

        if (is_end == 1)
            break;
        printf("\n");
    }
    fclose(fp);
    printf("\n");

    return 0;
}
