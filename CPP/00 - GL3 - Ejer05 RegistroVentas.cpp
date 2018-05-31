/*Diseñe un Flujograma, que calcule y despliegue el monto de una venta dados el nombre del producto,
su precio en dólares y la cantidad de unidades vendidas (deben ser mayor que cero).*/
#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int cantidad, ok, sal=1;
	char producto[30];
	float precio, monto=0;
	
	while (sal!=2)
	{
		fflush(stdin);
		printf("\n\n\n\tIngrese nombre del producto:\t");
		gets(producto);
		printf("\n\n\tIngrese precio del producto:\t");
		ok = scanf("%f", &precio);
		while((ok!=1)||(precio<0.00))
    	{
			fflush(stdin);
			printf("\n\t*** Por favor digite solo valores positivos!! ***");
			printf("\n\n\tIngrese precio del producto:\t");
			ok = scanf("%f", &precio);
			fflush(stdin);
		}
		printf("\n\n\tIngrese la cantidad de %s adquiridos:\t", producto);
		ok = scanf("%i", &cantidad);
		while((ok!=1)||(cantidad<0))
    	{
			fflush(stdin);
			printf("\n\t*** Por favor digite solo valores positivos!! ***");
			printf("\n\n\tIngrese la cantidad de %s adquiridos:\t", producto);
			ok = scanf("%i", &cantidad);
			fflush(stdin);
		}
		monto+=(cantidad*precio);
		printf("\n\n\tDesea registrar un nuevo producto\n\t1. Si\n\t2. No\n\n\tContinua?: ");
		scanf("%i", &sal);
		system("cls");
		fflush(stdin);
	}
	printf("\n\n\n\tEl monto total de la compra es de %.2f", monto);
	
	Sleep(5000);
	return 0;
}
