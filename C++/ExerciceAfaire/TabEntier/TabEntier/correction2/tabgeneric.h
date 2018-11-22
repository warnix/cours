template <class X=int, class T=int>
class TabGeneric
 {
 private:
   T *tableau;
   X taille;
 public:
   TabGeneric(X nbelem);
   ~TabGeneric();
   T  operator[](const X i);
   void Print();
   void Remplir();
   T  Max();
};


