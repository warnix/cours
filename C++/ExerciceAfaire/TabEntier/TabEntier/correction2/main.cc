#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "tabgeneric.h"

using namespace std;

#define MAX_TAB 1000

int main(int argc, const char* argv[]) {
  int nbelem;

  /* Il faut au moins un parametre pour executer le programme */
  if (argc < 2) {
    cout << "Usage :" << argv[0] << " <nombre d'element>" << endl;
    return 1;
  }
  
  /* On recopere le nombre d'elements */
  nbelem = atoi(argv[1]);

  /* Allocation du tableau */
  TabGeneric<long, char> tableau(nbelem);
  char max;

  /* On remplit le tableau */
  tableau.Remplir();

  /* On recherche le maximum */
  max = tableau.Max();

  /* On affiche le tableau */
  tableau.Print();

  /* On affiche le résultat */
  cout << "Max : " << max << endl;

  return 0;
} 
