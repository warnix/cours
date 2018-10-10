/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(const Piece &p, const Piece &q)
{
  cout << "comparaison de deux pièce" << endl;
  return (p.x() == q.x()) && (p.y() == q.y());
}

/**
 * Programme principal
 */
int main(int argc, char **argv)
{
  /*
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init(3, 3, true);
  // instancie une Piece p2 noir de coordonnees (4,4)
  Piece p2 = Piece(4, 4, false);
  Piece p3 = p2;
  //test si une piece est bien noir
  assert(p2.isBlack());

  // On affiche
  p1.affiche();
  p2.affiche();

  // travail sur les passages par référence constante
  assert(!compare(p1, p2));
  assert(compare(p2, p3));
  
  //affichage de leurs pions
  jb.affiche();
  jn.affiche(); 
  */

  Echiquier e;
  //création de deux joueurs
  Joueur jb = Joueur(true);
  Joueur jn = Joueur(false);
  jb.placerPiece(e);
  jn.placerPiece(e);
  e.affiche();

  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1, p2
  return 0;
}
