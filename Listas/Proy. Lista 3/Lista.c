#include <iostream>
using namespace std;

#include "Nodo.h"
#include "Lista.h"

void Lista::inserIniLis(Dato entrada)
{
     Nodo* nuevo;
     nuevo = new Nodo(entrada);
     nuevo -> ponerEnlace(primero);
     primero = nuevo;
}

void Lista::inserUltLis(Dato entrada)
{
     Nodo* ultimo = this -> ultimo();
     ultimo -> ponerEnlace(new Nodo(entrada));
}

Nodo* Lista::ultimo()
{
      Nodo* p = primero;
      if(p==NULL)
            throw "ERROR, lista vacia";
      while(p -> enlaceNodo() != NULL)
            p = p -> enlaceNodo();
      
      return p;
}

void Lista::inserDentLis(Dato entrada, Nodo* anterior)
{
     Nodo* nuevo;
     
     nuevo = new Nodo(entrada);
     nuevo -> ponerEnlace(anterior -> enlaceNodo());
     anterior -> ponerEnlace(nuevo);
}

void Lista::visualizarList()
{
     Nodo* n;
     int k=0;
     n = primero;
     while (n != NULL)
     {
           char c;
           k++;
           c = (k%15 != 0 ? ' ':'\n');
           cout << n -> datoNodo() << c;
     }
}
