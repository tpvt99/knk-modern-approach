#include <stdio.h>
#include <stdlib.h>

#define N (int) (sizeof(country_codes)/sizeof(country_codes[0]))

struct dialing_code {
    char *country;
    int code;
};

int main()
{
    const struct dialing_code country_codes[] = {
    {"Argentina", 54}, {"Bangladesh", 880},
    {"Brazil", 55}, {"Burma (Myanmar}", 95},
    {"China", 86}, {"Colombia", 57},
    {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
    {"Ethiopia", 251}, {"France", 33},
    {"Germany", 251}, {"India", 91},
    {"Indonesia", 62}, {"Iran", 98},
    {"Italy", 39}, {"Japan", 81},
    {"Mexico", 52}, {"Nigeria", 234},
    {"United States", 1}, {"Vietnam", 84}};
    printf("Enter a country code: ");
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < N; i++) {
        if (country_codes[i].code == n) {
            printf("Country is: %s", country_codes[i].country);
            break;
        }
    }
    if (i == N)
        printf("Not a valid code");
    return 0;
}
