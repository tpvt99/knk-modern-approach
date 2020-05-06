#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define N 26

int read_line(char [], int);
bool are_anagrams(const char *, const char *);

int main()
{
    char word1[N], word2[N];
    printf("Enter first word: ");
    read_line(word1, N);
    printf("Enter second word: ");
    read_line(word2, N);
    bool is_anagram = are_anagrams(word1, word2);
    if (is_anagram)
        printf("The words are anagrams\n");
    else
        printf("The words are not anagrams\n");

    return 0;
}

int read_line(char str[], int n) {
    int i = 0;
    char ch;
    while((ch=getchar())!='\n' && ch != ' ') {
        if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

bool are_anagrams(const char *word1, const char *word2) {
    int a[N] = {0};
    char ch;
    while (*word1) {
        if (isalpha(*word1)) {
            ch = tolower(*word1);
            a[ch-'a'] += 1;
        }
        word1++;
    }
    while (*word2) {
        if (isalpha(*word2)) {
            ch = tolower(*word2);
            a[ch-'a'] -= 1;
        }
        word2++;
    }
    int *ptr = a;
    for (;ptr<a+N;)
        if (*ptr++ != 0)
            break;
    if (ptr == a+N) // This is not break;
        return true;
    else
        return false;
}
