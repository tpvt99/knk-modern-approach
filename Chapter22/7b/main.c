#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: uncompress file\n");
        exit(EXIT_FAILURE);
    }

    int length_file = strlen(argv[1]);
    if ((argv[1][length_file-1] != 'e') || (argv[1][length_file-2] != 'l') || (argv[1][length_file-3] != 'r')){
        fprintf(stderr, "file name does not end .rle\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s file cannot open\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *dest;
    char dest_file_name[strlen(argv[1])];
    strncpy(dest_file_name, argv[1], length_file-4);
    dest_file_name[strlen(argv[1])-4]='\0';

    if ((dest = fopen(dest_file_name, "wb")) == NULL) {
        fprintf(stderr, "%s file cannot open\n", dest_file_name);
        exit(EXIT_FAILURE);
    }

    int count ,ch;

    while ((count = fgetc(fp)) != EOF) {
        if ((ch = fgetc(fp)) == EOF)
            break;
        for (int i = 0; i < count; i++)
            fputc(ch, dest);
    }
    fclose(fp);
    fclose(dest);

    return 0;
}
