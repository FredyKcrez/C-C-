/*Implementacion de cola con memoria dinamica */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct _nodocola{
       int vertice;// para todos los vertices del grafo
       struct _nodocola *sig ;
       };

typedef struct _nodocola NodoCola ;//estamos creando un sinonimo, es una forma de referirme a la estructura de forma corta

typedef struct {//definimos una estructura de tipo de datos
	NodoCola *Frente, *Final;
	}Cola;

void VaciaC(Cola *C) {
     C->Frente = NULL ;
     C->Final = NULL ;
     } // void VaciaC

int EsVaciaC(Cola C) {//me comprueba si esta vacia
    return (C.Frente == NULL ) ;
    } // int EsVaciaC

void AnadeC(Cola *C, int nodo) {
     NodoCola *a;
     a = (NodoCola*)malloc(sizeof(NodoCola));//para asiganrle espacio a la memoria Ram
     a->vertice = nodo;
     a->sig = NULL;// esta a se pierde
     if (EsVaciaC(*C))
	    C->Frente = a;//los 2 tan apuntado al msmo lugar
     else
	    C->Final->sig = a;
        C->Final = a;
     } // void AnadeC

void BorraC(Cola *C) {
     NodoCola *a ;
     if (!EsVaciaC(*C)) {
	    a = C->Frente ;
	    C->Frente = C->Frente->sig ;
	    if (C->Frente == NULL)
	        C->Final = NULL ;
	    free(a);
	    }
     else {
	    puts("Error Eliminacion de una Cola Vacia") ;
	    exit(-1) ;
	    }
     } // void BorraC

NodoCola PrimeroC(Cola C) {
     NodoCola *a;
     a = (NodoCola*)malloc(sizeof(NodoCola));
     if (EsVaciaC(C)) {
	    puts("Error: Cola Vacia") ;
	    exit(-1) ;
	    }
     else 
     a->vertice = C.Frente->vertice;
           
     return *a;
     } //PrimeroC

void MostrarCola(Cola *C) {
     /* Muestra los elementos de una cola 
        que se le pase como parametro */
     NodoCola a, b;
     Cola Aux;
     VaciaC(&Aux);
     while (!EsVaciaC(*C)) {
           a = PrimeroC(*C);
           int vertice = a.vertice;
           AnadeC(&Aux,vertice);
           printf("\t%d", a.vertice);
           printf("\n\n");
           BorraC(C) ;
           } // while
      while (!EsVaciaC(Aux)) {
           b = PrimeroC(Aux);
           int vertic = b.vertice; 
           AnadeC(C,vertic);
           BorraC(&Aux) ;
           } // while
     } // void MostrarCola


