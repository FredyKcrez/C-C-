#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define maxq 100
#define TRUE 1
#define FALSE 0

struct queue{
       int items[maxq];
       int front, rear;
       };
struct queue q;

int empty(struct queue *);
int remove(struct queue *);
void insert(struct queue *, int );
void impri(struct queue *);

int empty(struct queue *pq)
{
    return((pq->front == pq->rear)? TRUE:FALSE);
}

int remove(struct queue *pq)
{
    if(empty(pq))
    {
                 printf("\nLa cola esta vacia!! :D");
                 exit(1);
    }
    if(pq->front==maxq-1)
                 pq->front = 0;
    else
        (pq->front)++;
    return(pq->items[pq->front]);
}
    
void insert(struct queue *pq, int X)
{
     if(pq->rear==maxq-1)
           pq->rear=0;
     else
         (pq->rear)++;
     /* DESBORDAMIENTO??*/
     if(pq->rear==pq->front)
     {
                            printf("\nDesbordamiento en la cola!!!");
                            exit(1);
     }
     pq->items[pq->rear]=X;
     return;
}

void impri(struct queue *pq)
{
     int i;
     
     if(empty(&q))
           printf("\nLa cola esta vacia.");
     else
     {
         for(i=1; i<5; i++)
                  printf("%i\t", q.items[i]);
     }
}
    
main()
{
      int Opc, r=1, inser;
      
      fflush(stdin);
      while(r!=0)
      {
                 printf("\nElija la opcion que desea realizar:\n1. Insertar elemento.\n2. Retirar elemento.\n3. Verificar si la lista esta vacia.\n4. Imprimir elementos de la cola.\n");
                 printf("\nOpcion:\t");
                 scanf("%i", &Opc);
                 while((Opc<1)||(Opc>4))
                 {
                                       printf("Error: Intente de nuevo.");
                                       scanf("%i", &Opc);
                 }
                 
                    switch (Opc)
                    {
                        case 1:
                                fflush(stdin);
                                printf("Ingrese el elemento a insertar:");
                                scanf("%i", &inser);
                                insert(&q, inser);
                                break;
                        case 2:
                                if(!empty(&q))
                                {
                                              printf("\nSe eliminara el elemento que esta al frente de la cola.");
                                              remove(&q);
                                }
                                else
                                    printf("\nLa cola no contiene elementos para eliminar.");
                                break;
                        case 3:
                                if(empty(&q))
                                   printf("\nLa cola esta vacia!!! D:");
                                else
                                    printf("\nLa cola no esta vacia!!! :D");
                                    break;
                        case 4:
                               impri(&q);
                               break;
                    }
                 printf("\n\n\tDigite 0 si no desea continuar:\t");
                 scanf("%i", &r);
      }
      
      getch();
      return 0;
}
