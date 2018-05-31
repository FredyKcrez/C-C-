#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define pi 3.1416

main()
{
	float ra = -0.34;
	int ok, ban = 0;
	
	while(ra<0.00)
	{
		printf("\n\n\tIngrese el radio de la circunferencia (en mts)\n\n\tRadio:\t");
		ok = scanf("%f", &ra);
		while(ok!=1)
		{
			fflush(stdin);
			system("cls");
			printf("\n\n\t\t*** El valor ingresado no es valido ***");
			printf("\n\n\tIngrese el radio de la circunferencia (en mts)\n\n\tRadio:\t");
			ok = scanf("%f", &ra);
			fflush(stdin);
		}
		if(ra>0)
			ban = 1;
		
		if(ban==0)
		{
			system("cls");
			printf("\n\n\t*** El valor ingresado no es valido debe ser positivo***");
		}
	}
	float area = pi*ra*ra;
	printf("\n\n\n\tLa circunferencia de radio %.2f posee un area de %.2f mt2.", ra, area);
	
	getch();
	return 0;
}
