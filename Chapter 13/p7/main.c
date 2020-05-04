#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter a two-digit number: (1-99) ");
    scanf("%d", &x);
    int a, b;
    a = x / 10;
    b = x % 10;
    char *ty[10] = {"", "", "twenty", "thirty","forty","fifty", "sixty", "seventy","eighty", "ninety"};
    char *one_word[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *tens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    if (x < 10 || x >= 20) {
        printf("%s", ty[a]);
        if ((x >= 20) && (b != 0))
            printf("-");
        printf("%s", one_word[b-1]);
    } else {
        printf("%s", tens[x-10]);
    }
    return 0;
}
