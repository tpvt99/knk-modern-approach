#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

void lower_string(char *ptr);

int main(int argc, char *argv[])
{
    char *planets[] = {"mercury", "venus", "earth",
                        "mars", "jupiter", "saturn",
                        "uranus", "neptune", "pluto"};
    int i,j;

    for(i = 1; i < argc; i++) {
        for(j=0;j < NUM_PLANETS; j++) {
            lower_string(argv[i]);
            if (strcmp(argv[i], planets[j])==0) {
                printf("%s is planet %d\n", argv[i], j+1);
                break;
            }
        }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}

void lower_string(char *ptr) {
    while (*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
}
