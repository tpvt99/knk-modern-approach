#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int read_line(int n, char str[n]);
bool is_palindrome(const char *message);


int main()
{
    char str[200];
    printf("Enter a message: ");
    read_line(200, str);
    bool is = is_palindrome(str);
    if (is)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}

bool is_palindrome(const char *message) {
    const char *ptr_end = message;
    const char *ptr_beg = message;
    while(*(ptr_end++))
        ;
    ptr_end-=2;
    while(ptr_beg <= ptr_end) {
        if (*ptr_beg <'a' || *ptr_beg >= 'z') {
            ptr_beg++;
            continue;
        }
        if (*ptr_end <'a' || *ptr_end >= 'z') {
            ptr_end--;
            continue;
        }
        printf("First char: %c.  Last char: %c\n", *ptr_beg, *ptr_beg);
        if (*ptr_beg == *ptr_end) {
            ptr_beg+=1;
            ptr_end-=1;
        } else
            return false;
    }
    return true;
}

int read_line(int n, char str[n]) {
    char ch;
    int i=0;
    while((ch=getchar())!='\n') {
        if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
