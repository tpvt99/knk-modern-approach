#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("Enter message: ");
    char sentences[100];
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
        sentences[i++] = c;
    sentences[i] = '\n';

    printf("In B1FF-speak: ");

    for (i = 0; i < 100; i++) {
        if (sentences[i] != '\n') {
            c = toupper(sentences[i]);
            switch(c) {
                case 'A': printf("4");break;
                case 'B': printf("8");break;
                case 'E': printf("3");break;
                case 'I': printf("1");break;
                case 'O': printf("0");break;
                case 'S': printf("5");break;
                default: printf("%c", c);
            }
        } else
            break;
    }
    printf("!!!!!!!!!!");

    return 0;
}
