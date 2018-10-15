/** 
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cxx
 */

// A besoin de la declaration de la classe
#include "Joueur.h"
#include <iostream> // pour l'affichage

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

Joueur::Joueur(bool white)
{
  int p = 0;
  int y = (white) ? 1 : 8;
  for (int x = 1; x <= 8; x++)
  {
    m_piece[p++].init(x, y, white);
  }
  y = (white) ? 2 : 7;
  for (int x = 1; x <= 8; x++)
  {
    m_piece[p++].init(x, y, white);
  }
}

void Joueur::affiche()
{
  for (int i = 0; i < 16; i++)
  {
    m_piece[i].affiche();
  }
}

void Joueur::placerPiece(Echiquier &e)
{
  for (int i = 0; i < 16; i++)
  {
    e.placer(m_piece + i);
  }
}

JoueurBlanc::JoueurBlanc() : Joueur(true){
}
JoueurNoir::JoueurNoir() : Joueur(false){
}
bool JoueurBlanc::isWhite() const{
  return true;
}
bool JoueurNoir::isWhite() const{
  return false;
}
