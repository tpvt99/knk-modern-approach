#include <stdio.h>
#include <stdlib.h>

struct time {
    int hour;
    int minute;
    int second;
};

struct time split_time(long total_seconds) {
    struct time t;
    int minute = total_seconds / 60;
    int second = total_seconds - minute * 60;
    int hour = minute / 60;
    minute = minute - hour * 60;
    t.hour = hour;
    t.minute = minute;
    t.second = second;
    return t;

};

int main()
{
    struct time t = split_time(15487);
    printf("Hour: %d Minute: %d Second: %d", t.hour, t.minute, t.second);
    return 0;
}
