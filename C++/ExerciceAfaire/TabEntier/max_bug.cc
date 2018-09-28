#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#define MAX_TAB 1000

int RemplirTableau(int *tableau, int nbelem){
  int i;

  /* On initialise la fonction de generation de nombre aleatoire */
  srand((unsigned)time(NULL));

  /* On remplit le tableau aleatoirement */
  for (i=0; i<nbelem; i++)
    tableau[i] = (rand()%MAX_TAB - MAX_TAB / 2);

  return 1;
}

int RechercheMax(int * tableau, int nbelem){
  int i, max;

  /* On initialise max a la valeur du premier element du tableau */
  max = tableau[0];

  /* On parcours le tableau à la recherche d'un plus grand élément que max */
  for(i = 1 ; i=nbelem; i++) {
    if (max < tableau[i]) max = tableau[i];
  }

  return max;
}


int main(int argc, const char* argv[]) {
  int max, nbelem;
  int* tableau;

  /* Il faut au moins un parametre pour executer le programme */
  if (argc < 2) {
    cout << "Usage :" << argv[0] << " <nombre d'element>" << endl;
    return 1;
  }
  
  /* On recopere le nombre d'elements */
  nbelem = atoi(argv[1]);

  /* Allocation du tableau */
  tableau = new int[nbelem];

  /* On remplit le tableau */
  RemplirTableau(tableau, nbelem);

  /* On recherche le maximum */
  max = RechercheMax(tableau, nbelem);

  /* On affiche le tableau */
  if (nbelem < 20)
    {
      for (int i=0; i<nbelem; i++)
	cout << tableau[i] << " ";
      cout << endl;
    }

  /* On affiche le résultat */
  cout << "Max : " << max << endl;

  return 0;
} 
