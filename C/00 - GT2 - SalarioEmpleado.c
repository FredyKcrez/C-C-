#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#define n 25

main()
{
	char Nom[n];
	int ban = 0, horas = -3, ok;
	float sal;
	
	fflush(stdin);
	printf("\n\n\tIngrese el nombre del empleado\n\n\tNombre:\t");
	gets(Nom);
	while(horas < 0)
	{
		printf("\n\n\tIngrese las horas trabajadas del empleado\n\n\tHoras:\t");
		ok = scanf("%i", &horas);
		while(ok!=1)
		{
			fflush(stdin);
			system("cls");
			printf("\n\n\t*** Error al leer horas trabajadas por el empleado ***");
			printf("\n\n\tIngrese las horas trabajadas del empleado\n\n\tHoras:\t");
			ok = scanf("%i", &horas);
			fflush(stdin);
		}
		if(horas>0)
			ban = 1;
		
		if(ban==0)
		{
			system("cls");
			printf("\n\n\t*** El valor ingresado no es valido debe ser positivo***");
		}
	}
	sal = 6.50*horas;
	printf("\n\n\tEl empleado ");
	int i=0;
	while((Nom[i]!=' ')&&(Nom[i]!=0))
	{
		printf("%c", Nom[i]);
		i++;
	}
	printf(" que labora %i horas, posee un salario de %.2f", horas, sal);
	Sleep(5000);
	return 0;
}
