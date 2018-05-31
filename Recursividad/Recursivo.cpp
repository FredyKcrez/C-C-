//Funcion ackerman
int ackermann(int m, int n)
{ 
	if (m==0)
		return n+1;
	else
		 if (n==0)
			return ackermann(m-1,1);
		else
			return ackermann(m-1,ackermann(m,n-1)); 
}
int Recursivo (int *V, int i1, int i2)
{
 int aux1, aux2;
 if (i1==i2) 		//Caso base
    return V[i1];
 else {       		//Caso general
      aux1 = Recursivo(V, i1, (i1+i2)/2);
      aux2 = Recursivo(V, ((i1+i2)/2)+1, i2);
      if (aux1>aux2)
         return aux1;
      else
         return aux2;
      }
}


/*Ecuacion A[n] = A[subindice(n-1)] + 2[n]  los que estan en corchete son subindice ban "abajo"
	A[0] = 1*/

int func( int n )
{
	if (n==0)
		return 1;
	else
		return func( n-1 ) + ( int ) pow( 2 , n);
}
#include <stdio.h>
#include <conio.h>
#include <math.h>

int func( int n );

int main()   {
    
	int n, i, x;
for (i=0;i<10;i++)
    {
        x=func(i);
        printf("n= %d, func(%d)=%d\n", i, i, x);
    }

    getch();
    return 0;
}
