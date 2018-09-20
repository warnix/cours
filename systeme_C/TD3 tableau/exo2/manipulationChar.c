#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//retourne la longeur de la chaine de caractère
size_t strlen(const char *s){
  int i = 0;
  while (s[i]!='\0') {
    i++;
  }
  return i;
}

//concat les deux chaine de caractère
char *strcat(char *dest, const char *src)
{
  int i = 0;
  int taille = strlen(dest);
  while (src[i]!='\0') {
    dest[taille+i]=src[i];
    i++;
  }
}

/* retourne un entier donnant leur ordre lexicographique
* 0 si parail
* -1 si la première est avant la deuxième
* 1 si la première est après la deuxième
*/
int strcmp(const char *s1, const char *s2){
  int i = 0;
  int result = 0;
  int special = 0; //utiliser pour les cas comme s2=AAAA et s1=AAAAB
  char *testeur;
  if (strlen(s1)<strlen(s2)){
    strcpy(testeur,s1);
    special = -1;
  }else if(strlen(s2)<strlen(s1)){
    strcpy(testeur,s2);
    special = 1;
  }else{
    strcpy(testeur,s2);
  }
  while( testeur[i]!='\0' && result == 0 ){
    if(s1[i]<s2[i]){result = -1;}
    else if(s1[i]>s2[i]){result = 1;}
    else{i++;}
  }
  if(result == 0){
    result = special;
  }
  return result;
}

int main(void) {
  char str[10]="abcde";
  int taille = strlen(str);
  printf("taille de la chaine : %d\n", taille);
  char str2[]="sgft";
  int taille2 = strlen(str2);
  printf("taille de la chaine2 : %d\n", taille2);
  strcat(str,str2);
  printf("chaine concat %s\n", str);
  char str3[]="aaaa";
  char str4[]="aaaab";
  char str5[]="bba";
  char str6[]="bbb";
  printf("comparaison str3 et str4 %d\n",strcmp(str3,str4));
  printf("comparaison str4 et str5 %d\n",strcmp(str5,str4));
  printf("comparaison str5 et str6 %d\n",strcmp(str5,str6));
  printf("comparaison str3 et str3 %d\n",strcmp(str3,str3));
}
