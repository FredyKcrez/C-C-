#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXCOLS 15

typedef struct nodo
{
        char dato;
        struct nodo *siguiente;
} tiponodo;

typedef tiponodo *pNodo;
typedef tiponodo *Pila;

int empty(Pila *ps)
{
    return ((*ps)== NULL);
}

char pop(Pila * ps)
{
     pNodo temp;
     char popvalue;
     temp = *ps;
     popvalue = (*ps)->dato;
     *ps = (*ps)->siguiente;
     free(temp);
     
     return popvalue;
}

void push(Pila *ps, char a)
{
     pNodo nuevo;
     nuevo = (pNodo) malloc(sizeof(tiponodo));
     if (nuevo != NULL)
     {
        nuevo->dato = a;
        nuevo->siguiente = *ps;
        *ps = nuevo;
     }
     else
     printf("No se pudo insertar el elemento. Falta de memoria\n");
}

int comparar(char linea[MAXCOLS], char invert[MAXCOLS])
{
        int i;
        for(i=0; i<MAXCOLS; i++)
            if(linea[i]!=invert[i])
                return 1;
        
        return 0;
}

main()
{
      char linea[MAXCOLS];
      char invert[MAXCOLS];
      int pos=0, i, res;
      
      Pila p1=NULL;
      
      printf("\t===Digite la linea a verificar:===\n\n\t\t");
      while ((linea[pos++]=getchar()) != '\n');
            linea[--pos]='\0';
      for (i=0; i<pos; i++)
          push(&p1, linea[i]);
      for (i=0; i<pos; i++)
          invert[i]=pop(&p1);
          invert[pos]='\0';
          
      res = comparar(linea, invert);
      
      if(res==0)
                printf("\n\tLa cadena es palindroma");
      else
          printf("\n\tLa cadena no es palindroma");
      
      getch();
}
