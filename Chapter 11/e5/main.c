#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main()
{
    printf("Hello world!\n");
    int hr, min, sec, total_sec;
    total_sec = 52145;
    split_time(total_sec, &hr, &min, &sec);
    printf("%d has %d hours, %d mins, %d seconds\n", total_sec, hr, min, sec);
    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
    int total_mins = total_sec / 60;
    *sec = total_sec - total_mins * 60;
    *hr = total_mins / 60;
    *min = total_mins - (*hr) * 60;

}
