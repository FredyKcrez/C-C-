#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

struct stack {
int tope;
char elementos[MAXCOLS];
};

int empty(struct stack *);
char pop(struct stack *);
void push(struct stack *, char);
main()
{
      char linea[MAXCOLS];
      char invert[MAXCOLS];
      int pos=0, i, n=0;
      struct stack pila;
      pila.tope=-1;

      printf("\n Digite la Cadena a trabajar:\t");
      while ((linea[pos++]=getchar()) != '\n');
      linea[--pos]= '\0';
      printf("\n La linea original es:\t%s", linea);
      for (i=0; i<pos; i++)
          push(&pila, linea[i]);
      for (i=0; i<pos; i++)
          invert[i]=pop(&pila);
          invert[i] = '\0';
      printf("\n La linea invertida es:\t%s", invert);
      for (i=0; i<pos; i++)
      {
          if(linea[i]=='a'||linea[i]=='A'||linea[i]=='e'||linea[i]=='E'||linea[i]=='i'||linea[i]=='I'||linea[i]=='o'||linea[i]=='O'||linea[i]=='u'||linea[i]=='U')
               n++;
      }
      printf("\n\n Numero de Vocales de la Linea de Texto:  %d\n", n);
      printf("\n\n\t\t |._.|._.|._.|._.|._.|");
      getch();
}

int empty(struct stack *ps)
{
    return (ps->tope == -1);
}

char pop( struct stack *ps)
{
     if (empty(ps))
     {
         printf("Subdesbordamiento de pila\n");
         exit(1);
     }
     return ( ps->elementos[ps->tope--]);
}

void push(struct stack *ps, char a)
{
     if (ps->tope == MAXCOLS - 1)
     {
          printf("Desbordamiento de pila\n");
          exit(1);
     }
     ps->elementos[++ps->tope]=a;
}
