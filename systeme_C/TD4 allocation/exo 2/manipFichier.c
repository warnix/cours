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
  ptr_annuaire->taille++;
  ptr_annuaire->tableau =
      realloc(ptr_annuaire->tableau, (tmp + 1) * sizeof(struct Personne));
  ptr_annuaire->tableau[tmp] = *ptr_nouveau;

  return EXIT_SUCCESS;
}

//lis un fichier et l'intégre à un annuaire
int lire_fichier(struct Annuaire *ptr_annuaire, const char *nomfic)
{
  char c[50] = "";
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
      fgets(c, 50, f);
      struct Personne p = {"", "", NULL};
      str = strtok(c, ";");
      while (str != NULL)
      {
        printf("%s", str);
        str = strtok(NULL, ";");
      }
      printf("\n");
    }
    fclose(f);
  }
  return EXIT_SUCCESS;
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
      fprintf(f, "\n%s;", ptr_annuaire->tableau[i].nom);
      fprintf(f, "%s;", ptr_annuaire->tableau[i].prenom);
      fprintf(f, "%d", ptr_annuaire->tableau[i].naissance.annee);
    }
    fclose(f);
  }
}

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

printf("\n---lire fichier avant écriture---\n");
  lire_fichier(&annuaire, "personne.txt");
  printf("\n---écriture dans le fichier---\n");
  ecrire_fichier(&annuaire, "personne.txt");
  printf("\n---lire fichier après écriture---\n");
  lire_fichier(&annuaire, "personne.txt");

  return EXIT_SUCCESS;
}
