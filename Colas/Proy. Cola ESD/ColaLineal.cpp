typedef int TipoDato;
#include "ColaLineal.h"
#include <stdio.h>
#include <windows.h>

int main()
{
    int x=0;
    
    Cola colaLineal1;
    Cola colaLineal2;
    
    crearCola(&colaLineal1);
    crearCola(&colaLineal2);
    puts("\n\n\t=====Se estan insertando los elementos=====");
    for(x=0;x<10;x++)
    {
           insertar(&colaLineal1,x+100);
           insertar(&colaLineal2,x+200);
    }
    Sleep(3000);
    system("cls");
    puts("\n\n\t=====Lista de los elementos=====");
    printf("\n\nValores de la Cola 1:\t");
    for(x=0;x<10;x++)
            printf("%d\t",quitar(&colaLineal1));
    printf("\nValores de la Cola 2:\t");
    for(x=0;x<10;x++)
            printf("%d\t",quitar(&colaLineal2));
    printf("\n\n\n");
    system("Pause");
    return 1;
}

void crearCola(Cola* cola)
{
     cola->frente = 0;
     cola->final = -1;
}

Cola *crearColaDim()
{
     Cola *ColaDim;
     ColaDim = (Cola*) malloc(sizeof(Cola));
     ColaDim->frente=0;
     ColaDim->final = -1;
     return ColaDim;
}

void insertar(Cola* cola, TipoDato entrada)
{
     if(colaLlena(*cola))
     {
         puts("Cola completa.");
         exit(1);
     }
     cola->final++;
     cola->Elemento[cola->final]=entrada;
}

TipoDato quitar(Cola* cola)
{
     TipoDato item;
     if(colaVacia(*cola))
     {
         puts("Se intenta sacar un elemento en cola vacia.");
         exit(1);
     }
     item=cola->Elemento[cola->frente];
     cola->frente++;
     return item;
}

int colaVacia(Cola cola)
{
    return cola.final<cola.frente;
}

int colaLlena(Cola cola)
{
    return cola.final == MAXTAMQ -1;
}

TipoDato frente(Cola cola)
{
     if(colaVacia(cola))
     {
          puts("Error de ejecucion, cola vacia.");
          exit(1);
     }
     return cola.Elemento[cola.frente];
}
