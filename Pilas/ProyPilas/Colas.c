/* COLAS.C */
#include "Colas.h"
#include <conio.h>
#include <stdio.h>
void Make(QUEUE * pq)  {
  pq->front=pq->rear=MAXQUEUE-1;
 }

int IsEmpty(QUEUE * pq)  { 
               if (pq->front == pq->rear)
		return(TRUE);
	 else
		 return(FALSE);
 }

void Insert(QUEUE * pq, QUEUELEMENT x) {
  /* Hacer espacio para un nuevo elemento */
    if (pq->rear== MAXQUEUE - 1)
	pq->rear=0;
    else
       (pq->rear)++;
   /* Comprueba que no hay desbordamiento */
   if (pq->rear==pq->front) {
      	printf("%s","Cola desbordada");
	//exit(1);
           }
   else
	pq->items[pq->rear]=x;
   return;
 }

QUEUELEMENT Remove(QUEUE * pq) {
     if (IsEmpty(pq)) {
       printf("%s","Cola subdesbordada");
       //exit(1);
        }
   if(pq->front==MAXQUEUE -1 )
	pq->front=0;
   else
       (pq->front)++;
   return (pq->items[pq->front]);
 }
