#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    printf("Enter the number of entries in the table: ");
    scanf("%d", &n);
    for(i=n-10; i<=n;i++) {
        printf("%30d%30d\n", i, i*i);
    }
    return 0;
}
