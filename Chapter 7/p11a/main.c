#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a first and last name: ");
    char ch;
    scanf(" %c", &ch);
    char fname = ch;
    while(ch != ' ') {
        scanf("%c", &ch);
    }
    scanf(" %c", &ch);
    while ((ch != ' ') && (ch != '\n')) {
        printf("%c", ch);
        scanf("%c", &ch);
    }
    printf(", %c\n", fname);
    return 0;
}
