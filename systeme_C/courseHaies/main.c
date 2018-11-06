#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void simuler_equipe(char *equipe)
{
    int temp;
    int chute;
    int somme = 0;
    printf("L'équipe %s au départ.\n", equipe);
    sleep(1);
    srand(getpid());
    for (int i = 0; i < 4; i++)
    {
        printf("-> le coureur %d de l'équipe %s est parti.\n", (i + 1), equipe);
        temp = 8 + rand() % (11 - 8 + 1);
        chute = rand() % (10 + 1);
        if (chute == 1)
        {
            exit(0);
        }
        sleep(temp);
        somme = somme + temp;
    }
    printf("L'équipe %s est arrivée en %ds !\n", equipe, somme);
    exit(0);
}

int main(int argc, char **argv)
{
    pid_t tabPid[argc];
    printf("* Début Course\n");
    for (int i = 1; i < argc; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            simuler_equipe(argv[i]);
        }
        tabPid[i - 1] = pid;
    }
    for (int i = 1; i < argc; i++)
    {
        int wstatus;
        waitpid(tabPid[i - 1], &wstatus, 0);
    }
    printf("* Fin Course\n");
    return 0;
}