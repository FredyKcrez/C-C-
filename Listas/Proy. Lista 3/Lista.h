typedef int Dato;

#include "Nodo.h"

class Lista
{
      protected:
                Nodo* primero;
      public:
             Lista()
             {
                    primero = NULL;
             }

             Lista(Nodo* one)
             {
                    primero = one;
             }

             void inserIniLis(Dato entrada);
             void inserUltLis(Dato entrada);
             void inserDentLis(Dato entrada, Nodo* anterior);
             Nodo* ultimo();
             void visualizarList();
};
