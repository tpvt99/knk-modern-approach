#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

long int string2hex(char * s) {
    char *p = s;
    int counter = 0;
    while(*p) {
        if (!isxdigit(*p))
            return -1;
        p++;
        counter += 1;
    }
    long int val = 0;
    p = s;
    while(*p) {
        if ('0' <= *p && *p <= '9')
            val += (long int) (((*p)-48) * pow(16, counter-1));
        else
            val += (long int) (((*p)-87) * pow(16, counter-1));
        printf("Pow: %d and int: %d and val: %ld\n", counter-1, *p, val);
        p++;
        counter-=1;
    }
    return val;
}

int main()
{
    char s[] = "001c";
    printf("Value: %ld\n", string2hex(s));
    return 0;
}
