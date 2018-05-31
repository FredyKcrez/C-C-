/*En una tienda se efectúan descuentos a los clientes dependiendo del valor de la compra. Los
descuentos se aplican de acuerdo con los siguientes rangos:
Tipo de producto	Forma de Pago	Descuento
     A 				 1 Crédito		   5%
					 2 Contado		   7%
	 B				 1 Crédito		  10%
					 2 Contado		  14%
	 C				 1 Crédito		  20%
					 2 Contado		  28%
Dado el tipo de producto, forma de pago y el monto de la compra, despliegue el total apagar por la
compra*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	float monto,montoP;
	int ok,Fpag;
	char Tpro;
	
	printf("\n\n\tIngrese el Tipo de Producto en la compra (A-B-C)\n\n\tTipo: ");
	scanf("%c",&Tpro);
	while((Tpro!='A')&&(Tpro!='B')&&(Tpro!='C')&&(Tpro!='a')&&(Tpro!='b')&&(Tpro!='c'))
    {
        fflush(stdin);
        system("cls");
        puts("\n\t*** Por favor ingrese A, B o C ***");
        printf("\n\n\tDigite el dato: ");
        scanf("%c",&Tpro);
        system("cls");
        fflush(stdin);
	}
	printf("\n\n\tIngrese la forma de pago\n\n\t1. Credito\n\t2. Contado\n\n\tForma de Pago: ");
	scanf("%i",&Fpag);
	while((Fpag!=1)&&(Fpag!=2))
    {
        fflush(stdin);
        system("cls");
        puts("\n\t*** Por favor ingrese 1 o 2 ***");
        printf("\n\t1. Credito\n\t2. Contado\n\n\tForma de Pago: ");
        scanf("%i",&Fpag);
        system("cls");
        fflush(stdin);
	}
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
	if((Tpro=='A')||(Tpro=='a')&&(Fpag==1))
	{
		montoP=monto-(monto*0.05);
		printf("\n\n\n\tMonto a pagar:\t%.2f",montoP);
	}
	else
		if((Tpro=='A')||(Tpro=='a')&&(Fpag==2))
		{
			montoP=monto-(monto*0.07);
			printf("\n\n\n\tMonto a pagar:\t%.2f",montoP);
		}
		else
			if((Tpro=='B')||(Tpro=='b')&&(Fpag==1))
			{
				montoP=monto-(monto*0.1);
				printf("\n\n\n\tMonto a pagar:\t%.2f",montoP);
			}
			else
				if((Tpro=='B')||(Tpro=='b')&&(Fpag==2))
				{
					montoP=monto-(monto*0.14);
					printf("\n\n\n\tMonto a pagar:\t%.2f",montoP);
				}
				else
					if((Tpro=='C')||(Tpro=='c')&&(Fpag==1))
					{
						montoP=monto-(monto*0.2);
						printf("\n\n\n\tMonto a pagar:\t%.2f",montoP);
					}
					else
					{
						montoP=monto-(monto*0.28);
						printf("\n\n\n\tMonto a pagar:\t%.2f",montoP);
					}

	Sleep(7000);
	return 0;
}
