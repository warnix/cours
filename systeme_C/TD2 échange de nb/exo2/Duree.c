#include <stdio.h>

struct Duree {
  int heures;
  int minutes;
  int secondes;
};

struct Duree construire_Duree(int heures, int minutes, int secondes){
  struct Duree temps = {
    .heures = heures,
    .minutes = minutes,
    .secondes = secondes
  };
  return temps;
}

void eclate(struct Duree t)
{
}

void afficher_Duree(const struct Duree *adr_duree)
{
  printf("l'heure:%d,les minutes:%d,les secondes:%d\n",
  adr_duree.heures,adr_duree.minutes,adr_duree.secondes);
}

int main(void) {

struct Duree t = construire_Duree(2,43,5);
afficher_Duree(&t);
return 0;

}
