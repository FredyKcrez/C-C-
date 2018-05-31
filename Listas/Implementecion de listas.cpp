/*IMPLEMENTACIÓN LISTAS ESTATICAS <------------------------------------------------------------------------*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define NumNode 10
#define TRUE 1
#define FALSE 0
 
struct nodetype {
   char info[30];
   int next;
   };

main(void) 
{
	struct nodetype node[NumNode];
	int avail=0;    /*inicializacion de lista de  
						nodos disponible avail a 0 */
 
	int i, r, enc;
	int paises=-1, herramientas=-1, alumnos=-1;
	char pais[30];
	char herra[30];
	char alum[30];
	 	int salir=FALSE,opcion;
 	/*inicializacion del arreglo de nodos */
  	for (i=0; i<NumNode-1; i++)
  	{
    			strcpy(node[i].info," ");
     		node[i].next=i+1;
  	}
  	strcpy(node[NumNode-1].info," ");
  	node[NumNode-1].next = -1;
  	…..
  	getch();
  	return 0;
}
int getnode ( void)
{
		int p;
		if ( avail== -1)
		{
			printf (“overflow\n”);
			exit (1);
		}
		p= avail ;
		avail= node [avail].next;
		return   (p);
}
void freenode ( int p)
{
		node[p].next=avail;
		avail=p;
}

//Insertar y elminar despues de un nodo conocido
void insafter (int p, int x )
{
    int q ;
	if (p== -1)
	{
			prinf (“fallo la inserción \n”)
			return ();
	}
	q= getnode ();
	node[q].info =x;
	node[q].next =node[p].next;
	node[p].next =q;
	return ;
}
void delafter (int p, int *px)
{
	int q;
    if ((p==-1)|| node[p].next==-1){
		  printf (“fallo eliminación \n”)
		  return ;
	}
	q= node [p].next;
	*px= node [q].info;
	node[p].next= node [q].next;
	freenode (q);
    return;
} /* fin de desafter*/


/*IMPLEMENTACIÓN LISTAS DINAMICAS UNIDIRECCIONALES <-----------------------------------------------------*/
struct node {		/* Definición del tipo de dato para un Nodo */
			int info;
			struct node *next;
	}
	typedef struct node *nodeptr; 	/* Definición del tipo de dato para un puntero a un nodo */

	nodeptr p;			/* Declaración de un puntero a un Nodo */

	p= getnode ();	/* Asignar una dirección de memoria válida de un nodo vacío a un puntero */
nodeptr  getnode (void){		
nodeptr p;
	p= (nodeptr)malloc (sizeof(struct node));	/*Obtener dirección
							y espacio de memoria para un nodo vacío*/
	return ( p);
}

freenode (p)		/*Liberar espacio de memoria de un nodo*/


void  freenode(nodeptr p){		/*Liberar nodo*/ 	
	free (p);
}
void insafter (nodeptr p, int x){	/*insertar nodo q 
												después de nodo p*/
		nodeptr q;
		if (p== NULL){
			printf (“fallo inserción \n”);
			exit (1)
		}
	q= getnode ( );
	q->info= x;
	q->next= p->next;
	p->next=q;
}/* fin insafter */ 
void delafter (nodeptr p, int *px){	/*borrar nodo q después de nodo p, el dato se devuelve en puntero px*/

	nodeprt q;
	if ( (p==NULL)||(p-> next== NULL)){
			printf (“”fallo eliminación \n);
			exit (1);
	}
	q= p->next;
	*px= q->info;
	p->next= q->next;
	freenode (q);

}/* fin de delafter */ 

/*IMPLEMENTACIÓN LISTAS DINAMICAS BIDIRECCIONALES <-----------------------------------------------------*/
#include <stdlib.h>				 /* Librerías */
#include <stdio.h>
#include <conio.h>

#define ASCENDENTE 1		 /* Constantes */
#define DESCENDENTE 0
#define TRUE 1
#define FALSE 0

