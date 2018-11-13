#include "Joueur.h"

Joueur::Joueur( bool white )
{
    int p = 0;
    int y = (white) ? 1 : 8;
    for (int x = 1; x <= 8; x++)
    {
        m_pieces[p].init(x, y, white);
        p++; // p=p+1 // p+=1
    }
    y = (white) ? 2 : 7;
    for (int x = 1; x <= 8; ++x)
        m_pieces[p++].init(x, y, white);
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
}

JoueurNoir::JoueurNoir() : Joueur(false)
{
}

void
Joueur::affiche()
{
    for (int i=0; i<16; i++)
        m_pieces[i].affiche();
}

void
Joueur::placerPieces(Echiquier & e)
{
    for (int i = 0; i < 16; i++)
        e.placer( m_pieces+i /*&(m_pieces[i])*/ );
}

bool
JoueurBlanc::isWhite() const
{
    return true;
}

bool
JoueurNoir::isWhite() const
{
    return false;
}