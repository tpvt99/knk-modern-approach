#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define N 26

void read_word(int []);
bool equal_array(int [], int []);

int main()
{
    int a[N] = {0};
    int b[N] = {0};
    printf("Enter first word: ");
    read_word(a);
    printf("Enter second word: ");
    read_word(b);

    if (equal_array(a,b)) // This is not break;
        printf("The words are anagrams\n");
    else
        printf("The words are not anagrams\n");
    return 0;
}

void read_word(int counts[N]) {
    char ch;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            counts[ch-'a'] += 1;
        }
    }
}

bool equal_array(int counts1[N], int counts2[N]) {
    int i = 0;
    for (;i<N;i++) {
        if (counts1[i] != counts2[i])
            return false;
    }
    return true;
}
