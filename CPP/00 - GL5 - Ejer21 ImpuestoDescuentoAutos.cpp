/*En el auto lote “Los Fantásticos” se tiene una promoción, en la cual dependiendo de la marca del
carro, así se le aplican los impuestos y el descuento a la hora de la compra.
	Marca		Impuestos		Descuentos
1 Toyota		   5%			   10%
2 Chevrolet		   7%			   15%
3 Ford			   4%			   20%
4 Hyundai		   8%			   30%
Diseñe una solución que permita imprimir la marca del vehiculo que compra, el precio original, los
impuestos de compra y el precio final de compra*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int ok, marca;
	float pVeh,imp,pFin,desc;
	
	puts("\n\n\tSeleccione el tipo de auto a adquirir\n\n\t1. Toyota\n\t2. Chevrolet\n\t3. Ford\n\t4.Hyundai");
	printf("\n\n\tMarca:\t");
	ok=scanf("%d",&marca);
	while((ok!=1)||((marca!=1)&&(marca!=2)&&(marca!=3)&&(marca!=4)))
    {
		system("cls");
     	fflush(stdin);
        puts("\n\t*** Debe escoger entre los modelos mostrados ***");
        printf("\n\t1. Toyota\n\t2. Chevrolet\n\t3. Ford\n\t4.Hyundai\n\n\tMarca:\t");
        ok=scanf("\n%d", &marca);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el precio del vehiculo: $ ");
	ok=scanf("%f",&pVeh);
	while((ok!=1)||(pVeh<0.00))
    {
		system("cls");
     	fflush(stdin);
        printf("\n\t**Debe ser un valor mayor que 0.00 **\n\n\tPrecio: $");
        ok=scanf("\n%d", &pVeh);
        fflush(stdin);
	}
	system("cls");
	puts("\n\n\t*** Detalles de la compra ***");
	if(marca==1)	//Para el modelo Toyota
	{
		imp=pVeh*0.05;
		desc=pVeh*0.1;
		pFin=pVeh-desc+imp;
		printf("\n\n\n\tMarca del vehiculo: Toyota");
	}
	else
		if(marca==2)	//Para el modelo Chevrolet
		{
			imp=pVeh*0.07;
			desc=pVeh*0.15;
			pFin=pVeh-desc+imp;
			printf("\n\n\n\tMarca del vehiculo: Chevrolet");
		}
		else
			if(marca==3)	//Para el modelo Ford
			{
				imp=pVeh*0.04;
				desc=pVeh*0.2;
				pFin=pVeh-desc+imp;
				printf("\n\n\n\tMarca del vehiculo: Ford");
			}
			else
				if(marca==4)	//Para el modelo Hyundai
				{
					imp=pVeh*0.08;
					desc=pVeh*0.3;
					pFin=pVeh-desc+imp;
					printf("\n\n\n\tMarca del vehiculo: Hyundai");
				}
	printf("\n\tPrecio original del vehiculo: $%.2f\n\tImpuestos sobre la compra: $%.2f\n\tPrecio final del vehiculo: $%.2f",pVeh,imp,pFin);
	
	Sleep(12000);
	return 0;
}
