#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "TabEntier.h"

using namespace std;

#define MAX_TAB 1000

TabEntier::TabEntier(int nbelem){
  taille = nbelem;
  tableau = new int[taille];
}

TabEntier::~TabEntier(){
  delete[] tableau;
}

int 
TabEntier::operator[](const int i){
  return tableau[i];
}

void
TabEntier::Remplir(){
  int i;

  /* On initialise la fonction de generation de nombre aleatoire */
  srand((unsigned)time(NULL));

  /* On remplit le tableau aleatoirement */
  for (i=0; i<taille; i++)
    tableau[i] = (rand()%MAX_TAB - MAX_TAB / 2);

}

int
TabEntier::Max(){
  int i, max;

  /* On initialise max a la valeur du premier element du tableau */
  max = tableau[0];

  /* On parcours le tableau à la recherche d'un plus grand élément que max */
  for(i = 1 ; i<taille; i++) {
    if (max < tableau[i]) max = tableau[i];
  }

  return max;
}

void
TabEntier::Print(){
  if (taille < 20)
    {
      for (int i=0; i<taille; i++)
	cout << tableau[i] << " ";
      cout << endl;
    }
  else
    cout << "Trop d'elements" << endl;
}
