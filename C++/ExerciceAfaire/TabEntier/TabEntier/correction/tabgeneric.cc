#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "tabgeneric.h"

using namespace std;

#define MAX_TAB 1000

template <class T>
TabGeneric<T>::TabGeneric(int nbelem){
  taille = nbelem;
  tableau = new T[taille];
}

template <class T>
TabGeneric<T>::~TabGeneric(){
  delete[] tableau;
}

template <class T>
T
TabGeneric<T>::operator[](const int i){
  return tableau[i];
}

template <class T>
void
TabGeneric<T>::Remplir(){
  int i;

  /* On initialise la fonction de generation de nombre aleatoire */
  srand((unsigned)time(NULL));

  /* On remplit le tableau aleatoirement */
  for (i=0; i<taille; i++)
    tableau[i] = (T)(rand()%MAX_TAB - MAX_TAB / 3.0);

}

template <class T>
T
TabGeneric<T>::Max(){
  int i;
  T max;

  /* On initialise max a la valeur du premier element du tableau */
  max = tableau[0];

  /* On parcours le tableau à la recherche d'un plus grand élément que max */
  for(i = 1 ; i<taille; i++) {
    if (max < tableau[i]) max = tableau[i];
  }

  return max;
}

template <class T>
void
TabGeneric<T>::Print(){
  if (taille < 20)
    {
      for (int i=0; i<taille; i++)
	cout << tableau[i] << " ";
      cout << endl;
    }
  else
    cout << "Trop d'elements" << endl;
}

template class TabGeneric<int>;
template class TabGeneric<double>;
template class TabGeneric<char>;
