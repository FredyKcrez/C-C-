#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

typedef struct PILA{
        int top;
        int cad[25];
} pila;

void push(pila *, char);
int pop(pila *);
int empty(pila *);
int full(pila *);

main()
{
      int i, x;
      int z, d, y;
      pila s;
      s.top=-1;
      
      printf("Ingrese datos a trabajar:");
      for(i=0;i<8; i++)
      {
                   scanf("%i", z);
                   push(&s, z);
      }
      
      for (i=0;i<24;i++)
      {    
           x = pop(&s);
           printf("%c", x);
      }
      
      getch();
      return 0;
}

void push(pila *ps, char z)
{
     if (full(ps))
        printf("desbordamiento");
     else
         ps->cad[++(ps->top)]=z;
}

int pop(pila *ps)
{
     if (empty(ps))
        printf("Desbordamiento");
     else
        return(ps->cad[ps->top--]);
}

int empty(pila *ps)
{
    if(ps->top == -1)
        return(TRUE);
    else
        return(FALSE);
}

int full(pila *ps)
{
    if(ps->top==24)
       return(TRUE);
    else
       return(FALSE);
}
