#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annuaire.h"
#include "fichier.h"
//lis un fichier et l'intégre à un annuaire
int lire_fichier(struct Annuaire *ptr_annuaire, const char *nomfic)
{
  char tab[3][50];
  int i;
  char s[50] = "";
  char *str;
  FILE *f = fopen(nomfic, "r");
  if (f == NULL)
  {
    printf("Could not open file\n");
    return 0;
  }
  else
  {
    while (!feof(f))
    {
      i = 0;
      fgets(s, 50, f);
      struct Personne p;
      str = strtok(s, ";");
      while (str != NULL)
      {
        strcpy(tab[i], str);
        printf("%s ", tab[i]);
        str = strtok(NULL, ";");
        i++;
      }
      p.prenom = tab[0];
      printf("\n%s\n",p.prenom);
      p.nom = tab[1];
      printf("%s\n",p.nom);
      //la suite à corriger
      //creerDate(&p.naissance,&tab[2]); 
      //printf("%d\n",p.naissance.jour);
      //ajouter_personne(ptr_annuaire,&p);
    }
    fclose(f);
  }
  return EXIT_SUCCESS;
}

void creerDate(struct Date *date,char *str)
{
  char *s;
  int tab[3];
  int i = 0;
  s = strtok(str, ",");
  while (str != NULL)
  {
    tab[i] = (int)str;
    printf("%d ", tab[i]);
    str = strtok(NULL, ",");
    i++;
  }
  date->jour = tab[0];
  date->mois = tab[1];
  date->annee = tab[2];
}

//écris le contenu d'un annuaire dans un fichier
int ecrire_fichier(const struct Annuaire *ptr_annuaire, const char *nomfic)
{
  FILE *f = fopen(nomfic, "a");
  if (f == NULL)
  {
    printf("Could not open file\n");
    return 0;
  }
  else
  {
    for (int i = 0; i < (ptr_annuaire->taille); i++)
    {
      fprintf(f, "\n%s;%s;%d", ptr_annuaire->tableau[i].nom,
              ptr_annuaire->tableau[i].prenom,
              ptr_annuaire->tableau[i].naissance.annee);
    }
    fclose(f);
  }
  return EXIT_SUCCESS;
}