#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

struct vstring {
    int n;
    char str[];
};

int read_line(char str[], int n);

int main()
{
    struct vstring *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i< num_remind; i++)
            if (strcmp(day_str, reminders[i]->str) <0 )
                break;
        for (j = num_remind; j>i;j--) {
            reminders[j] = reminders[j-1];
        }
        reminders[i] = malloc(sizeof(struct vstring) + 2 + strlen(msg_str) + 1);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }
        strcpy(reminders[i]->str, day_str);
        strcat(reminders[i]->str, msg_str);
        reminders[i]->n = 2 + strlen(msg_str) + 1;

        num_remind++;
    }
    printf("\nDay Reminder\n");
    for (i=0; i<num_remind;i++)
        printf(" %s\n", reminders[i]->str);

    return 0;
}

int read_line(char str[], int n) {
    int ch, i =0;
    while((ch = getchar()) != '\n')
        if (i<n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
