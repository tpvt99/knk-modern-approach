#include <stdio.h>
#include <stdlib.h>

int main()
{
    int is_new_word = 0;
    printf("Enter a sentence: ");
    char ch;
    int words = 0;
    int characters = 0;
    while ((ch = getchar()) != '\n') {
        if (ch != ' ') {
            characters += 1;
            if (!is_new_word) {
                is_new_word = 1;
                words += 1;
            }
        } else if (ch == ' ') {
            is_new_word = 0;
        }
    }
    printf("Char: %d Word: %d\n", characters, words);
    printf("Average word length: %.1f\n", (float) characters / words);
    return 0;
}
