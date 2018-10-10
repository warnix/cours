#include <stdio.h>
#include <stdlib.h>
#include "strChar.h"

int main(void)
{
  char str[10] = "abcde";
  ;
  int taille = strlen(str);
  printf("taille de la chaine : %d\n", taille);
  char str2[] = "sgft";
  int taille2 = strlen(str2);
  printf("taille de la chaine2 : %d\n", taille2);
  strcatt(str, str2);

  printf("chaine concat %s\n", str);
  char str3[] = "aaaa";
  char str4[] = "aaaab";
  char str5[] = "bba";
  char str6[] = "bbb";
  printf("comparaison str3 et str4 %d\n", strcmp(str3, str4));
  printf("comparaison str4 et str5 %d\n", strcmp(str5, str4));
  printf("comparaison str5 et str6 %d\n", strcmp(str5, str6));
  printf("comparaison str3 et str3 %d\n", strcmp(str3, str3));
}
