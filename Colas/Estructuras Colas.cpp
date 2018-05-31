/*IMPLEMENTECIÓN DE LAS COLAS USANDO ARREGLOS <--------------------------------------------------------------*/

#include<stdio.h>
#include<conio.h>
#define TamCola 100
struct Cola{
      int frente;
      int atras;
      int nodes[TamCola];
};

struct Cola *create_cola (struct Cola *ps) {
      ps = (struct Cola *) malloc(sizeof(struct Cola));
      ps->frente = 0;
      ps->atras = -1;
      return ps;
}

main(){
     struct Cola *ps;
     ps=create_cola(ps);
:
}
int IsFull(struct Cola* ps) { //verifica si la cola esta llena
    int result=0;
    if (ps->atras == (TamCola -1)) 
        result=1;
   return result;
} 
void insert(struct Cola* ps, int i) { //inserta elemento entero a la cola
    ps->atras++;
    ps->nodes[ps->atras] = i;
}
int IsEmpty (struct Cola *ps) { //verifica si la cola esta vacia
    int result=0;
    if (ps->frente == ps->atras + 1)
           result=1;
    return result;
} 
int remove (struct Cola *ps) { //elimina elemnto de la cola
     int t= ps->nodes[ps-> frente];
     ps->frente++;
     return t;
} 

/*IMPLEMENTECIÓN DE LAS COLAS CIRCULARES <------------------------------------------------------------------*/

#define  TamCola 100
struct Cola{
      int frente;
      int final;
      int nodes[TamCola];
};
struct Cola *create_cola(struct Cola *ps) {
      ps = (struct Cola *) malloc(sizeof(struct Cola));
      ps->frente = ps->final = TamCola-1;
      return ps;
}
int main(){
     struct Cola *ps;
     ps=create_cola(ps);
:
}  
void insert(struct Cola* pq,  int i) 
{
   if ( isFull(pq) ){  //final+1== frente
       printf (“desbordamiento en la cola”);
       exit(1);
   }
   if ( pq->final==TamCola-1)   //final==99
      pq-> final=0;
   else
      ( pq-> final)++;
   pq->nodes[pq-> final] = i ;
}
int remove (struct Cola *pq) {
   int x=-1;    //devuelve -1 si cola está vacía
   if ( empty(pq) ) {
          printf (“la cola está vacía”);
           exit(1);
    } 
   if (pq->frente ==TamCola-1)
      pq->frente=0;
   else
      (pq->frente)++;
   x=(pq->nodes[pq->frente]);
   return x;
}
int empty(struct Cola* pq)
{
   if (pq->frente==pq-> final){
      return 1;
   else
      return 0;
}
int isFull(struct Cola* pq)
{
   if ( pq->final+1==pq->frente ){
       return 1;
   else
       return 0;
}

/*IMPLEMENTECIÓN DE LAS COLAS USANDO MEMORIA DINAMICA <-----------------------------------------------------*/
struct colaNodo {
   int dato;
   struct colaNodo * siguiente;
};
Typedef struct colaNodo * COLAPTR;
   COLAPTR frentePtr = NULL, finalPtr = NULL;

int isEmpty(COLAPTR frentePtr)
{
   return frentePtr == NULL;
}

void insertar ( COLAPTR * frentePtr, COLAPTR *finalPtr, char valor )
{
   COLAPTR newPtr;
   newPtr = (COLAPTR) malloc (sizeof (struct colaNodo));
   
   if ( newPtr != NULL ) {
      newPtr->dato = valor;
      newPtr->siguiente = NULL;
      if (isEmpty(*frentePtr))
         *frentePtr = newPtr;
      else
	 (*finalPtr)->siguiente = newPtr;
 
      *finalPtr = newPtr;
     }
    else {
       printf("%c no insertado.”, valor);
       printf(“ No existe memoria disponible.\n");
     }
}

char remover (COLAPTR *frentePtr, COLAPTR *finalPtr)
{
   char valor;
   COLAPTR tempPtr;
   valor = (*frentePtr)->dato;
   tempPtr = *frentePtr;
   *frentePtr = (*frentePtr)->siguiente;
    if (*frentePtr == NULL )
     *finalPtr = NULL;
    free(tempPtr);
   return valor;
}
