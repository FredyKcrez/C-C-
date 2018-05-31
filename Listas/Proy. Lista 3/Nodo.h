typedef int Dato;

#ifndef _NODO_H
#define _NODO_H
#include <stdlib.h>

class Nodo
{
      protected:
                Dato dato;
                Nodo* enlace;
      public:
             Nodo()         //Constructor vacio
             {
                    dato = 0;
                    enlace = NULL;
             }

             Nodo(Dato date)   //Constructor que solo recibe el dato a almacenar en el nodo
             {
                     dato = date;
                     enlace = NULL;
             }

             Nodo(Dato date, Nodo* link)  //Constructor que recibe el dato asi como la direccion
             {
                     dato = date;
                     enlace = link;
             }
             
             Dato datoNodo() const;
             Nodo* enlaceNodo() const;
             void ponerEnlace(Nodo* sgte);
};
#endif
