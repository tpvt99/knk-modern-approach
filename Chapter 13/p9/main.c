#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_line(char str[], int n);

int compute_vowel_count(const char *sentence) {
    char ch;
    int vowels = 0;
    while (*sentence) {
        ch = tolower(*sentence++);
        switch(ch) {
            case 'a': case 'e': case 'i' : case 'o': case 'u': vowels += 1;break;
            default:;
        }
    }
    return vowels;
}

int main()
{
    char str[100];
    printf("Enter a sentence: ");
    read_line(str, 100);
    int vowel = compute_vowel_count(str);
    printf("Number of vowels: %d", vowel);
    return 0;
}

int read_line(char str[], int n) {
    char ch;
    int i = 0;
    while ((ch = getchar())!='\n') {
        if (i<n)
            str[i] = ch;
        i++;
    }
    str[i] = '\0';
    return i;
}
