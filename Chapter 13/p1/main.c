#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char smallest_words[20], largest_words[20];
    char enter_words[20];
    printf("Enter word: ");
    scanf("%s", enter_words);
    strcpy(smallest_words, enter_words);
    strcpy(largest_words, enter_words);

    while (1) {
        printf("Enter word: ");
        scanf("%s", enter_words);
        if (strlen(enter_words) == 4)
            break;
        if (strcmp(enter_words, smallest_words) <= 0)
            strcpy(smallest_words, enter_words);
        else if (strcmp(enter_words, largest_words) >= 0)
            strcpy(largest_words, enter_words);
    }
    printf("Smallest word: %s\n", smallest_words);
    printf("Largest word: %s\n", largest_words);
    return 0;
}
