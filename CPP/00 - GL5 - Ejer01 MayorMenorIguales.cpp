/*Dise�e una soluci�n que permita leer dos n�meros y determinar el n�mero mayor, el n�mero menor o
un mensaje de que los n�meros son iguales*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	float a,b;
	int ok,fi;
	
	printf("\n\n\tDigite dos valores numericos\n\tValor 1: ");
	ok=scanf("%f",&a);
	printf("\n\tValor 2: ");
	fi=scanf("%f",&b);
	while((ok!=1)||(fi!=1))
    {
    	fflush(stdin);
    	system("cls");
        printf("\n\n\t*** Por favor ingrese solo valores numericos ***");
        printf("\n\n\tValor 1: ");
		ok=scanf("%f",&a);
		printf("\n\tValor 2: ");
		fi=scanf("%f",&b);
		system("cls");
		fflush(stdin);
	}
	if(a>b)
		printf("\n\n\tEl dato 1 es mayor que el dato 2\n\n\t  ---->\t%.3f > %.3f",a,b);
	else
		if(a<b)
			printf("\n\n\tEl dato 1 es menor que el dato 2\n\n\t  ---->\t%.3f < %.3f",a,b);
		else
			printf("\n\n\tEl dato 1 es igual que el dato 2\n\n\t  ---->\t%.3f = %.3f",a,b);
	
	Sleep(10000);
	return 0;
}
