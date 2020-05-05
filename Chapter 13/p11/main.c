#include <stdio.h>
#include <stdlib.h>

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main()
{
    char str[100];
    printf("Enter a sentence: ");
    read_line(str, 100);
    printf("Average word length: %.1f\n", compute_average_word_length(str));
    return 0;
}

double compute_average_word_length(const char *sentence) {
    int is_new_word = 0;
    const char *ch = sentence;
    int words = 0;
    int characters = 0;
    while (*ch) {
        if (*ch != ' ') {
            characters += 1;
            if (!is_new_word) {
                is_new_word = 1;
                words += 1;
            }
        } else if (*ch == ' ') {
            is_new_word = 0;
        }
        ch++;
    }
    return (double) characters / words;
}

int read_line(char str[], int n) {
    int i = 0;
    char ch;
    while((ch=getchar())!='\n') {
        if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
