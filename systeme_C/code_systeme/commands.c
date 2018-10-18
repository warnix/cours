#include "shell.h"
#include "commands.h"

static void do_exit(struct Shell *this, const struct StringVector *args);
static void do_cd(struct Shell *this, const struct StringVector *args);
static void do_pwd(struct Shell *this, const struct StringVector *args);
static void do_help(struct Shell *this, const struct StringVector *args);
static void do_system(struct Shell *this, const struct StringVector *args);
static void do_execute(struct Shell *this, const struct StringVector *args);
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
static void do_execute(struct Shell *this, const struct StringVector *args)
{
    printf("commande introuvable.\n");
}
static void do_rappel(struct Shell *this, const struct StringVector *args)
{
    printf("commande \"rappel\" à faire.\n");
}