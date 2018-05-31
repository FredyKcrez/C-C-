/*Dados el nombre del cliente, y el valor de la compra, calcule el monto a pagar considerando lo
siguiente:
 Si la compra es menor o igual a $75.00, NO tiene descuento.
 Si la compra es mayor de $75.00, tiene un descuento del 5%
 Si la compra es mayor de $150.00, tiene un descuento del 10%
Se deberá imprimir el nombre del cliente, el valor de la compra y el monto real a pagar*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	char name[30];
	float monto,montoP;
	int ok;
	
	printf("\n\n\tDigite el nombre del cliente:\t");
	gets(name);
	printf("\n\n\tIngrese el monto de la compra:\n\n\tMonto: $");
	ok=scanf("%f",&monto);
	while((ok!=1)||(monto<0.00))
    {
        fflush(stdin);
        system("cls");
        puts("\n\t*** Por favor ingrese un valor positivo ***");
        printf("\n\n\tDigite el monto: $");
        ok=scanf("\n%f",&monto);
        system("cls");
        fflush(stdin);
	}
	if(monto<=75.00)
		printf("\n\n\n\tCliente:\t%s\n\n\tMonto a pagar:\t%.2f",name,monto);
	else
		if((monto>75.00)&&(monto<=150.00))
		{
			montoP=monto-(monto*0.05);
			printf("\n\n\n\tCliente:\t%s\n\n\tMonto de la compra:\t%.2f\n\n\tMonto a pagar:\t%.2f",name,monto,montoP);
		}
		else
		{
			montoP=monto-(monto*0.1);
			printf("\n\n\n\tCliente:\t%s\n\n\tMonto de la compra:\t%.2f\n\n\tMonto a pagar:\t%.2f",name,monto,montoP);
		}
	
	Sleep(7000);
	return 0;
}
