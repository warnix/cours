#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void simuler_equipe(int x, int tabTemp[24], int tabChute[24], char *equipe)
{
    x = x+1;
    int temp;
    int chute;
    int somme = 0;
    printf("L'équipe %s au départ.\n", equipe);
    sleep(2);
    for (int i = 0; i < 4; i++)
    {
        printf("-> le coureur %d de l'équipe %s est parti.\n", (i + 1), equipe);
        srand(tabTemp[(x * i)]);
        temp = 8 + rand() % (11 - 8 + 1);
        srand(tabChute[(x * i)]);
        chute = rand() % (10 + 1);
        if (chute == 1)
        {
            printf("-- Chute équipe %s --\n",equipe);
            exit(0);
        }
        sleep(temp);
        somme = somme + temp;
    }
    printf("L'équipe %s est arrivée en %ds !\n", equipe, somme);
    exit(0);
}

int main(int argc, char** argv)
{
    printf("* initialisation \n");
    srand(time(NULL));
    int tabTemp[24];
    int tabChute[24];
    pid_t tabPid[argc];
    for (int i = 0; i < 24; i++)
    {
        tabTemp[i] = rand();
        tabChute[i] = rand();
    }
    sleep(1);
    printf("* Début Course\n");
    for (int i = 1; i < argc; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            simuler_equipe(i, tabTemp, tabChute, argv[i]);
        }
        tabPid[i-1]=pid;
    }
    for (int i = 0; i < argc; i++)
    {
        int wstatus;
        waitpid(tabPid[i], &wstatus, 0);
    }
    printf("* Fin Course\n");
    return 0;
}