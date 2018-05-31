#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

main()
{
	float desc, monto = -4.00, pagoT;
	int ok, ban = 0;
	
	while(monto < 0)
	{
		printf("\n\n\tIngrese el total de la compra\n\n\tCompra:\t");
		ok = scanf("%f", &monto);
		while(ok!=1)
		{
			fflush(stdin);
			system("cls");
			printf("\n\n\t\t*** El valor ingresado no es valido ***");
			printf("\n\n\tIngrese el total de la compra\n\n\tCompra:\t");
			ok = scanf("%f", &monto);
			fflush(stdin);
		}
		if(monto>0)
			ban = 1;
		if(ban==0)
		{
			system("cls");
			printf("\n\n\t*** El valor ingresado no es valido debe ser positivo ***");
		}
	}
	desc = 0.2*monto;
	pagoT = monto-desc;
	system("cls");
	printf("\n\n\t*** Resultados ***\n");
	printf("\n\n\tEl monto de la compra es de:\t$ %.2f.\n\n\tRecibe un descuento de:\t$ %.2f\n\n\tEl total a pagar es:\t$ %.2f", monto, desc, pagoT);
	
	Sleep(7000);
	return 0;
}
