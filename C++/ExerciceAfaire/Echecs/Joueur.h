/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
/**
 * Declaration d'une classe mod�lisant un Joueur de jeu d'echec.
 */
class Joueur 
{
private:
  Piece m_piece[16]; 
  bool couleur;
public:
  Joueur(bool couleur);
  void affiche();
}; 

#endif // !defined Joueur_h
