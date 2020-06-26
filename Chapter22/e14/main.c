#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 100

int fputs_custom(const char *restrict s, FILE * restrict stream);
char *fgets_custom(char *restrict s, int n, FILE *restrict stream);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: main.c src dest");
        exit(EXIT_FAILURE);
    }
    FILE *src, *dest;
    if ((src = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    char s[MAX_LINE];
    while(1) {
        if (fgets_custom(s, MAX_LINE+1,src) == NULL)
            break;
        if (fputs_custom(s, dest) == EOF) {
            fprintf(stderr, "Error in fputs_custom.\n");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}

char *fgets_custom(char *restrict s, int n, FILE *restrict stream) {
    if (stream == NULL) {
        fprintf(stderr, "Stream error.\n");
        return NULL;
    }
    int ch;
    int counter = 0;
    while ((ch=getc(stream)) != EOF && ch != '\n') {
        if (counter < n-1) {
            s[counter] = ch;
        }
        counter++;
    }
    if (ch == EOF)
        return NULL;
    if (counter < n-1)
        s[counter++] = '\n';
    s[counter] = '\0';
    return s;
}

int fputs_custom(const char *restrict s, FILE * restrict stream) {
    if (stream == NULL) {
        fprintf(stderr, "Stream error.\n");
        return EOF;
    }
    const char *c = s;
    int num_chars = 0;
    while(*c) {
        if (fputc((int) *c, stream) == EOF) {
            fprintf(stderr, "Output error.\n");
            return EOF;
        }
        c++;
        num_chars++;
    }
    return num_chars;
}