typedef struct _nodo {			 /* tipoNodo */
   int valor;
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;
typedef tipoNodo *pNodo;		 /* Puntero a un nodo */
typedef tipoNodo *Lista;		 /* Puntero a la lista */

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
pNodo getnodo(void);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);
pNodo buscar_nodo( Lista, int, int *);
pNodo buscar_nodo( Lista lista, int v, int *enc ) {
   pNodo nodo;
   /* Buscar el nodo de valor v */
   nodo = lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;
   /* El valor v no está en la lista */
   if (!nodo || nodo->valor != v)
      *enc = FALSE;            /* devolver a través de enc si v fue encontrado en la lista */
   else
      *enc = TRUE ;
   /* devolver el apuntador al nodo */
   return nodo;
} 
void Insertar(Lista *lista, int v)
{
   pNodo nuevo, actual;
   /* pedir un nodo nuevo */
   nuevo = getnodo();
   nuevo->valor = v;
   
	/* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if (actual) 			 /* si lista no vacìa */
			while (actual->anterior)
				actual = actual->anterior;
/* Si la lista está vacía o el primer miembro es mayor que el nuevo*/
    if (!actual || actual->valor > v)
	{
   		   	/* Añadimos la lista a continuación del nuevo nodo */
      	nuevo->siguiente = actual;
      	nuevo->anterior = NULL;

      	if (actual) 	/*si la lista no esta vacía*/
				actual->anterior = nuevo;

      	if (!*lista)	/*si la lista esta vacía*/
				*lista = nuevo;
   }
else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente 	tenga un valor mayor que v */
      while (actual->siguiente && actual->siguiente->valor <= v)
	 			actual = actual->siguiente;

      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;

      if	(nuevo->siguiente) 
			nuevo->siguiente->anterior = nuevo;
   		}
}
void Borrar(Lista *lista, int v)
{
   pNodo nodo;
   /* Buscar el nodo de valor v */
   nodo = *lista;
   while (nodo && nodo->valor < v)
			nodo = nodo->siguiente;
   while (nodo && nodo->valor > v)
			nodo = nodo->anterior;
   /* El valor v no está en la lista */
   if (!nodo || nodo->valor != v)
			return;			 /* se sale sin borrar */
   /* Sigue borrar el nodo */
	/* Borrar el nodo */
   /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if	(nodo == *lista)
     		if (nodo->anterior)	/* si existe un nodo anterior */
				*lista = nodo->anterior;
     		else 
				*lista = nodo->siguiente;

   if (nodo->anterior) 	/* no es el primer nodo */
      	nodo->anterior->siguiente = nodo->siguiente;

   if (nodo->siguiente) 	/* no es el último nodo */
      	nodo->siguiente->anterior = nodo->anterior;

   free(nodo);
}
void BorrarLista(Lista *lista)
{
   pNodo nodo, actual;
   actual = *lista;
	/* hacer que actual apunte al primer nodo */
   while (actual->anterior)
			actual = actual->anterior;
   while (actual)
	{
      	nodo = actual;
      	actual = actual->siguiente;
      	free(nodo);
   	}
   	*lista = NULL;
}
void MostrarLista(Lista lista, int orden)
{
   pNodo nodo = lista;
   if (!lista) 
		printf("Lista vacía");
   nodo = lista;
   if(orden == ASCENDENTE)
	{
      while(nodo->anterior) 	/* hacer que nodo apunte al inicio*/
			nodo = nodo->anterior;
      printf("Orden ascendente: ");
      while(nodo)
		{
	 		printf("%d -> ", nodo->valor);
	 		nodo = nodo->siguiente;
      }
   }
else 
	{
      while (nodo->siguiente) /* hacer que nodo apunte al fin */
				nodo = nodo->siguiente;
      printf("Orden descendente: ");
      while (nodo) 
		 {
	 		printf("%d -> ", nodo->valor);
	 		nodo = nodo->anterior;
      }
	}
 	printf("\n");
}
pNodo getnodo(void)
{
	   pNodo nuevo;
	   /* Crear un nodo nuevo y vacío*/
	   nuevo =(pNodo)malloc(sizeof(tipoNodo));
   		  return nuevo;
}

