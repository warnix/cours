#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "tabgeneric.h"

using namespace std;

#define MAX_TAB 1000

template <class X, class T>
TabGeneric<X,T>::TabGeneric(X nbelem){
  taille = nbelem;
  tableau = new T[taille];
}

template <class X, class T>
TabGeneric<X,T>::~TabGeneric(){
  delete[] tableau;
}

template <class X, class T>
T
TabGeneric<X,T>::operator[](const X i){
  return tableau[i];
}

template <class X, class T>
void
TabGeneric<X,T>::Remplir(){
  X i;

  /* On initialise la fonction de generation de nombre aleatoire */
  srand((unsigned)time(NULL));

  /* On remplit le tableau aleatoirement */
  for (i=0; i<taille; i++)
    tableau[i] = (T)(rand()%24+'a'); //(rand()%MAX_TAB - MAX_TAB / 2.1);

}

template <class X, class T>
T
TabGeneric<X,T>::Max(){
  X i;
  T max;

  /* On initialise max a la valeur du premier element du tableau */
  max = tableau[0];

  /* On parcours le tableau à la recherche d'un plus grand élément que max */
  for(i = 1 ; i<taille; i++) {
    if (max < tableau[i]) max = tableau[i];
  }

  return max;
}

template <class X, class T>
void
TabGeneric<X,T>::Print(){
  if (taille < 20)
    {
      for (X i=0; i<taille; i++)
	cout << tableau[i] << " ";
      cout << endl;
    }
  else
    cout << "Trop d'elements" << endl;
}

template class TabGeneric<long,int>;
template class TabGeneric<long,double>;
template class TabGeneric<long,char>;
