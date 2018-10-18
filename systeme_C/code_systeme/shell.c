#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "StringVector.h"
#include "commands.h"

#define TAMPON_SIZE 100

void shell_init(struct Shell *shell)
{
    shell->running = false;
    shell->line = malloc(TAMPON_SIZE * sizeof(char));
    shell->line_length = 0;
    shell->line_number = 0;
}
void shell_run(struct Shell *shell)
{
    shell->running = true;
    while (shell->running)
    {
        shell_read_line(shell);
    }
}
void shell_free(struct Shell *shell)
{
    free(shell->line);
}
void shell_read_line(struct Shell *shell)
{
    printf("$:\n");
    shell->line_length = read(STDIN_FILENO, shell->line, TAMPON_SIZE);
    shell->line[shell->line_length] = '\0';
    shell_execute_line(shell);
}
void shell_execute_line(struct Shell *shell)
{
    struct StringVector token = split_line(shell->line);
    int nb_tokens = string_vector_size(&token);
    if (nb_tokens == 0)
    {
        printf("-> Nothing to do !\n");
    }
    else
    {
        char *name = string_vector_get(&token, 0);
        Action action = get_action(name);
        action(shell, &token);
        string_vector_free(&token);
    }
}