/*IMPLEMENTACIÓN LISTAS CIRCULARES BIDIRECCIONALES <-----------------------------------------------------*/
typedef struct celda {
   tElemento elemento;
   struct celda *siguiente,*anterior;
} tipocelda;
 
typedef tipocelda *tPosicion;
typedef tipocelda *tLista;static void error(char *cad)
{		/*Imprime la cadena de error enviada como parámetro, en la salida del error estándar: el monitor*/

   			fprintf(stderr, "ERROR: %s\n", cad);
   			exit(1);
}
tLista Crear( ) 
{	/*Crea nodo de cabecera, asigna su misma dirección en el siguiente y anterior de la cabecera*/
	 		tLista l;
   			l = (tLista)malloc(sizeof(tipocelda));
   			if (l == NULL)
			{
					Error("Memoria insuficiente.");
					exit (1);
			}
   			l->siguiente = l->anterior = l;
   			return l;
}
void Destruir (tLista l)
{	/* Elimina todos los nodos de la lista, incluyendo la cabecera*/
   tPosicion p;
 
   for (p=l, l->anterior->siguiente=NULL; l!=NULL; p=l)
	{
			l = l->siguiente;
			free(p);
   	}
}
tPosicion Primero (tLista l)
{	/* Retorna la dirección del siguiente a la cabecera */
	   return l->siguiente;
}

 
tPosicion Fin (tLista l)
{	/* Retorna la dirección de la cabecera */
	   return l;
}
void Insertar (tElemento x, tPosicion p, tLista l) 
{ /* Inserta un nodo antes del nodo en la posición p */
   tPosicion nuevo;
   nuevo = (tPosicion)malloc(sizeof(tipocelda));
   if (nuevo == NULL) 
	{
			Error("Memoria insuficiente.");
			exit (1);
	}
   nuevo->elemento = x;
   nuevo->siguiente = p;
   nuevo->anterior = p->anterior;
   p->anterior->siguiente = nuevo;
   p->anterior = nuevo;
}
void Borrar (tPosicion *p, tLista l)
{	/*Borra el nodo ubicado en la dirección p, y después p apunta a la posición del siguiente nodo*/
   tPosicion q;
   if (*p == l)
   { 
			Error("Posicion fin(l)");
			exit (1);
   }
   q = (*p)->siguiente;
   (*p)->anterior->siguiente = q;
   q->anterior = (*p)->anterior;
   free(*p);
   (*p) = q; 
}
tElemento elemento(tPosicion p, tLista l)
 {	/* Retorna el dato de nodo ubicado en la posición p, a menos que p sea la cabecera */
	   	if (p == l)
			{ 
				Error("Posición fin(l)");
  			}
   			return p->elemento;
}
tPosicion siguiente (tPosicion p, tLista l)
{	/* Devuelve la dirección del nodo siguiente a p */
   			if (p == l)
			{ 
				Error("Posicion fin(l)");
   			}
   			return p->siguiente;
}
tPosicion anterior( tPosicion p, tLista l)
{	/* Devuelve la dirección del nodo anterior a p */
   			if (p == l->siguiente)
			{
					Error("Posicion primero(l)");
   			}
   			return p->anterior;
}
tPosicion posicion (tElemento x, tLista l)
{		/* Devuelve la posición del elemento x en la lista l */
   tPosicion p;
   int encontrado;
	p = primero(l);
   encontrado = 0;
   while ((p != fin(l)) && (!encontrado))
			if (p->elemento == x)
					encontrado = 1;
			else
					p = p->siguiente;
   return p;	    /* Si no lo encontró, retorna la dirección del último nodo */
}
