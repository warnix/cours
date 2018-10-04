#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "StringVector.h"
#define TAMPON_SIZE 100
int main()
{
    char tamponLecture[TAMPON_SIZE];
    int fini = 1;
    while(fini==1){
        int i = read(STDIN_FILENO, tamponLecture, TAMPON_SIZE);
        tamponLecture[i]='\0';
        struct StringVector str = split_line(tamponLecture);
        if (strcmp(str.strings[0],"exit")==0){
            fini = 0;
        }else if(strcmp(str.strings[0],"help")==0){
            printf("tapez exit pour arreter\n");
        }else{
            printf("commande inconnue\n");
        }
    }
    return 0;
}