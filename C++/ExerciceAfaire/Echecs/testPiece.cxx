/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );
  // instancie une Piece p2 noir de coordonnees (4,4)
  Piece p2 = Piece(4,4,false);

  //test si une piece est bien noir
  if (p2.isBlack())
    cout<<"une Piece noir"<<endl;

  // On affiche
  p1.affiche();
  p2.affiche();

  //création de deux joueurs
  Joueur jb = Joueur(true);
  Joueur jn = Joueur(false);

  jb.affiche();
  jn.affiche();
  
  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1, p2
  return 0;
}
