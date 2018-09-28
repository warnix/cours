#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
  int jour;
  int mois;
  int annee;
};

struct Personne
{
  char *nom;
  char *prenom;
  struct Date naissance;
};

struct Annuaire
{
  int taille;
  struct Personne *tableau;
};

//affiche les personnes de l'annuaire
void afficher_annuaire(const struct Annuaire *ptr_annuaire)
{
  printf("-- affiche l'annuaire --\n");
  for (int i = 0; i < ptr_annuaire->taille; i++)
  {
    printf("nom %s,prénom %s,age %d\n", ptr_annuaire->tableau[i].nom,
           ptr_annuaire->tableau[i].prenom,
           ptr_annuaire->tableau[i].naissance.annee);
  }
}

//détruit l'annuaire et son allocation
void detruire_annuaire(struct Annuaire *ptr_annuaire)
{
  free(ptr_annuaire->tableau);
  ptr_annuaire->tableau = NULL;
  free(ptr_annuaire);
  ptr_annuaire = NULL;
}

//ajoute une personne à l'annuaire
int ajouter_personne(struct Annuaire *ptr_annuaire, const struct Personne *ptr_nouveau)
{
  printf("-- ajout d'une personne --\n");
  int tmp = (int)ptr_annuaire->taille;
  ptr_annuaire->taille = tmp+1;
  ptr_annuaire->tableau =
      realloc(ptr_annuaire->tableau, (tmp+1) * sizeof(struct Personne));
  ptr_annuaire->tableau[tmp] = *ptr_nouveau;

  return EXIT_SUCCESS;
}

int main(void)
{
  struct Date date = {31, 10, 1999};
  struct Personne p1 = {"bast", "vinc", date};
  struct Personne p2 = {"reee", "dfsd", date};
  struct Personne p3 = {"erwan", "ghgh", date};
  struct Personne p4 = {"guill", "rttt", date};
  struct Annuaire annuaire;
  annuaire.taille = 4;
  annuaire.tableau = malloc(annuaire.taille * sizeof(struct Personne));

  annuaire.tableau[0].nom = "test";
  annuaire.tableau[0].prenom = "test2";
  annuaire.tableau[0].naissance = date;

  annuaire.tableau[1]=p2;
  annuaire.tableau[2]=p3;
  annuaire.tableau[3]=p4;
  afficher_annuaire(&annuaire);
  ajouter_personne(&annuaire, &p1);
  afficher_annuaire(&annuaire);
  return EXIT_SUCCESSs;
}
