template <class T>
class TabGeneric
 {
 private:
   T *tableau;
   int taille;
 public:
   TabGeneric(int nbelem);
   ~TabGeneric();
   T  operator[](const int i);
   void Print();
   void Remplir();
   T  Max();
};


