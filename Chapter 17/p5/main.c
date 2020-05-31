#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_WORDS 20

int read_line(char str[], int length);
void sort_mess(char **mess, int n);

int main()
{
    char *words[MAX_WORDS];
    char mess[MAX_LENGTH+1];
    int num_mes = 0;
    for(;num_mes < MAX_WORDS; num_mes++) {
        printf("Enter word: ");
        read_line(mess, MAX_LENGTH);

        if (strlen(mess) == 0)
        break;

        words[num_mes] = malloc(strlen(mess)+1);
        strcpy(words[num_mes], mess);

    }
    sort_mess(words, num_mes); // same as sort_mess(&words[0], num_mes);
    printf("In sorted order: ");
    for (int i = 0; i<num_mes;i++)
        printf("%s ", words[i]);
    return 0;
}

void sort_mess(char **mess, int n) { // selection sort
    for (char **p1 = mess; p1 < mess + n-1; p1++) {
        char *min_mess = *p1;
        for (char **p2 = p1+1; p2 < mess + n; p2++) {
            int cmp = strcmp(min_mess, *p2);
            if (cmp > 0)
                min_mess = *p2;
        }
        char temp[MAX_LENGTH+1];
        strcpy(temp, *p1);
        strcpy(*p1, min_mess);
        strcpy(min_mess, temp);
    }
}

int read_line(char str[], int length) {
    int ch, i = 0;
    while((ch = getchar())!='\n') {
        if (i < length)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
