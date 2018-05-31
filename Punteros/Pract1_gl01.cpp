#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

/*Empleando aritmetica de punteros y por medio de una funcion conparar, compara dos matrices indicando mediante un valor logico si 
las matrices son iguales o no
*/
int comparar(int A[3][3], int B[3][3]);

main()
{
      /*Inicializando matrices*/
      int i, j, r;
      int A[3][3]={
                   {7,8,5},
                 {9, 2, 1},
                 {3,7, 5}
                 };
                 
      int B[3][3]={
                   {7,8,6},
                 {9, 2, 1},
                 {3,7, 5}
                 };
      printf("\n Inicializando matrices\n");
                 
      printf("\n Mostrando matrices\n\n");
      for(i=0; i<3; i++)
      {
               for(j=0; j<3; j++)
               {
                        printf("%i\t",*(*(A+i)+j));
               }
               printf("\n");
      }
      printf("\n\n");
      for(i=0; i<3; i++)
      {
               for(j=0; j<3; j++)
               {
                        printf("%i\t",*(*(B+i)+j));
               }
               printf("\n");
      }
      
      printf("\n Comparando matrices:");
      r = comparar(A, B);
      if(r==0)
             printf("\n Las matrices son diferentes.");
      else
          if(r==1)
              printf("\n Las matrices son iguales.");
      
      getch();
      return 0;
}

int comparar(int A[3][3], int B[3][3])
{
    int i, j;
    for(i=0; i<3; i++)
             for(j=0; j<3; j++)
               {
                        if(*(*(A+i)+j)==*(*(B+i)+j))
                            return(TRUE);
                        else
                            return(FALSE);
               }
}
