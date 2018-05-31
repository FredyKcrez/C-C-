#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queueNode{
       char dato;
       struct queueNode * siguiente;
};

typedef struct queueNode *QUEUEPTR;
typedef struct {
        QUEUEPTR frontPtr, rearPtr;
} Tipocola;

int isEmpty(QUEUEPTR *);
void insertar(QUEUEPTR *, QUEUEPTR *, char );
char remover(QUEUEPTR *, QUEUEPTR *);

int isEmpty(QUEUEPTR headPtr)
{
    return headPtr==NULL;
}

void insertar(QUEUEPTR *headPtr, QUEUEPTR *tailPtr, char valor)
{
    QUEUEPTR newPtr;
    newPtr = (QUEUEPTR)malloc(sizeof(queueNode));
    if(newPtr!=NULL)
    {
        newPtr->dato=valor;
        newPtr->siguiente=NULL;
        if(isEmpty(*headPtr))
             *headPtr=newPtr;
        else
            (*tailPtr)->siguiente=newPtr;
        *tailPtr=newPtr;
    }
    else
        printf("%c no insertado, no hay memoria disponible.\n", valor);
}
char remover(QUEUEPTR *headPtr, QUEUEPTR *tailPtr)
{
     char value;
     QUEUEPTR tempPtr;
     
     value = (*headPtr)->dato;
     tempPtr = *headPtr;
     *headPtr = (*headPtr)->siguiente;
     
     if(*headPtr==NULL)
                       *tailPtr=NULL;
     free(tempPtr);
     return value;
}

main()
{
      int Opc, r=1;
      char inser;
      Tipocola x;
      
      fflush(stdin);
      while(r!=0)
      {
                 printf("\nElija la opcion que desea realizar:\n1. Insertar elemento.\n2. Retirar elemento.\n3. Verificar si la lista esta vacia.\n4. Imprimir elementos de la cola.\n");
                 printf("\nOpcion:\t");
                 scanf("%i", &Opc);
                 while((Opc<1)||(Opc>3))
                 {
                                       printf("Error: Intente de nuevo.");
                                       scanf("%i", &Opc);
                 }
                 
                    switch (Opc)
                    {
                        case 1:
                                fflush(stdin);
                                printf("Ingrese el elemento a insertar:");
                                scanf("%c", inser);
                                insertar(&, &rearPt, inser);
                                break;
                        case 2:
                                if(!isEmpty(headPtr))
                                {
                                              printf("\nSe eliminara el elemento que esta al frente de la cola.");
                                              remove(&);
                                }
                                else
                                    printf("\nLa cola no contiene elementos para eliminar.");
                                break;
                        case 3:
                                if(isEmpty(!!!!!!!!!!!!!!!!!!!))
                                   printf("\nLa cola esta vacia!!! D:");
                                else
                                    printf("\nLa cola no esta vacia!!! :D");
                                    break;
                    }
                 printf("\n\n\tDigite 0 si no desea continuar:\t");
                 scanf("%i", &r);
      }
      
      getch();
      return 0;
}
      
