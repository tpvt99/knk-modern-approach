#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS 30
#define CHARACTERS 20

int read_line(int, int, char  (*str)[*]);

int main()
{
    printf("Enter a sentence: ");
    char str[WORDS][CHARACTERS];
    int no_rows = read_line(WORDS, CHARACTERS, str);

    printf("Reverse sentence is:", no_rows);
    for (int i = no_rows-2; i>= 0; i--)
        printf(" %s", str+i);
    printf("%s", str+no_rows-1);
}

int read_line(int rows, int columns, char (*str)[columns]) {
    char *element = *str;
    char ch;
    int counter = 0;
    int is_writing_current_char = 0;
    while((ch=getchar())!='\n') {
        if (ch != ' ' && ch != '?' && ch != '.' && ch != '!') {
            if ((element - *str) < columns-1) {
                //printf("Saving char: %c\n", ch);
                *(element++) = ch;
            }
            is_writing_current_char = 1;
        } else if (ch == ' ') {
            if (is_writing_current_char == 1) {
                *element = '\0';
                counter += 1;
                element = *(++str);
                is_writing_current_char = 0;
            }
        } else if (ch == '?' || ch == '.' || ch == '!') {
            is_writing_current_char = 0;
            *element = '\0';
            counter += 2;
            element = *(++str);
            *(element++) = ch;
            *element = '\0';
            break;
        }
    }
    return counter;
}

