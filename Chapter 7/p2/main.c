#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n, counter;
    printf("Enter the number of entries in the table: ");
    scanf("%d", &n);
    getchar();
    i = 1;
    counter = 0;
    do {
        if (counter+24 < n)
            counter += 24;
        else
            counter = n;
        for(; i<=counter;i++) {
            printf("%15d%15d\n", i, i*i);
        }
        if (counter == n)
            break;
        printf("Press Enter to continue...");
    } while (getchar());

    return 0;
}
