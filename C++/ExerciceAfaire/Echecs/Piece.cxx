/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include "Piece.h"
#include <iostream> // pour l'affichage

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

Piece::Piece()
{
  //cout << "une piece construite par défaut" << endl;
}

Piece::~Piece()
{
  //cout << "une piece détruite" << endl;
}

Piece::Piece(int x, int y, bool white)
{
  //cout << "une piece construite" << endl;
  init(x, y, white);
}

Piece::Piece(const Piece &autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "une piece construite par défaut" << endl;
}

Roi::Roi(bool white) : Piece(5, white ? 1 : 8, white)
{
  cout << "Un Roi construit" << endl;
}
Reine::Reine(bool white) : Piece(4, white ? 1 : 8, white)
{
  cout << "Une Reine construite" << endl;
}

Piece &
Piece::operator=(const Piece &autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "une piece affectée" << endl;
  return *this;
}

void Piece::init(int x, int y, bool white)
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void Piece::move(int x, int y)
{
  m_x = x;
  m_y = y;
}

int Piece::x() const
{
  return m_x;
}

int Piece::y() const
{
  return m_y;
}

bool Piece::isWhite() const
{
  return m_white;
}

bool Piece::isBlack() const
{
  return !m_white;
}

void Piece::affiche() const
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << (m_white ? "blanche" : "noire") << endl;
}

bool Piece::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvement valide de pièce" << endl;

  return false;
}
bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Roi" << endl;
  return false;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Reine" << endl;
  return false;
}
char
Piece::getChar() const
{
  return m_white ? 'B' : 'N';
}

char
Roi::getChar() const
{
  return m_white ? 'R' : 'r';
}

char
Reine::getChar() const
{
  return m_white ? 'Q' : 'q';
}
