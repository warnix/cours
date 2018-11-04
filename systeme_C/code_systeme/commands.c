#include "shell.h"
#include "commands.h"
#include <sys/types.h>

static void do_exit(struct Shell *this, const struct StringVector *args);
static void do_cd(struct Shell *this, const struct StringVector *args);
static void do_pwd(struct Shell *this, const struct StringVector *args);
static void do_help(struct Shell *this, const struct StringVector *args);
static void do_system(struct Shell *this, const struct StringVector *args);
static void do_execute(struct Shell *this, struct StringVector *args);
static void do_rappel(struct Shell *this, const struct StringVector *args);

static struct
{
    const char *name;
    Action action;
} actions[] = {
    {.name = "exit", .action = do_exit},
    {.name = "cd", .action = do_cd},
    {.name = "pwd", .action = do_pwd},
    {.name = "help", .action = do_help},
    {.name = "?", .action = do_help},
    {.name = "!", .action = do_system},
    {.name = "rappel", .action = do_rappel},
    {.name = NULL, .action = do_execute}};

Action get_action(char *name)
{
    int i = 0;
    while (actions[i].name != NULL && strcmp(actions[i].name, name) != 0)
    {
        i++;
    }
    return actions[i].action;
}

//-------------------------------------------
static void do_exit(struct Shell *this, const struct StringVector *args)
{
    this->running = false;
}
static void do_cd(struct Shell *this, const struct StringVector *args)
{
    if (string_vector_get(args, 1) != NULL)
    {
        printf("déplacement vers un fichier : \n");
        chdir(string_vector_get(args, 1));
    }
    else
    {
        printf("déplacement vers home : \n");
        chdir(getenv("HOME"));
    }
}
static void do_pwd(struct Shell *this, const struct StringVector *args)
{
    printf("vous êtes ici : ");
    fflush(stdout);
    system("pwd");
}
static void do_help(struct Shell *this, const struct StringVector *args)
{
    printf("    - tapez \"exit\" pour arreter\n");
    printf("    - tapez \"cd\" pour vous déplacer\n");
    printf("    - tapez \"pwd\" pour voir où vous êtes\n");
    printf("    - tapez \"help\" pour afficher les aides\n");
    printf("    - tapez \"?\" pour afficher les aides\n");
    printf("    - tapez \"!\" pour lancer une terminal\n");
    printf("    - tapez \"! commande\" pour lancer une commande\n");
    printf("    - tapez \"RAPPEL nom tmps\" pour lancer un rappelle \"nom\" dans un temps donné en seconde\n");
}
static void do_system(struct Shell *this, const struct StringVector *args)
{
    if (string_vector_get(args, 1) != NULL)
    {
        char *cmd = malloc(256 * sizeof(char));
        string_vector_space(cmd, args->strings, args->size);
        system(cmd);
        cmd = NULL;
        free(cmd);
    }
    else
    {
        printf("lancement du sous-shell : \n");
        system("/bin/bash");
    }
}
static void do_execute(struct Shell *this, struct StringVector *args)
{
    int arrPlan = 0;
    if (args->size >= 2)
    {
        char *name = string_vector_get(args, args->size - 1);
        if (strcmp(name, "&") == 0)
        {
            args->strings[args->size - 1] = NULL;
            args->size = args->size-1;
            arrPlan = 1;
        }
    }
    printf("  -> execute \n");
    pid_t pid = fork();
    if (pid == 0)
    {
        if (args->strings[1] != NULL)
        {
            execvp(args->strings[0], args->strings);
        }
        else
        {
            execlp(args->strings[0], args->strings[0], NULL);
        }
        do_exit(this, args);
    }
    if (arrPlan == 1)
    {
        char *dest = malloc(256 * sizeof(char));
        string_vector_space(dest, args->strings, args->size);
        dest = strcat(args->strings[0],dest);
        printf("[%d] %s\n", pid, dest);
        dest = NULL;
        free(dest);
    }
    if (arrPlan == 0)
    {
        int status;
        waitpid(pid, &status, 0);
    }
}
static void do_rappel(struct Shell *this, const struct StringVector *args)
{
    int digit = 0;
    if (string_vector_get(args, 1) != NULL)
    {
        for (int i = 0; args->strings[1][i] != '\0'; ++i)
        {
            if (isdigit(args->strings[1][i]) == 0)
            {
                digit = 1;
            }
        }
        if (digit == 0)
        {
            pid_t p = fork();
            if (p == 0)
            {
                sleep(atoi(args->strings[1]));
                if (args->strings[2] != NULL)
                {
                    char *cmd = malloc(256 * sizeof(char));
                    string_vector_space(cmd, args->strings, args->size);
                    char *str = cmd + strlen(args->strings[1]);
                    printf("Rappel :%s\n", str);
                    cmd = NULL;
                    free(cmd);
                }
                else
                {
                    printf("Rappel : sans argument\n");
                }
                printf("shell:$ "); //pour le design
                do_exit(this, args);
            }
        }
        else
        {
            printf("erreur d'argument\n");
        }
    }
    else
    {
        printf("pas d'argument\n");
    }
}