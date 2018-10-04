#include <stdio.h>
#include <stdlib.h>
#include "annuaire.h"
#include "fichier.h"

int main(void)
{
  struct Date date = {31, 10, 1999};
  struct Personne p1 = {"bast", "vinc", date};
  struct Personne p2 = {"reee", "dfsd", date};
  struct Personne p3 = {"erwan", "ghgh", date};
  struct Personne p4 = {"guill", "rttt", date};
  struct Annuaire annuaire;
  annuaire.taille = 5;
  annuaire.tableau = malloc(annuaire.taille * sizeof(struct Personne));
  annuaire.tableau[0].nom = "test";
  annuaire.tableau[0].prenom = "test2";
  annuaire.tableau[0].naissance = date;
  annuaire.tableau[1] = p2;
  annuaire.tableau[2] = p3;
  annuaire.tableau[3] = p4;
  annuaire.tableau[4] = p1;

  printf("\n---écriture dans le fichier---\n");
  ecrire_fichier(&annuaire, "personne.txt");
  printf("\n---lire fichier avant écriture---\n");
  lire_fichier(&annuaire, "personne.txt");
  afficher_annuaire(&annuaire);

  return EXIT_SUCCESS;
}
