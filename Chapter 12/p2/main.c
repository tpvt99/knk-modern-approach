#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool check_palindrome_a(char a[], int n);
bool check_palindrome_b(char *a, int n);

int main()
{
    printf("Enter a message: ");
    char a[100];
    char ch;
    int counter = 0;
    while ((ch=getchar()) != '\n') {
        a[counter] = tolower(ch);
        counter += 1;
    }
    if (check_palindrome_b(a, counter))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}

bool check_palindrome_a(char a[], int n) {
    int first = 0;
    int last = n-1;
    char first_char, last_char;
    while(first <= last) {
        first_char = a[first];
        last_char = a[last];

        if (first_char <'a' || first_char >= 'z') {
            first+=1;
            continue;
        }
        if (last_char <'a' || last_char >= 'z') {
            last-=1;
            continue;
        }
        if (first_char == last_char) {
            first+=1;
            last-=1;
        } else
            return false;
    }
    return true;
}

bool check_palindrome_b(char *a, int n) {
    char *first = a;
    char *last = a+n-1;
    while(first <= last) {
        if (*first <'a' || *first >= 'z') {
            first+=1;
            continue;
        }
        if (*last <'a' || *last >= 'z') {
            last-=1;
            continue;
        }
        printf("First char: %c.  Last char: %c\n", *first, *last);
        if (*first == *last) {
            first+=1;
            last-=1;
        } else
            return false;
    }
    return true;
}
