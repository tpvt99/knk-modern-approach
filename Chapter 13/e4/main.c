#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_line(char str[], int n);

int main()
{
    char str[10], str2[100];
    printf("Enter a sentence: ");
    read_line(str, 10);
    read_line(str2, 100);
    printf("%s", str);
    printf("%s", str2);
    return 0;
}

int read_line(char str[], int n) {
    int ch, i=0;
    scanf(" %c", &str[i++]); // part a
    while (((ch = getchar()) != '\n') && (!isspace(ch))) // part b
        if (i<(n-1))
            str[i++] = ch;
        else // part d
            break;
    str[i++] = '\n'; // part c
    str[i] = '\0';
    return i;
}
