#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("Enter a sentence: ");
    char ch;
    int vowels = 0;
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        switch(ch) {
            case 'a': case 'e': case 'i' : case 'o': case 'u': vowels += 1;break;
            default:;
        }
    }
    printf("Your sentence contains %d vowels.\n", vowels);
    return 0;
}
