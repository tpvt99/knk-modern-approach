#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *sentence) {
    char *p;
    int count = 0;
    p = strtok(sentence, " \t");
    while (p != NULL) {
        count += 1;
        p = strtok(NULL, " \t");
    }
    return count;
}

int main()
{
    char s[] = "i like it so mucha,hihi!!! hih??? hihi";
    printf("Number of words: %d\n", count_words(s));
    return 0;
}
