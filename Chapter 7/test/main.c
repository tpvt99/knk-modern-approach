#include <stdio.h>

int main(void) {

    typedef char Int8;
    typedef short Int16;
    typedef int Int32;

    printf("%d\n", sizeof(Int8));
    printf("%d\n", sizeof(Int16));
    printf("%d\n", sizeof(Int32));
    return 0;

}
