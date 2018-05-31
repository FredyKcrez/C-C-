#include <stdlib.h>
#include <stdio.h>
         
typedef struct s_rac {
int num;
int den;
} STRUCTRAC;
typedef STRUCTRAC *RACIONAL;

RACIONAL R_Crear (int x, int y);
/* PRE: y != 0
   POST: R_Crear = x , y */

void R_Destruir (RACIONAL R);
/* PRE: ninguna
   POST: Libera el espacio ocupado por el racional */

int R_Num(RACIONAL R);
/* PRE: ninguna
   POST: Devuelve el numerador del racional dado */

int R_Den(RACIONAL R);
/* PRE: ninguna
   POST: Devuelve el denominador del racional dado */

RACIONAL R_AsignarNum(RACIONAL R, int z);
/* PRE: ninguna
   POST: Devuelve el racional modificado con z 
         como numerador */

RACIONAL R_AsignarDen(RACIONAL R, int z);
/* PRE: z != 0
   POST: Devuelve el racional modificado con z 
         como denominador */

RACIONAL R_adicion (RACIONAL R1, RACIONAL R2);
/* PRE: R1 = X1/Y1 y R2=X2/Y2
    POST: R_adicion = X1/Y1 + X2/Y2 
                    = (X1*Y2 + X2*Y1) / Y1*Y2        */

RACIONAL R_multiplicacion ( RACIONAL R1, RACIONAL R2);
/* PRE: R1 = X1/Y1 y R2=X2/Y2
    POST: R_adicion = X1/Y1 * X2/Y2 
                    = (X1 * X2) / (Y1 * Y2)            */

int R_igualdad( RACIONAL R1, RACIONAL R2);
/* PRE: R1 = X1/Y1 y R2=X2/Y2
    POST: R_igualdad=(X1*Y2 = X2*Y1 )        */
