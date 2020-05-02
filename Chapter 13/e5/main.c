#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void capitalize(char *);

int main()
{
    char p[100] = "i like this so much.";
    char *str = "Just like me";
    str = p;
    capitalize(p);
    printf(str);
    return 0;
}

void capitalize(char *str) {
    char *slow = str;
    str++;
    if ((tolower(*slow) >= 'a' && tolower(*slow) <= 'z')) // Handle first character
        *slow = toupper(*slow);

    for (;*str!='\0';str++) {
        if ((*slow == ' ') && (tolower(*str) >= 'a' && tolower(*str) <= 'z'))
            *str = toupper(*str);
        slow = str;
    }
}
