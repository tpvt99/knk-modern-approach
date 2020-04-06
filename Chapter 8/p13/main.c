#include <stdio.h>
#include <stdlib.h>

#define N 20
int main()
{
    char lastNames[N];
    char ch, firstName;
    printf("Enter a first and last name: ");
    while ((ch = getchar()) == ' ') // First non-space character is first name
        ;
    firstName = ch;
    while ((ch = getchar()) != ' ') // End loop if there is a space and ch is equal to that space
        ;
    while ((ch = getchar()) == ' ') // Remove spaces, first character is last name
        ;
    lastNames[0] = ch;
    for (int i = 1; i< N; i++){
        ch = getchar();
        lastNames[i] = ch;
        if ((ch == ' ') || (ch == '\n'))
            break;
    }
    printf("You entered the name: ");
    for (int i = 0; i<N; i++) {
        if ((lastNames[i] != '\n') && (lastNames[i] != ' '))
            printf("%c", lastNames[i]);
        else
            break;
    }
    printf(", %c.\n", firstName);

    return 0;
}
