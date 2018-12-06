#include "shell.h"
#include "commands.h"
#include <sys/types.h>
#include <ctype.h>
#include <sys/wait.h>
#include <signal.h>

static void do_exit(struct Shell *this, const struct StringVector *args);
static void do_cd(struct Shell *this, const struct StringVector *args);
static void do_pwd(struct Shell *this, const struct StringVector *args);
static void do_help(struct Shell *this, const struct StringVector *args);
static void do_system(struct Shell *this, const struct StringVector *args);
static void do_execute(struct Shell *this, struct StringVector *args);
static void do_rappel(struct Shell *this, const struct StringVector *args);
static void do_jobs(struct Shell *this, const struct StringVector *args);

struct Shell *shell;

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
    {.name = "jobs", .action = do_jobs},
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

void fin_fils(int sig)
{
    __pid_t p = wait(NULL);
    if (p != -1)
    {
        printf("fin de %d!\n", p);
        do_suprJobs(p);
    }
}

void do_suprJobs(pid_t p)
{
    int i = 0;
    while (shell->pid[i] != p)
    {
        i++;
    }
    if (i == shell->current)
    {
        shell->pid[i] = -1;
    }
    else
    {
        while (i < shell->current)
        {
            shell->pid[i] = shell->pid[i + 1];
        }
        shell->pid[shell->current] = -1;
    }
    shell->current = shell->current - 1;
}

void do_arrPlan(struct Shell *this, const struct StringVector *args, pid_t pid)
{
    this->current = this->current + 1;
    this->name[this->current] = malloc(256 * sizeof(char));
    string_vector_space(this->name[this->current], args->strings, args->size);
    char *name = malloc(256 * sizeof(char));
    name = strcat(name, args->strings[0]);
    name = strcat(name, " ");
    this->name[this->current] = strcat(name, this->name[this->current]);
    this->pid[this->current] = pid;
}

static void do_execute(struct Shell *this, struct StringVector *args)
{
    shell = this;
    int isArrPlan = 0;
    int redirection = isRedirected(args);
    if (args->size >= 2)
    {
        char *name = string_vector_get(args, args->size - 1);
        if (strcmp(name, "&") == 0)
        {
            args->strings[args->size - 1] = NULL;
            args->size = args->size - 1;
            isArrPlan = 1;
        }
    }
    printf("  -> execute \n");
    signal(SIGCHLD, fin_fils);
    __pid_t pid = fork();
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
    if (isArrPlan == 1)
    {
        do_arrPlan(this, args, pid);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}

int isRedirected(struct StringVector *args){
    int redirection = 0;
    
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
static void do_jobs(struct Shell *this, const struct StringVector *args)
{
    if (this->current != -1)
    {
        for (int i = 0; i <= this->current; i++)
        {
            printf("[%d] %s\n", this->pid[i], this->name[i]);
        }
    }
}