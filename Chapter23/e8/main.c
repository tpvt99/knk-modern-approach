#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numchar(const char *s, char ch) {
    int count = 0;
    char *p;
    while((p=strchr(s, ch)) != NULL) {
        count += 1;
        s = p+1;
    }
    return count;
}

int main()
{
    printf("c appears %d times\n", numchar("ilikeyoucc haha c", 'c'));
    return 0;
}
