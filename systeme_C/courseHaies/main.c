#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void simuler_equipe(int x)
{
    int temp;
    int chute;
    int somme = 0;
    pid_t pidTmp = getpid();
    printf("L'équipe %d au départ.\n", pidTmp);
    sleep(2);
    for (int i = 0; i < 4; i++)
    {
        printf("-> le coureur %d de l'équipe %d est parti.\n", (i+1), pidTmp);
        temp = nbRandom(8,12,(10*x+i));
        chute = nbRandom(0,10,(100*x+i));
        if(chute == 1){
            exit(0);
        }
        sleep(temp);
        somme = somme + temp;
    }
    printf("L'équipe %d est arrivée en %ds !\n", pidTmp, somme);
    exit(0);
}

int nbRandom(int min, int max, int seed){
    srand(seed);
    int nb = min + rand() % (max - min + 1);
    return nb;
}

int main()
{
    printf("* Début Course\n");
    pid_t pid = fork();
    if (pid == 0)
    {
        simuler_equipe(1);
    }
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        simuler_equipe(2);
    }
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        simuler_equipe(3);
    }
    pid_t pid3 = fork();
    if (pid3 == 0)
    {
        simuler_equipe(4);
    }
    pid_t pid4 = fork();
    if (pid4 == 0)
    {
        simuler_equipe(5);
    }
    pid_t pid5 = fork();
    if (pid5 == 0)
    {
        simuler_equipe(6);
    }
    int wstatus;
    waitpid(pid, &wstatus, 0);
    waitpid(pid1, &wstatus, 0);
    waitpid(pid2, &wstatus, 0);
    waitpid(pid3, &wstatus, 0);
    waitpid(pid4, &wstatus, 0);
    waitpid(pid5, &wstatus, 0);
    printf("* Fin Course\n");
    return 0;
}