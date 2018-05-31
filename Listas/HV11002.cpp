#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define ASCENDENTE 1
#define DESCENDENTE 0
#define TRUE 1
#define FALSE 0

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
pNodo getnodo(void);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);
pNodo buscar_nodo( Lista, int, int *);
void menu(void);
int cuadrado(Lista lista, int orden);

main()   {                                  //Principal
   Lista lista = NULL;
   pNodo p;
   int opcion, v, enc, cont=TRUE, i;

   for(i=1; i<=10; i++) //Inicializando nodos
   {
            Insertar(&lista, i);
   }
   MostrarLista(lista, 1);  //Muestra 1ra vez
   printf("\n Elevando datos al cuadrado\n\n");
   cuadrado(lista,1);        //Eleva al cuadrado
   MostrarLista(lista, 1);           //Muestra 2da vez
   getch();
}

int cuadrado(Lista lista, int orden)  //Funcion que eleva al cuadrado los datos de un nodo
{
    pNodo nodo = lista;

   if(!lista) printf("Lista vacía");

   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      while(nodo) {
	 nodo->valor=(int)pow(nodo->valor, 2);
	 nodo = nodo->siguiente;
      }
}
}


void Insertar(Lista *lista, int v)
{
   pNodo nuevo, actual;

   /* pedir un nodo nuevo */
   nuevo = getnodo();

   nuevo->valor = v;

   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;

   /* Si la lista está vacía o el primer miembro es mayor que el nuevo*/
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
	 un valor mayor que v */
      while(actual->siguiente && actual->siguiente->valor <= v)
	 actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void Borrar(Lista *lista, int v)   {
   pNodo nodo;

   /* Buscar el nodo de valor v */
   nodo = *lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v) return;

   /* Borrar el nodo */
   /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if(nodo == *lista)
     if(nodo->anterior) *lista = nodo->anterior;
     else *lista = nodo->siguiente;

   if(nodo->anterior) /* no es el primer elemento */
      nodo->anterior->siguiente = nodo->siguiente;

   if(nodo->siguiente) /* no es el último nodo */
      nodo->siguiente->anterior = nodo->anterior;
   free(nodo);
}

void BorrarLista(Lista *lista)
{
   pNodo nodo, actual;

   actual = *lista;
   while(actual->anterior) actual = actual->anterior;

   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      free(nodo);
   }
   *lista = NULL;
}

void MostrarLista(Lista lista, int orden)
{
   pNodo nodo = lista;

   if(!lista) printf("Lista vacía");

   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      printf("Datos: ");
      while(nodo) {
	 printf("%d -> ", nodo->valor);
	 nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      printf("Orden descendente: ");
      while(nodo) {
	 printf("%d -> ", nodo->valor);
	 nodo = nodo->anterior;
      }
   }

   printf("\n");
}

pNodo getnodo(void) {
   pNodo nuevo;


   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   return nuevo;
}

pNodo buscar_nodo( Lista lista, int v, int *enc ) {
   pNodo nodo;

   /* Buscar el nodo de valor v */
   nodo = lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v)
      *enc = FALSE;            /* devolver a través de enc si v fue encontrado en la lista */
   else
      *enc = TRUE ;

   /* devolver el apuntador al nodo */
   return nodo;
}

void menu(void)
{
   printf("\n------------------------------------------------\n");
   printf("----------------- M E N U ----------------------\n");
   printf("------------------------------------------------\n");
   printf("1. Introducir un elemento en la lista.\n");
   printf("2. Borrar un elemento de la lista.\n");
   printf("3. Buscar un elemento en la lista.\n");
   printf("4. Imprimir la lista en forma ASCENDENTE\n");
   printf("5. Imprimir la lista en forma DESCENDENTE\n");
   printf("6. Salir. \n");
}
