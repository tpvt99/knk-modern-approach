#include <stdio.h>
#include <stdlib.h>
#define N 26
#include <ctype.h>

int main()
{
    int a[N] = {0};
    printf("Enter first word: ");
    char ch;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            a[ch-'a'] += 1;
        }
    }
    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            a[ch-'a'] -= 1;
        }
    }
    int i = 0;
    for (; i < N; i++)
        if (a[i] != 0)
            break;
    if (i == N) // This is not break;
        printf("The words are anagrams\n");
    else
        printf("The words are not anagrams\n");
    return 0;
}
