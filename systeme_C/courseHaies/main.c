#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

typedef struct Equipe equipe;
struct Equipe
{
    char *nom;
    int temps;
};

typedef struct Podium Podium;
struct Podium
{
    struct Equipe *equipes;
    int taille;
};

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
    exit(somme);
}

void afficherPodium(struct Podium *podium)
{
    printf("Podium :\n");
    int min;
    for (int i = 0; i < podium->taille; i++)
    {
        min = i;
        for (int j = i+1; j < podium->taille; j++)
        {
            if(podium->equipes[j].temps<podium->equipes[min].temps){
                min = j;
            }
        }
        if(min != i){
            struct Equipe tmp = podium->equipes[i];
            podium->equipes[i]=podium->equipes[min];
            podium->equipes[min]=tmp;
        }
    }
    for(int i=0; i<podium->taille;i++){
        printf("%d.equipe %s\n", (i + 1), podium->equipes[i].nom);
    }
}

int main(int argc, char **argv)
{
    pid_t tabPid[argc];
    struct Podium podium;
    podium.equipes = malloc(argc * sizeof(struct Equipe));
    podium.taille = 0;
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
        int wstatus = 0;
        waitpid(tabPid[i - 1], &wstatus, 0);
        if (wstatus > 0)
        {
            struct Equipe equipe = {argv[i], wstatus};
            podium.equipes[podium.taille] = equipe;
            podium.taille = podium.taille + 1;
        }
    }
    afficherPodium(&podium);
    printf("* Fin Course\n");
    return 0;
}