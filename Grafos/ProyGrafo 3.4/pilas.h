#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int ElementoPila;
int tamano_pila = 0;

typedef struct nodo 
{
        ElementoPila vertice;
        struct nodo *siguiente;
}tiponodo;

typedef tiponodo *pNodo;

typedef struct pila
{
        pNodo ultimo;
        int tamano_pila;
}Pila;        

//typedef tiponodo *Pila;

//Prototipo de funciones
int empty(Pila *);
ElementoPila pop(Pila *);
void push(Pila *, ElementoPila);
ElementoPila UltimoP(Pila *);
void inicializarPila(Pila *);

//Definicion de la funciones
void inicializarPila(Pila *ps)
{
     ps->tamano_pila = 0;
     ps->ultimo = NULL;
}

int empty(Pila *ps)
{
    return ((ps)->tamano_pila == 0);
}

void push(Pila *ps, ElementoPila a)
{
     pNodo nuevo;
     nuevo = (pNodo) malloc(sizeof(tiponodo));
     if (nuevo != NULL)
     {
        nuevo->vertice = a;
        nuevo->siguiente = ps->ultimo;
        ps->ultimo = nuevo;
        ps->tamano_pila++;
     }
     else
     printf("\nNo se pudo insertar el elemento. Falta de memoria\n");
}

ElementoPila UltimoP(Pila *ps)
{
     ElementoPila valor;
     valor = (ps)->ultimo->vertice;
     return valor;
}

ElementoPila pop(Pila *ps)
{
     pNodo temp;
     ElementoPila popvalue;
     temp = ps->ultimo;
     popvalue = (ps)->ultimo->vertice;
     ps->ultimo = (ps)->ultimo->siguiente;
     free(temp);
     ps->tamano_pila--;
     return popvalue;
}

void MostrarPila (Pila *pila , char *nombrePila)
{
     int i = 0;
     int aux;
     /* Generando una pila auxiliar para copiar los contenidos */
     Pila *pilaAuxiliar;
     pilaAuxiliar=(Pila *)malloc(sizeof(Pila));
     printf("\n\n\n\n\tบบบบบบบบบบบบบบบบบบบบบบบบบ\n");
     printf("\n\tDatos de la pila %s\n",nombrePila);
     printf("\n\t    VERTICE\n\n");
     
     int tamano = pila->tamano_pila;
     for ( i = 0 ; i < tamano ; i++ )
     {
         aux=pop(pila);
         push(pilaAuxiliar, aux);
         printf("\t%i-    %d",(tamano)-i,aux);
         printf("\n");
     }
     printf("\n\n\tบบบบบบบบบบบบบบบบบบบบบบบบบ");
     for ( i = 0 ; i < tamano ; i++ )
     {
         aux=pop(pilaAuxiliar);
         push(pila, aux);
     }     
}                        
