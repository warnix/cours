/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece()
{
  cout << "Une Piece construite par defaut" << endl;
  // ne fait rien => objet instancie mais non valide.
}

Piece::~Piece()
{
  cout << "Une Piece detruite" << endl;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  cout << "Une Piece construite" << endl;
}

Roi::Roi( bool white ) : Piece(5, white?1:8, white)
{
  cout << "Un Roi construit" << endl;
}

Fou::Fou( bool white, bool gauche ) : Piece(gauche?3:6, white?1:8, white)
{
  cout << "Un Fou construit" << endl;
}

Tour::Tour( bool white, bool gauche ) : Piece(gauche?1:8, white?1:8, white)
{
  cout << "Un Tour construit" << endl;
}

Reine::Reine( bool white ) :  Piece(4,white?1:8,white),
                              Fou(white,true), Tour(white,true)
{
  cout << "Une Reine construite" << endl;
}

/*
Piece::Piece(const Piece &autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Une Piece construite par copie" << endl;
}
*/

/*
Piece &
Piece::operator=(const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Une Piece affectee" << endl;
  return *this;
}
*/

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Piece" << endl;
  return false;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Roi" << endl;
  return false;
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Fou" << endl;
  return false;
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Tour" << endl;
  return false;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  return Tour::mouvementValide(e, x, y) ||
         Fou::mouvementValide(e, x, y);
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack() const
{
  return !m_white;
}

void
Piece::affiche() const
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
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
Fou::getChar() const
{
  return m_white ? 'F' : 'f';
}

char
Tour::getChar() const
{
  return m_white ? 'T' : 't';
}

char
Reine::getChar() const
{
  return m_white ? 'Q' : 'q';
}