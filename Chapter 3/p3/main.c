#include <stdio.h>
#include <stdlib.h>

int main()
{
    int gsi, gi, pc, in, check;
    printf("Enter ISBN: ");
    scanf("%d - %d - %d - %d - %d", &gsi, &gi, &pc, &in, &check);
    printf("GS1 prefix: %d\n", gsi);
    printf("Group identifier: %d\n", gi);
    printf("Publisher code: %d\n", pc);
    printf("Item number: %d\n", in);
    printf("Check digit: %d\n", check);
    return 0;
}
