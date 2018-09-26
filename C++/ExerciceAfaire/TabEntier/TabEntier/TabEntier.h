#ifndef TABENTIER_H
#define TABENTIER_H

class TabEntier
 {
 private:
   int *tableau;
   int taille;
 public:
   TabEntier(int nbelem);
   ~TabEntier();
   int  operator[](const int i);
   void Print();
   void Remplir();
   int  Max();
};

#endif
