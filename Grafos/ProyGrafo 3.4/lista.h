#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoLista {
		int NodoPartida;
		int NodoDestino;
		int Costo;
		struct ElementoLista *siguiente;
}Element;

typedef struct ListaIdentificar {
		Element *inicio;
		Element *fin;
		int tamano;
}Lista;

void inicializacion (Lista *lista){
		lista->inicio = NULL;
		lista->fin = NULL;
		lista->tamano = 0;
}

/* inserción en una lista vacía */
int ins_en_lista_vacia (Lista *lista, int a, int b, int c){
  Element *nuevo_elemento;
  if ((nuevo_elemento = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
  nuevo_elemento->NodoPartida = a;
  nuevo_elemento->NodoDestino = b;
  nuevo_elemento->Costo = c;
  nuevo_elemento->siguiente = NULL;
  lista->inicio = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamano++;
  return 0;
}

/* comprobar si esta vacia la lista*/
int es_vacia(Lista *lista){
    if(lista->inicio == NULL)
    return 1;
    else
    return 0;
}

/* inserción al inicio de la lista */
int ins_inicio_lista (Lista *lista, int a, int b, int c){
  Element *nuevo_elemento;
  if ((nuevo_elemento = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
  nuevo_elemento->NodoPartida = a;
  nuevo_elemento->NodoDestino = b;
  nuevo_elemento->Costo = c;

  nuevo_elemento->siguiente = lista->inicio;
  lista->inicio = nuevo_elemento;
  lista->tamano++;
  return 0;
}

/*inserción al final de la lista */
int ins_fin_lista (Lista *lista, Element *actual, int a, int b, int c){
  Element *nuevo_elemento;
  if ((nuevo_elemento = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
  nuevo_elemento->NodoPartida = a;
  nuevo_elemento->NodoDestino = b;
  nuevo_elemento->Costo = c;

  actual->siguiente = nuevo_elemento;
  nuevo_elemento->siguiente = NULL;

  lista->fin = nuevo_elemento;

  lista->tamano++;
  return 0;
}

/* inserción en la posición solicitada */
int ins_lista (Lista * lista, int a, int b, int c, int pos){
  if (lista->tamano < 2)
    return -1;
  if (pos < 1 || pos >= lista->tamano)
    return -1;

  Element *actual;
  Element *nuevo_elemento;
  int i;

  if ((nuevo_elemento = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;

  actual = lista->inicio;
  for (i = 1; i < pos; ++i)
    actual = actual->siguiente;
  if (actual->siguiente == NULL)
    return -1;
  nuevo_elemento->NodoPartida = a;
  nuevo_elemento->NodoDestino = b;
  nuevo_elemento->Costo = c;

  nuevo_elemento->siguiente = actual->siguiente;
  actual->siguiente = nuevo_elemento;
  lista->tamano++;
  return 0;
}

/* eliminación al inicio de la lista */
int sup_inicio (Lista * lista){
  if (lista->tamano == 0)
    return -1;
  Element *sup_elemento;
  sup_elemento = lista->inicio;
  lista->inicio = lista->inicio->siguiente;
  if (lista->tamano == 1)
    lista->fin = NULL;
  free (sup_elemento);
  lista->tamano--;
  return 0;
}

/* eliminar un elemento después de la posición solicitada */
int sup_en_lista (Lista * lista, int pos){
  if (lista->tamano <= 1 || pos < 1 || pos >= lista->tamano)
    return -1;
  int i;
  Element *actual;
  Element *sup_elemento;
  actual = lista->inicio;

  for (i = 1; i < pos; ++i)
    actual = actual->siguiente;

  sup_elemento = actual->siguiente;
  actual->siguiente = actual->siguiente->siguiente;
  if(actual->siguiente == NULL)
          lista->fin = actual;
  free (sup_elemento);
  lista->tamano--;
  return 0;
}

/* visualización de la lista */
void mostrar (Lista * lista){
  Element *actual;
  int contador=0;
  actual = lista->inicio;
  if(actual==NULL)
  printf("\nLista Vacia");
  printf("\t");
  while (actual != NULL){
           contador++;
           if(actual->NodoPartida == 0)printf("A");
           if(actual->NodoDestino == 0)printf("A");
           if(actual->NodoPartida == 1)printf("B");
           if(actual->NodoDestino == 1)printf("B");
           if(actual->NodoPartida == 2)printf("C");
           if(actual->NodoDestino == 2)printf("C");
           if(actual->NodoPartida == 3)printf("D");
           if(actual->NodoDestino == 3)printf("D");
           if(actual->NodoPartida == 4)printf("E");
           if(actual->NodoDestino == 4)printf("E");
           if(actual->NodoPartida == 5)printf("F");
           if(actual->NodoDestino == 5)printf("F");  
           printf("%d ",actual->Costo);
           if(actual->siguiente != NULL)
           printf("-> ");
           actual = actual->siguiente;
           if(contador%10 == 0)
           printf("\n\t");
  }
  printf("\n");
}

/* destruir la lista */
void destruir (Lista * lista){
  while (lista->tamano > 0)
    sup_inicio (lista);
}

