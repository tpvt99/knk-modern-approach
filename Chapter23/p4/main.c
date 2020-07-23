#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_WORD 50

int main()
{
    printf("Enter a sentence: ");
    int ch;
    char s[MAX_LENGTH+1];
    char *words[MAX_WORD];
    int counter = 0;
    while((ch=getchar())!='\n') {
        if (counter < MAX_LENGTH)
            s[counter++] = ch;
    }

    char *p;
    p = strtok(s, " \t");
    counter = 0;
    while(p!=NULL) {
        if (counter < MAX_WORD) {
            words[counter] = malloc(sizeof(char) * (strlen(p)+1));
            strcpy(words[counter++], p);
            p = strtok(NULL, " \t");
        }
    }
    printf("Reversed sentence is: ");
    for (int i = counter-1; i>= 0; i--) {
        printf("%s ", words[i]);
    }
    return 0;
}
