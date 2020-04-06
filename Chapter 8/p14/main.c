#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
    printf("Enter a sentence: ");
    char sentences[N];
    char ch;
    int i = 0;
    for (i = 0; i < N; i++) {
        ch = getchar();
        sentences[i] = ch;
        if (ch == '?' || ch == '.' || ch == '!')
            break;
    }
    getchar(); // Get the new-line character
    char terminate_char = sentences[i];
    int index_be, index_en, index = i-1;
    printf("Reversal of sentence: ");
    while (index>=0) {
        index_en = index;
        while (sentences[index] != ' ') {
            if (index==0) {
                index--;
                break;
            }
            index--;
        }
        index_be = index+1;
        for (int j = index_be; j <= index_en; j++)
            printf("%c", sentences[j]);
        if (index_be != 0)
            printf(" ");
        index--;
    }
    printf("%c\n", terminate_char);

    return 0;
}
