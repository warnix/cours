//fichier hello.c
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  //échange de deux entiers
  printf("échande de deux entiers\n");
  int a,b;
  demande_entiers("Combien vaut a ?",&a);
  printf("--------\n");
  demande_entiers("Combien vaut b ?",&b);
  affichage_entiers(&a,&b);
  echange_entiers(&a,&b);
  affichage_entiers(&a,&b);
  //br
  printf("\n");
  //ordonnance de deux entiers
  printf("ordonnance de deux entiers\n");
  int c,d;
  demande_entiers("Combien vaut c ?",&c);
  printf("--------\n");
  demande_entiers("Combien vaut d ?",&d);
  affichage_entiers(&c,&d);
  ordonner_entiers(&c,&d);
}
void ordonner_entiers(int *n,int *m)
{
  if(*n>*m){
    echange_entiers(n,m);
    affichage_entiers(n,m);
  }else{
    printf("déjà ordonné\n");
  }
}
void demande_entiers(char question[], int *adr_reponse)
{
    printf("%s\n",question);
    scanf("%d", adr_reponse);
}
void echange_entiers(int *n,int *m)
{
  printf("échange fait\n");
  int p = *n;
  *n = *m;
  *m = p;
}
void affichage_entiers(int *n,int *m)
{
  printf("a vaut :%d\n",*n);
  printf("b vaut :%d\n",*m);
}
