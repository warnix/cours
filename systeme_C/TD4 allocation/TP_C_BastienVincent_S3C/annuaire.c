#include <stdio.h>
#include <stdlib.h>
#include "annuaire.h"

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