/*IMPLEMENTACI�N LISTAS ESTATICAS <------------------------------------------------------------------------*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define NumNode 10
#define TRUE 1
#define FALSE 0
�
struct nodetype {
   char info[30];
   int next;
   };

main(void) 
{
	struct nodetype node[NumNode];
	int avail=0;    /*inicializacion de lista de  
						nodos disponible avail a 0 */
�
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
  	�..
  	getch();
  	return 0;
}
int getnode ( void)
{
		int p;
		if ( avail== -1)
		{
			printf (�overflow\n�);
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
			prinf (�fallo la inserci�n \n�)
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
		  printf (�fallo eliminaci�n \n�)
		  return ;
	}
	q= node [p].next;
	*px= node [q].info;
	node[p].next= node [q].next;
	freenode (q);
    return;
} /* fin de desafter*/


/*IMPLEMENTACI�N LISTAS DINAMICAS UNIDIRECCIONALES <-----------------------------------------------------*/
struct node {		/* Definici�n del tipo de dato para un Nodo */
			int info;
			struct node *next;
	}
	typedef struct node *nodeptr; 	/* Definici�n del tipo de dato para un puntero a un nodo */

	nodeptr p;			/* Declaraci�n de un puntero a un Nodo */

	p= getnode ();	/* Asignar una direcci�n de memoria v�lida de un nodo vac�o a un puntero */
nodeptr  getnode (void){		
nodeptr p;
	p= (nodeptr)malloc (sizeof(struct node));	/*Obtener direcci�n
							y espacio de memoria para un nodo vac�o*/
	return ( p);
}

freenode (p)		/*Liberar espacio de memoria de un nodo*/


void  freenode(nodeptr p){		/*Liberar nodo*/ 	
	free (p);
}
void insafter (nodeptr p, int x){	/*insertar nodo q 
												despu�s de nodo p*/
		nodeptr q;
		if (p== NULL){
			printf (�fallo inserci�n \n�);
			exit (1)
		}
	q= getnode ( );
	q->info= x;
	q->next= p->next;
	p->next=q;
}/* fin insafter */ 
void delafter (nodeptr p, int *px){	/*borrar nodo q despu�s de nodo p, el dato se devuelve en puntero px*/

	nodeprt q;
	if ( (p==NULL)||(p-> next== NULL)){
			printf (��fallo eliminaci�n \n);
			exit (1);
	}
	q= p->next;
	*px= q->info;
	p->next= q->next;
	freenode (q);

}/* fin de delafter */ 

/*IMPLEMENTACI�N LISTAS DINAMICAS BIDIRECCIONALES <-----------------------------------------------------*/
#include <stdlib.h>				 /* Librer�as */
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
   /* El valor v no est� en la lista */
   if (!nodo || nodo->valor != v)
      *enc = FALSE;            /* devolver a trav�s de enc si v fue encontrado en la lista */
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
   
	/* Colocamos actual en la primera posici�n de la lista */
   actual = *lista;
   if (actual) 			 /* si lista no vac�a */
			while (actual->anterior)
				actual = actual->anterior;
/* Si la lista est� vac�a o el primer miembro es mayor que el nuevo*/
    if (!actual || actual->valor > v)
	{
   		   	/* A�adimos la lista a continuaci�n del nuevo nodo */
      	nuevo->siguiente = actual;
      	nuevo->anterior = NULL;

      	if (actual) 	/*si la lista no esta vac�a*/
				actual->anterior = nuevo;

      	if (!*lista)	/*si la lista esta vac�a*/
				*lista = nuevo;
   }
else {
      /* Avanzamos hasta el �ltimo elemento o hasta que el siguiente 	tenga un valor mayor que v */
      while (actual->siguiente && actual->siguiente->valor <= v)
	 			actual = actual->siguiente;

      /* Insertamos el nuevo nodo despu�s del nodo anterior */
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
   /* El valor v no est� en la lista */
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

   if (nodo->siguiente) 	/* no es el �ltimo nodo */
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
		printf("Lista vac�a");
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
	   /* Crear un nodo nuevo y vac�o*/
	   nuevo =(pNodo)malloc(sizeof(tipoNodo));
   		  return nuevo;
}

/*IMPLEMENTACI�N LISTAS CIRCULARES BIDIRECCIONALES <-----------------------------------------------------*/
typedef struct celda {
   tElemento elemento;
   struct celda *siguiente,*anterior;
} tipocelda;
�
typedef tipocelda *tPosicion;
typedef tipocelda *tLista;static void error(char *cad)
{		/*Imprime la cadena de error enviada como par�metro, en la salida del error est�ndar: el monitor*/

   			fprintf(stderr, "ERROR: %s\n", cad);
   			exit(1);
}
tLista Crear( ) 
{	/*Crea nodo de cabecera, asigna su misma direcci�n en el siguiente y anterior de la cabecera*/
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
�
   for (p=l, l->anterior->siguiente=NULL; l!=NULL; p=l)
	{
			l = l->siguiente;
			free(p);
   	}
}
tPosicion Primero (tLista l)
{	/* Retorna la direcci�n del siguiente a la cabecera */
	   return l->siguiente;
}

�
tPosicion Fin (tLista l)
{	/* Retorna la direcci�n de la cabecera */
	   return l;
}
void Insertar (tElemento x, tPosicion p, tLista l) 
{ /* Inserta un nodo antes del nodo en la posici�n p */
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
{	/*Borra el nodo ubicado en la direcci�n p, y despu�s p apunta a la posici�n del siguiente nodo*/
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
 {	/* Retorna el dato de nodo ubicado en la posici�n p, a menos que p sea la cabecera */
	   	if (p == l)
			{ 
				Error("Posici�n fin(l)");
  			}
   			return p->elemento;
}
tPosicion siguiente (tPosicion p, tLista l)
{	/* Devuelve la direcci�n del nodo siguiente a p */
   			if (p == l)
			{ 
				Error("Posicion fin(l)");
   			}
   			return p->siguiente;
}
tPosicion anterior( tPosicion p, tLista l)
{	/* Devuelve la direcci�n del nodo anterior a p */
   			if (p == l->siguiente)
			{
					Error("Posicion primero(l)");
   			}
   			return p->anterior;
}
tPosicion posicion (tElemento x, tLista l)
{		/* Devuelve la posici�n del elemento x en la lista l */
   tPosicion p;
   int encontrado;
	p = primero(l);
   encontrado = 0;
   while ((p != fin(l)) && (!encontrado))
			if (p->elemento == x)
					encontrado = 1;
			else
					p = p->siguiente;
   return p;	    /* Si no lo encontr�, retorna la direcci�n del �ltimo nodo */
}
