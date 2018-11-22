/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include <vector>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;
/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Joueur
{
private:
  //Piece m_pieces[16];
  vector<Piece*> m_pieces;

public:
  Joueur( bool white );
  void placerPieces(Echiquier & e);
  void affiche();
  virtual bool isWhite() const =0;
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
