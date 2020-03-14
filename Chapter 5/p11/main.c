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
    if (x < 10 || x >= 20) {
        switch (a) {
            case 9: printf("ninety"); break;
            case 8: printf("eighty");break;
            case 7: printf("seventy");break;
            case 6: printf("sixty");break;
            case 5: printf("fifty");break;
            case 4: printf("forty");break;
            case 3: printf("thirty");break;
            case 2: printf("twenty");break;
        }
        if ((x >= 20) && (b != 0))
            printf("-");

        switch (b) {
            case 1: printf("one");break;
            case 2: printf("two");break;
            case 3: printf("three");break;
            case 4: printf("four");break;
            case 5: printf("five");break;
            case 6: printf("six");break;
            case 7: printf("seven");break;
            case 8: printf("eight");break;
            case 9: printf("nine");break;
        }
    } else {
        switch(x) {
            case 10: printf("ten");break;
            case 11: printf("eleven");break;
            case 12: printf("twelve");break;
            case 13: printf("thirteen");break;
            case 14: printf("fourteen");break;
            case 15: printf("fifteen");break;
            case 16: printf("sixteen");break;
            case 17: printf("seventeen");break;
            case 18: printf("eighteen");break;
            case 19: printf("nineteen");break;
        }
    }
    return 0;
}
