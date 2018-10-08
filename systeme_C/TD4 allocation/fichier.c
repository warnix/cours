#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annuaire.h"
#include "fichier.h"
//lis un fichier et l'intégre à un annuaire
int lire_fichier(struct Annuaire *ptr_annuaire, const char *nomfic)
{
  char tab[4][30];
  int i;
  int test = 0;
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
        if(i==2){
          tab[i][4]=NULL;
        }
        printf("%s|", tab[i]);
        str = strtok(NULL, ";");
        i++;
      }
      if (test == 0)
      {
        p.prenom=malloc(30 * sizeof(char));
        strcpy(p.prenom,tab[0]);
        printf("%s\n", tab[0]);

        p.nom=malloc(30 * sizeof(char));
        strcpy(p.nom,tab[1]);
        printf("%s\n", tab[1]);
        
        creerDate(&p.naissance, &tab[2]);
        //printf("%d\n", p.naissance.annee);
        ajouter_personne(ptr_annuaire, &p);
        test = 1;
        break;
      }

    }
    fclose(f);
  }
  return EXIT_SUCCESS;
}

void creerDate(struct Date *date, char *str)
{
  date->jour = 0;
  date->mois = 0;
  date->annee = atoi(str);
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