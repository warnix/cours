#include <stdio.h>
#include <stdlib.h>

struct Personne {
  char nom[30];
  char prenom[30];
  int age;
};


int main(void) {

struct Personne t = {"toto","code",17};
printf("nom %s,prénom %s,age %d\n",t.nom,t.prenom,t.age);
printf("taille de la personne t %d\n",sizeof(t));

struct Personne equipe[5];
printf("taille de l'équipe %d\n",sizeof(equipe));

for (int i = 0; i<5; i++){
  printf("adresse de t = %p\n", (void*) &equipe[i]);
}

return EXIT_SUCCESS;
}
