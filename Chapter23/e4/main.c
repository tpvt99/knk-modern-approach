#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void isIdentifier(char *s, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0 && (!(s[i] == '_')) && (!(isalpha(s[i])))) {
            printf("First character contains letters which are not _ or letters.\n");
            return;
        } else if (i > 0 && (!isalnum(s[i]))) {
            printf("On-ward second characters contains non-letters.\n");
            return;
        }
    }
    printf("Valid identifier.\n");
}

int main()
{
    isIdentifier("Hello world!\n", 13);
    isIdentifier("_Helloorld", 10);
    isIdentifier("$Helloorld", 10);

    return 0;
}
