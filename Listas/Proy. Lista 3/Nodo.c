#include "Nodo.h"

Dato Nodo::datoNodo() const
{
      return dato;
}

Nodo* Nodo::enlaceNodo() const
{
      return enlace;
}

void Nodo::ponerEnlace(Nodo* sgte)
{
     enlace = sgte;
}
