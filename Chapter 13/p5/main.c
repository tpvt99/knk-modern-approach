#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char **ptr;
    int sum=0;
    for(ptr = &argv[1]; ptr < &argv[argc];ptr++) {
        sum += atoi(*ptr);
    }
    printf("Total: %d", sum);
    return 0;
}
