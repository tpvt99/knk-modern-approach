#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    int square =1, odd=3;
    for (int i=1; i<=n; i++) {
        printf("%10d%10d\n", i, square);
        square += odd;
        odd+=2;
    }
    return 0;
}
