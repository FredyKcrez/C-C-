#include<stdio.h>
#include<conio.h>
#define equal 1
#define amay 2
#define amen 3

/* EMPLEANDO ARITMETICA DE PUNTEROS, CREAR UNA FUNCION "COMPARAR" LA CUAL COMOPARA LA SUMATORIA DE LAS MATRIZ "a"
CONTRA LA SUMATORIA DE LA MATRIZ "b". dEVULVE UN VALOR INDICADO:
  1: SON IGUALES;      2: a>b;        3: b>a     */

int compara(int a[3][3], int b[3][3]);

main()
{
      int a[3][3]={
               {4,5,1}, /*primera fila*/
               {0,7,3}, /*segunda fila*/
               {2,9,0}
               };
      int b[3][3]={
                   {5,7,1},
                   {2,3,6},
                   {3,4,1}
               };
      
      int i, j, x;
      
      /*inicializando las matrices*/
      
      
      /*impresion de matrices*/
      printf("\nElementos de la matriz A\n");
      for(i=0; i<3; i++)
      {
               for(j=0; j<3; j++)
                       printf(" %i\t", *(*(a+i)+j));
               printf("\n");
      }
      
      printf("\nElementos de la matriz B\n");
      for(i=0; i<3; i++)
      {
               for(j=0; j<3; j++)
                       printf(" %i\t", *(*(b+i)+j));
               printf("\n");
       }
                        
      /*invocaion a funcion comparar*/
      x = compara(a, b); 
      printf("\n\nComparacion de las matrices:");
      /*resultado de la comparacion*/
      if(x==1)
             printf("\nLas matrices son: IGUALES");
      else
          if(x==2)
                 printf("\nLa sumatoria de la matriz A es mayor que la de la matriz B");
          else
              printf("\nLa sumatoria de la matriz B es mayor que la de la matriz A");
             
      
      
      getch();
      return 0;
}

int compara(int a[3][3], int b[3][3])
{
    int i, j, z=0, y=0;
    
    //Sumatoria matriz a 
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            z = z+(*(*(a+i)+j));
    //Sumatoria matriz b       
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            y = y+(*(*(b+i)+j));
    
    if(z==y)
            return(equal);
    else
        if(z>y)
               return(amay);
        else
            if(z<y)
                   return(amen);
}
