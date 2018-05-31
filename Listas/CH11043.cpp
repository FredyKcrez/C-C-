/*Con memoria dinamica:
"Crear una funcion cuadrado, la cual recorre un lista doblemente enlazada
y eleva los elementos de esta al cuadrado"

1)Inicialice la lista con 10 datos
2) Muestre los datos
3) Ejeculte la funcion
4) Muestre los datos*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define ASCENDENTE 1
#define DESCENDENTE 0
#define TRUE 1
#define FALSE 0
#define n 10

typedef struct _nodo {/*definicion de la estructura lista doblementes enlazada con datos enteros*/
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
void Cuadrado (Lista l);

int main(void)
{
    Lista lista = NULL;
    pNodo p;
    int i=3, v, i2;
    puts("Se creo un funcion que permite elevar los elementos al cuadrado \nde una lista doblemente enlazada!!!\n\n");
    for(i2=0;i2<n;i2++)
    Insertar(&lista,i++);/*inicializacion de laista con los 10 elementos*/
    MostrarLista(lista,ASCENDENTE);/*muestra la lista con los 10 elemento iniciales*/
    Cuadrado(lista);/*Se ejecuta la funcion cuadrado 10 veces para elevar cada uno de los elementos de la lista al cuadrado*/
    MostrarLista(lista,ASCENDENTE);/*Muestra la lista con los elementos al cuadrado*/
    
    BorrarLista(&lista);/* Liberar toda la memoria utilizada */
    getch();
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

void Borrar(Lista *lista, int v) {
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
        printf("Orden ascendente: ");
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

void Cuadrado (Lista lista)/*Esta funcion recorre la lista y los elementos los eleva al cuadrado*/
{
     pNodo nodo = lista;
     int num;
    if(!lista)
    printf("Lista vacía");
    nodo = lista;
        while(nodo->anterior)
        nodo = nodo->anterior;
        while(nodo)
        {
        num = (nodo->valor)*(nodo->valor);/*Eleva el elemento del nodo al cuadrado, mutliplicando el valor por si mismo*/
        nodo->valor = num;
        nodo = nodo->siguiente;
        }   
    
}
