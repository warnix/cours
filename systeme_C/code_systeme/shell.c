#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include "shell.h"
#include "StringVector.h"

#define TAMPON_SIZE 100

void shell_init(struct Shell *s)
{
    s->running = false;
    s->line = malloc(TAMPON_SIZE * sizeof(char));
    s->line_length = 0;
    s->line_number = 0;
}
void shell_run(struct Shell *s)
{
    s->running = true;
    while (s->running)
    {
        shell_read_line(s);
    }
}
void shell_free(struct Shell *s)
{
    free(s->line);
}
void shell_read_line(struct Shell *s)
{
    printf("$:\n");
    s->line_length = read(STDIN_FILENO, s->line, TAMPON_SIZE);
    s->line[s->line_length] = '\0';
    shell_execute_line(s);
}
void shell_execute_line(struct Shell *s)
{
    struct StringVector str = split_line(s->line);
    if (str.strings != NULL)
    {

        if (strcmp(string_vector_get(&str, 0), "exit") == 0)
        {
            s->running = false;
        }
        else if (strcmp(string_vector_get(&str, 0), "help") == 0)
        {
            printf("    - tapez exit pour arreter\n");
            printf("    - tapez ! pour lancer le terminal\n");
        }
        else if (strcmp(string_vector_get(&str, 0), "cd") == 0)
        {
            if (string_vector_get(&str, 2) == NULL)
            {
                printf("déplacement vers home : \n");
                chdir(getenv("HOME"));
            }
            else
            {
                printf("déplacement vers un fichier : \n");
                chdir(string_vector_get(&str, 2));
            }
        }
        else if (strcmp(string_vector_get(&str, 0), "!") == 0)
        {
            if (string_vector_get(&str, 1) != NULL)
            {
                printf("rien pour l'intant\n");
            }
            else
            {
                printf("lancement du sous-shell : \n");
                system("/bin/bash");
            }
        }
        else
        {
            printf("commande inconnue\n");
        }
    }else{
        printf("aucune commande entrée\n");
    }
}