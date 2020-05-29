#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_cmd(void) {
    printf("New command called.\n");
}
void open_cmd(void) {
    printf("Open command called.\n");
}
void close_cmd(void) {
    printf("Close command called.\n");
}
void close_all_cmd(void) {
    printf("Close all command called.\n");
}
void save_all_cmd(void) {
    printf("Save all command called.\n");
}
void exit_cmd(void) {
    printf("Exit command called.\n");
}

struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] ={
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
    {"close all", close_all_cmd},
    {"save all", save_all_cmd},
    {"exit", exit_cmd}
};

int main(int argc, char *argv[])
{
    char *p = NULL;
    if (argc >= 1) {
        p = argv[1];
        printf("1 argv: %s\n", p);
    }
    for (int i = 0; i < sizeof(file_cmd) / sizeof(file_cmd[0]); i++) {
        if (strcmp(p, file_cmd[i].cmd_name) == 0)
            (*file_cmd[i].cmd_pointer)();
    }
    return 0;
}
