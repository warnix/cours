#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strChar.h"

//retourne la longeur de la chaine de caractère
size_t strlen(const char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return i;
}

//concat les deux chaine de caractère
char *strcat(char *dest, const char *src)
{
  int i = 0;
  int taille = strlen(dest);
  while (src[i] != '\0')
  {
    dest[taille + i] = src[i];
    i++;
  }
}

char *strcatt(char *dest, const char *src)
{
  while (*dest)
  {
    dest++;
  }
  while (*src)
  {
    *dest = *src;
    src++;
    dest++;
  }
}

/* retourne un entier donnant leur ordre lexicographique
* 0 si parail
* -1 si la première est avant la deuxième
* 1 si la première est après la deuxième
*/
int strcmp(const char *s1, const char *s2)
{
  int i = 0;
  int result = 0;
  int special = 0; //utiliser pour les cas comme s2=AAAA et s1=AAAAB
  int max_index;
  int s1l = (int)strlen(s1);
  int s2l = (int)strlen(s2);
  if (s1l < s2l)
  {
    max_index = s1l;
    special = -1;
  }
  else if (s2l < s1l)
  {
    max_index = s2l;
    special = 1;
  }
  else
  {
    max_index = s2l;
  }
  for (int i = 0; i < max_index && result == 0; i++)
  {
    if (s1[i] < s2[i])
    {
      result = -1;
    }
    else if (s1[i] > s2[i])
    {
      result = 1;
    }
  }
  if (result == 0)
  {
    result = special;
  }
  return result;
}
