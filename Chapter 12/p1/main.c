#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a message: ");
    char ch, a[100];
    char *ptr = a;
    while ((ch=getchar())!= '\n') {
        if (ch == '\n')
            break;
        *(ptr++) = ch;
    }
    printf("Reversal is: ");
    while(ptr>a)
        printf("%c", *(--ptr));
    return 0;
}
