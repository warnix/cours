#ifndef SHELL_H
#define SHELL_H
#include <stdbool.h>
struct Shell
{
    bool running;
    int line_number;
    char *line;
    size_t line_length;
};
void shell_init(struct Shell *s);
void shell_run(struct Shell *s);
void shell_free(struct Shell *s);
void shell_read_line(struct Shell *s);
void shell_execute_line(struct Shell *s);
#endif