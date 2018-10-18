#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

struct Personnage{
    char *nom;
    char *phrase;
    int nb_repetitions;
    int delai_seconde;
};
void simuler_personnage(struct Personnage *p)
{
    printf("%s arrive.\n", p->nom);
    sleep(p->delai_seconde);
    for (int i = 0; i < p->nb_repetitions; i++)
    {
        printf("%s : %s\n", p->nom, p->phrase);
        sleep(p->delai_seconde);
    }
    printf("%s s'en va.\n", p->nom);
    exit(0);
}
struct Personnage personnages[] = {
    {"Dale Cooper", "Are you Laura Palmer ?", 5, 2},
    {"Log Lady", "The owls were flying", 3, 3},
    {"Gordon Cole", "WHAT ?!", 10, 1}
};
int main()
{
    printf("* debut simulation\n");
    pid_t pid = fork();
    if (pid == 0)
    {
        simuler_personnage(&personnages[0]);
    }
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        simuler_personnage(&personnages[1]);
    }
    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        simuler_personnage(&personnages[2]);
    }
    int wstatus;
    waitpid(pid,&wstatus,0);
    waitpid(pid1,&wstatus,0);
    waitpid(pid2,&wstatus,0);
    printf("* fin processus\n");
    return 0;
}