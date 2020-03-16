#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 0; i<= 10; i++) {
        if (i == 5) {
            goto AHIHI;
        } else {
            printf("%d\n", i);
        }
        AHIHI: ; // null statement
    }

    return 0;
}
