#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a first and last name: ");
    char ch;
    while ((ch = getchar()) == ' ')
        ;
    // First name
    char fname = ch;
    while ((ch = getchar()) != ' ')
        ;

    while ((ch = getchar()) == ' ')
        ;

    printf("%c", ch);
    while (((ch = getchar()) != ' ') && (ch != '\n'))
        printf("%c", ch);

    printf(", %c", fname);
    return 0;
}
