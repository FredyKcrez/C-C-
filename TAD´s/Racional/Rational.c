#include "Rational.h"
#include <stdlib.h>
#include <stdio.h>

RACIONAL R_Crear (int x, int y)
/* PRE: y != 0
   POST: R_Crear = x , y */
{
       RACIONAL R;
       if     ((R=(RACIONAL)malloc(sizeof(STRUCTRAC))) != NULL)
       {
                R->num = x;
                R->den = y;
        }
        return (R);

}
void R_Destruir (RACIONAL R)
/* PRE: ninguna
   POST: Libera el espacio ocupado por el racional */
{
   free(R);       
}

int R_Num(RACIONAL R)
/* PRE: ninguna
   POST: Devuelve el numerador del racional dado */
{
   return( R->num );
}

int R_Den(RACIONAL R)
/* PRE: ninguna
   POST: Devuelve el denominador del racional dado */
{
   return (R->den);   
}

RACIONAL R_AsignarNum(RACIONAL R, int z)
/* PRE: ninguna
   POST: Devuelve el racional modificado con z 
         como numerador */
{
        R->num = z;
        return(R); 
}

RACIONAL R_AsignarDen(RACIONAL R, int z)
/* PRE: z != 0
   POST: Devuelve el racional modificado con z 
         como denominador */
{
        R->den = z;
        return(R); 
}

RACIONAL R_adicion (RACIONAL R1, RACIONAL R2)
/* PRE: R1 = X1/Y1 y R2=X2/Y2
    POST: R_adicion = X1/Y1 + X2/Y2 
                    = (X1*Y2 + X2*Y1) / Y1*Y2        */
{
       return( R_Crear(R_Num(R1)*R_Den(R2)+R_Num(R2)*R_Den(R1),R_Den(R1)*R_Den(R2)));
}

RACIONAL R_multiplicacion ( RACIONAL R1, RACIONAL R2)
/* PRE: R1 = X1/Y1 y R2=X2/Y2
    POST: R_adicion = X1/Y1 * X2/Y2 
                    = (X1 * X2) / (Y1 * Y2)            */
{
          return( R_Crear(R_Num(R1)*R_Num(R2), R_Den(R1)*R_Den(R2)));
}

int R_igualdad( RACIONAL R1, RACIONAL R2)
/* PRE: R1 = X1/Y1 y R2=X2/Y2
    POST: R_igualdad=(X1*Y2 = X2*Y1 )        */
{
        return( R_Num(R1)*R_Den(R2) == R_Num(R2)*R_Den(R1) );
}

/*
int main()
{

 int a=1, b=2, c=3, d=4;
 RACIONAL x, y, z;
 x=R_Crear(a,b);
 y=R_Crear(a,c);
 z=R_Crear(a,d);
 
 printf("\n\nracional x = %i / %i",R_Num(x),R_Den(x));


 getch ();     
 return 0;     
}
*/

