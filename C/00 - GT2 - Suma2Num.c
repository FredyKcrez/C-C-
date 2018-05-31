#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

main()
{
	int ok;
	float n1, n2;
	
	printf("\n\n\tIngrese dos valores numericos\n\n\tValor 1:\t");
	ok = scanf("%f", &n1);
	while(ok!=1)
	{
			fflush(stdin);
			system("cls");
			printf("\n\n\t\t*** El valor ingresado no es valido ***");
			printf("\n\n\tIngrese dos valores numericos\n\n\tValor 1:\t");
			ok = scanf("%f", &n1);
			fflush(stdin);
	}
	printf("\n\n\tValor 2:\t");
	ok = scanf("%f", &n2);
	while(ok!=1)
	{
			fflush(stdin);
			system("cls");
			printf("\n\n\t\t*** El valor ingresado no es valido ***");
			printf("\n\n\n\tValor 1:\t %.2f \n\n\tValor 2:  \t", n1);
			ok = scanf("%f", &n2);
			fflush(stdin);
	}
	
	float s = n1 + n2;
	printf("\n\n\n\tLa suma de %.2f y %.2f es:\t %.2f", n1, n2, s);
	
	getch();
	return 0;
}
