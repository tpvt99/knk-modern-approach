#include <stdio.h>
#include <stdlib.h>


struct part {
    int number;
    char *name;
};

int compare_parts(const void *p, const void *q) {
    if (((struct part *)p)->number < ((struct part *)q)->number)
        return 1;
    else if (((struct part *)p)->number == ((struct part *)q)->number)
        return 0;
    else
        return -1;
}

int main()
{
    struct part inventories[4] = {{12, "haha"},{13, "love"}, {1, "just me"}, {100, "haha"}};
    qsort(inventories, 4, sizeof(struct part), compare_parts);
    printf("Number Name\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\t%s\n", inventories[i].number, inventories[i].name);
    }
    return 0;
}
