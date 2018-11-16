#ifndef SHELL_H
#define SHELL_H
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct Shell
{
    bool running;
    int line_number;
    char *line;
    size_t line_length;
    pid_t pid[25];
    char* name[25];
    int current;
};
void shell_init(struct Shell *s);
void shell_run(struct Shell *s);
void shell_free(struct Shell *s);
void shell_read_line(struct Shell *s);
void shell_execute_line(struct Shell *s);
#endif