#include <stdio.h>
#include <stdlib.h>

void remove_filename(char *url) {
    char *p = url;
    char *t;
    while (*p) {
        if (*p == '/') // assume it must has at least 1 /
            t = p;
        p++;
    }
    *t = '\0';
}

int main()
{
    char url[100]="https://knking.com/index.html";
    remove_filename(url);
    printf("%s", url);
    return 0;
}
