/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h
#include "Echiquier.h"
#include "Piece.h"
/**
 * Declaration d'une classe mod�lisant un Joueur de jeu d'echec.
 */
class Joueur
{
private:
  Piece m_piece[16];

public:
  Joueur(bool white);
  void affiche();
  void placerPiece(Echiquier &e);
  virtual bool isWhite() const = 0;
};
class JoueurBlanc : public Joueur
{
public:
  JoueurBlanc();
  bool isWhite() const;
};
class JoueurNoir : public Joueur
{
public:
  JoueurNoir();
  bool isWhite() const;
};

#endif // !defined Joueur_h
