#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Enter the file name: ");
    char s[20];
    int ch;
    int counter=0;
    while((ch=getchar())!='\n') {
        if (counter < 20)
            s[counter++] = ch;
    }
    s[counter] = '\0';

    FILE *fp;
    if ((fp=fopen(s, "rb")) == NULL) {
        fprintf(stderr, "Cannot open the file %s\n", s);
        exit(EXIT_FAILURE);
    }
    int sentence_count = 0;
    while((ch = fgetc(fp)) != EOF) {
        if (strchr(".?!", ch)) {
            ch = fgetc(fp);
            if (isspace(ch))
                sentence_count += 1;
            else
                ungetc(ch, fp);
        }
    }
    printf("Number of sentences: %d\n", sentence_count);
    fclose(fp);

    return 0;
}
