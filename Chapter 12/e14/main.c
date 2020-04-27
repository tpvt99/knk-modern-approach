#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int *, int n, int key); // search each elements, increment by one
bool search_row(int (*)[], int, int);

int main()
{
    int temperature[7][24] = {  {12,43,21,12},
                                {12,13,14,15},
                                {43,54,65,76},
                                {12,23,43,54}};
    int key = 54;
    //if(search(&temperature[0][0], 7*24, key)) {
    if(search_row(temperature, 7, key)) {
        printf("%d is inside temperature\n", key);
    } else {
        printf("%d is not inside temperature\n", key);
    }
    return 0;
}

bool search(int *temperature, int n, int key) {
    int *p = temperature;
    for (;p<temperature + n; p++)
        if (*p == key)
            return true;
    return false;
}

bool search_row(int (*temperature)[24], int rows, int key) {
    int (*p)[24] = temperature;
    for (;p<temperature+rows;p++) {
        int *q = *p;
        for (;q< *p + 24;q++) {
            printf("Key: %d\n", *q);
            if (*q == key)
                return true;
        }
    }
    return false;
}
