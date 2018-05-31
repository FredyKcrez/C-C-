/*Calcular el pago mínimo mensual en una tarjeta de crédito, sabiendo que al saldo de contado
se le agrega un 2.5% de interés mensual*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define inte 0.025

main()
{
	float pagoTot,pagoMen;
	int ok;
	
	printf("\n\n\tIngrese el monto acumulado en la tarjeta de credito: $");
	ok=scanf("%f",&pagoTot);
	while((ok!=1)||(pagoTot<0))
    {
    	fflush(stdin);
        printf("\n\n\t*** Por favor digite solo valores positivos ***");
        printf("\n\t Digite el dato: ");
        ok=scanf("%f", &pagoTot);
        fflush(stdin);
	}
	pagoMen=(pagoTot/12)+((pagoTot/12)*inte);
	printf("\n\n\tEl pago minimo mensual a realizar es de: $%.2f",pagoMen);
	Sleep(7000);
	return 0;
}
