#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0


typedef struct PILA{
       int top;
       int elem[10];
       }pila;
  
void push(pila *, int);
int pop(pila *);
int empty(pila *);
int full(pila *);        
        
main()
{
     int i, x;
     pila s;
     s.top=-1;
          
     for(i=0;i<5;i++)
     {
     printf("\nIngrese dato ");
     scanf("%i", &x);
     push(&s, x);
     }
     for(i=0;i<5;i++)
     {
         x=pop(&s);
         printf("\n%i", x);
     }
     
     getch();
     return 0;
}

void push(pila *ps, int x)
{
     if(full(ps))
                 printf("Desbordamiento");
     else
                 ps->elem[++(ps->top)] = x;
}

int pop(pila *ps)
{
     if(empty(ps))
                  printf("Desbordamiento");
     else
                  return (ps->elem[ps->top--]);
}  

int empty(pila *ps)
{
   if(ps->top==-1)
                  return (TRUE);
   else
       return(FALSE);
} 
    
int full(pila *ps)        
{
       if(ps->top==9)
                  return (TRUE);
   else
       return(FALSE);
}
