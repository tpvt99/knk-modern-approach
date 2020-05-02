#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);

int main()
{
    char domain[20] = "knking.com";
    char index_url[100];
    build_index_url(domain, index_url);
    printf("%s", index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url) {
    char c[100];
    //printf("%d", c[0]);
    //printf("%d", index_url[0]);
    strcat(c, "http://www.");
    strcat(c, domain);
    strcat(c, "/index.html");
    strcpy(index_url, c);
}
