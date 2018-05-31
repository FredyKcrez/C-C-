/*Diseñe una solución que dados un grupo de 10 números enteros calcule e imprima lo siguiente: el
promedio de los 10 números y la cantidad de números negativos*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	float prom,num,sum=0;
	int i,ok,neg=0;
	
	printf("\n");
	for(i=1;i<=10;i++)
	{
		printf("\n\tIngrese el %i° valor numerico:\t",i);
		ok=scanf("%f",&num);
		while(ok!=1)
	    {
	        fflush(stdin);
	        system("cls");
	        printf("\n\t*** Error. Intente de nuevo ***");
	        printf("\n\n\tIngrese el %i valor numerico:\t",i);
	        ok=scanf("\n%f",&num);
	        fflush(stdin);
		}
		sum+=num;
		if(num<0.00)
			neg++;
	}
	prom=sum/10;
	system("cls");
	printf("\n\n\t*** Resultados obtenidos ***\n\n\tPromedio: %.2f\n\tCantidad de numeros negativos: %i",prom,neg);
	
	Sleep(7000);
	return 0;
}
