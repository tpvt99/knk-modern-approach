#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_WORDS 20

int read_line(char str[], int length);
int compare_func(const void *p, const void *q);

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
    qsort(words, num_mes, sizeof(char *), compare_func);
    printf("In sorted order: ");
    for (int i = 0; i<num_mes;i++)
        printf("%s ", words[i]);
    return 0;
}

int compare_func(const void *p, const void *q) {
    const char *a = *(char **) p;
    const char *b = *(char **) q;
    int cmp = strcmp(a,b);
    if (cmp > 0)
        return 1;
    else if (cmp < 0)
        return -1;
    else
        return 0;
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
