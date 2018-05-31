/*Dados cuatro valores, calcular la suma y el promedio de ellos*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	float n1,n2,n3,n4,sum,prom;
	
	printf("\n\n\t--- Ingrese 4 valores numericos ---\n\n");
	printf("\n\tValor No. 1: "); scanf("%f",&n1);
	printf("\n\tValor No. 2: "); scanf("%f",&n2);
	printf("\n\tValor No. 3: "); scanf("%f",&n3);
	printf("\n\tValor No. 4: "); scanf("%f",&n4);
	sum=n1+n2+n3+n4;
	prom=sum/4;
	printf("\n\n\tLa suma de los valores numericos es %.2f\n\ty el promedio es de %.2f",sum,prom);
	Sleep(4000);
	return 0;
}

