#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: compress file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s file cannot open\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *dest;
    char dest_file_name[strlen(argv[1]) + 5];
    strcat(strcpy(dest_file_name, argv[1]), ".rle");

    if ((dest = fopen(dest_file_name, "wb")) == NULL) {
        fprintf(stderr, "%s file cannot open\n", dest_file_name);
        exit(EXIT_FAILURE);
    }

    int ch, count, base_ch;
    count = 1;
    base_ch = fgetc(fp);
    if (base_ch == EOF) {
        fclose(fp);
        fclose(dest);
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == base_ch)
            count+=1;
        else {
            fputc(count, dest);
            fputc(base_ch, dest);
            count = 1;
            base_ch = ch;
        }
    }
    fputc(count, dest);
    fputc(base_ch, dest);
    fclose(fp);
    fclose(dest);


    return 0;
}
