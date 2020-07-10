#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    printf("Enter name of file to be encrypted: ");
    char file_name[50];
    int ch;
    int counter=0;

    while ((ch = getc(stdin)) != '\n')
        file_name[counter++] = ch;
    file_name[counter] = '\0';

    FILE *fp, *dest;

    if ((fp = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", file_name);
        exit(EXIT_FAILURE);
    }

    char new_name[strlen(file_name) + 4+1];
    strcat(strcpy(new_name, file_name), ".enc");

    if ((dest = fopen(new_name, "wb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", new_name);
        exit(EXIT_FAILURE);
    }
    int n;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);

    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            fputc((((ch - 'a') + n)%26) + 'a', dest);
        else if (ch >= 'A' && ch <= 'Z')
            fputc((((ch - 'A') + n)%26) + 'A', dest);
        else
            fputc(ch, dest);
    }
    fclose(dest);
    fclose(fp);
    return 0;
}
