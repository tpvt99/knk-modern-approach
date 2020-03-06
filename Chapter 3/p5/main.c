#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;
    int c1, c2, c3, c4;
    int d1, d2, d3, d4;
    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
    scanf("%d%d%d%d", &b1, &b2, &b3, &b4);
    scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
    scanf("%d%d%d%d", &d1, &d2, &d3, &d4);

    printf("%d %d %d %d\n", a1, a2, a3, a4);
    printf("%d %d %d %d\n", b1, b2, b3, b4);
    printf("%d %d %d %d\n", c1, c2, c3, c4);
    printf("%d %d %d %d\n", d1, d2, d3, d4);

    printf("Row sums: %d %d %d %d\n", a1+a2+a3+a4, b1+b2+b3+b4, c1+c2+c3+c4, d1+d2+d3+d4);
    printf("Column sums: %d %d %d %d\n",a1+b1+c1+d1, a2+b2+c2+d2, a3+b3+c3+d3, a4+b4+c4+d4);
    printf("Diagonal sums: %d %d\n", a1+b2+c3+d4, d1+c2+b3+a4);
    return 0;
}
