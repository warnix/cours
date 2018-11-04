#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void simuler_equipe(int x, int *tabTemp, int *tabChute, char *equipe, int taille)
{
    int temp;
    int chute;
    int index;
    int somme = 0;
    printf("L'équipe %s au départ.\n", equipe);
    sleep(1);
    for (int i = 0; i < 4; i++)
    {
        printf("-> le coureur %d de l'équipe %s est parti.\n", (i + 1), equipe);
        index = (x + i * (taille / 4)) - 1;
        srand(tabTemp[index]);
        temp = 8 + rand() % (11 - 8 + 1);
        srand(tabChute[index]);
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
    printf("* Début initialisation\n");
    srand(time(NULL));
    pid_t tabPid[argc];

    //struct avec les deux tableaux et la taille ?
    int TAILLE = 4 * (argc - 1);
    int tabTemp[TAILLE];
    int tabChute[TAILLE];
    for (int i = 0; i < TAILLE; i++)
    {
        tabTemp[i] = rand();
        tabChute[i] = rand();
    }
    printf("* Fin initialisation\n");
    printf("* Début Course\n");
    for (int i = 1; i < argc; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            simuler_equipe(i, tabTemp, tabChute, argv[i], TAILLE);
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