#include <stdio.h>
#include <stdlib.h>

void censor(char *str);

int main()
{
    char str[100] = "food fool fike five f";
    censor(str);
    printf(str);
    return 0;
}

void censor(char *str) {
    for(;*str!='\0';) {
        if (*str == 'f') {
            if (*(str+1) != '\0' && *(str+2)!='\0' && *(str+1) == 'o' && *(str+2) == 'o') {
                *str = 'x';
                *(str+1) = 'x';
                *(str+2) = 'x';
                str+=3;
                continue;
            }
        }
        str+=1;
    }
}
