#include "Rational.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{

 int a=1, b=2, c=3, d=4;
 RACIONAL x, y, z;
 x=R_Crear(a,b);
 y=R_Crear(a,c);
 printf("\n\nracional x = %i / %i",R_Num(x),R_Den(x));
 printf("\n\nracional y = %i / %i",R_Num(y),R_Den(y)); 
 z=R_adicion(x,y);
 printf("\n\nracional x+y = %i / %i",R_Num(z),R_Den(z));
 z=R_multiplicacion(x,y);
 printf("\n\nracional x*y = %i / %i",R_Num(z),R_Den(z)); 
 a=R_igualdad(x,y);
 printf("\n\n x==y? = %i",a);  

 getch ();     
 return 0;     
}
