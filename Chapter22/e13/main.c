#include <stdio.h>
#include <stdlib.h>

int line_length(const char *file_name, int n);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: main file_name\n");
        exit(EXIT_FAILURE);
    }
    int n;
    printf("Enter line to count the length: ");
    scanf("%d", &n);
    fprintf(stdout, "Line length: %d\n", line_length(argv[1], n));
    return 0;
}

int line_length(const char *file_name, int n) {
    FILE *fp;
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Can't open the file: %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    int counter = 1;
    int ch;

    while ((ch = getc(fp)) != EOF && counter < n) {
        if (ch == '\n')
            counter += 1;
    }
    ungetc(ch, fp);
    int num_chars = 0;
    if (counter == n) {
        fprintf(stdout, "Line:");
        while ((ch=getc(fp))!= '\n' && ch != EOF) {
            num_chars++;
            fprintf(stdout, "%c-%d\\", ch, ch);
        }
        fprintf(stdout, "|\n");
    }

    return num_chars;
}
