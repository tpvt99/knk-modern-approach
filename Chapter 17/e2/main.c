#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * duplicate(char *str) {
    char *p = malloc(strlen(str)+1);
    if (p == NULL) {
        return NULL;
    }
    strcpy(p, str);
    return p;

}

int main()
{
    char *str = "love";
    char *p = duplicate(str);
    printf("%s", p);
    return 0;
}
