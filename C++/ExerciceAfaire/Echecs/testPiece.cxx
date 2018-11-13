/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare (const Piece & p, const Piece & q)
{
  return (p.x() == q.x()) && (p.y() == q.y());
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );

  Piece p2( 4, 4, false );

  if (p2.isBlack())
    cout << "Une Piece noire" << endl;

  // On l'affiche
  p1.affiche();
  p2.affiche();

  // p1 = p2; // interdit =delete

  if ( compare(p1, p2) )
    cout << "memes positions" << endl;
  else
    cout << "positions differentes" << endl;

  Echiquier e;
  //Joueur j(true); // classe abstraite
  JoueurBlanc jb;
  JoueurNoir jn;
  jb.placerPieces(e);
  jn.placerPieces(e);

  Roi rb( true );
  Roi rn( false );
  Reine qb( true );
  Reine qn( false );
  Fou fbg(true, true);
  Fou fbd(true, false);
  Fou fng(false, true);
  Fou fnd(false, false);
  Tour tbg(true, true);
  Tour tbd(true, false);
  Tour tng(false, true);
  Tour tnd(false, false);

  Piece *ptr = nullptr;
  ptr = e.enleverPiece(5, 1);
  e.placer(&rb);
  ptr = e.enleverPiece(5, 8);
  e.placer(&rn);
  ptr = e.enleverPiece(4, 1);
  e.placer(&qb);
  ptr = e.enleverPiece(4, 8);
  e.placer(&qn);
  ptr = e.enleverPiece(3, 1);
  e.placer(&fbg);
  ptr = e.enleverPiece(6, 1);
  e.placer(&fbd);
  ptr = e.enleverPiece(3, 8);
  e.placer(&fng);
  ptr = e.enleverPiece(6, 8);
  e.placer(&fnd);
  ptr = e.enleverPiece(1, 1);
  e.placer(&tbg);
  ptr = e.enleverPiece(8, 1);
  e.placer(&tbd);
  ptr = e.enleverPiece(1, 8);
  e.placer(&tng);
  ptr = e.enleverPiece(8, 8);
  e.placer(&tnd);

  e.affiche();

  // polymorphisme
  qb.mouvementValide(e, 1, 1);
  ptr = &qb;
  ptr->mouvementValide(e, 1, 1);

  // transtypage
  ptr = &rb;
  Roi *rptr = dynamic_cast<Roi *>(ptr);
  Reine *qptr = dynamic_cast<Reine *>(ptr);
  assert(nullptr != rptr);
  assert(nullptr == qptr);

  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1
  return 0;
}
