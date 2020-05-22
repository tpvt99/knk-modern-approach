#include <stdio.h>
#include <stdlib.h>

enum v {
    EM,
    SS,
};

struct pinball_machine {
    char name[41];
    int year;
    enum v type;
    int players;
};

int main()
{
    printf("Hello world!\n");
    return 0;
}
