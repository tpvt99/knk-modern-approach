#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("Enter a 12-hour time: ");
    int h, m;
    scanf("%d: %d", &h, &m);
    char c;
    scanf(" %c", &c);
    c = toupper(c);
    if (c == 'P') {
        if (h != 12)
            h += 12;
    }
    printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);
    return 0;
}
