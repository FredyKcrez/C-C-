#ifndef NODO_H
#define NODO_H
#define TipoDato int
#include <iostream>
 
using namespace std;
//template <class T>
class Nodo
{
   public:
   TipoDato dato;
   Nodo *sgte;
   Nodo();
   Nodo(TipoDato);
   ~Nodo();

   void print();
   void eliminar();
};
 
#endif // NODO_H
