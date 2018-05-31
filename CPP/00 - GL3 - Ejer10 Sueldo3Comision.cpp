/*Un vendedor recibe un salario base (en $) y 10% extra por comisiones de sus ventas.
El vendedor quiere saber cuánto recibirá en concepto de comisiones por las tres ventas que
realizó en el mes y el total de dinero que tendrá como sueldo*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#define com 0.10

main()
{
	float salbas, sueldo, vent1, vent2, vent3;
	int ok;
	
	printf("\n\n\tIngrese su salario base: ");
	ok=scanf("%f", &salbas);
	while((ok!=1)||(salbas<0.00))
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00!! ***");
        printf("\n\n\tDigite el salario: ");
        ok=scanf("%f", &salbas);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el valor de la venta 1: ");
	ok=scanf("%f", &vent1);
	while((ok!=1)||(vent1<0.00))
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00!! ***");
        printf("\n\n\tDigite el valor: ");
        ok=scanf("%f", &vent1);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el valor de la venta 2: ");
	ok=scanf("%f", &vent2);
	while((ok!=1)||(vent2<0.00))
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00!! ***");
        printf("\n\n\tDigite el valor: ");
        ok=scanf("%f", &vent2);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el valor de la venta 3: ");
	ok=scanf("%f", &vent3);
	while((ok!=1)||(vent3<0.00))
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00!! ***");
        printf("\n\n\tDigite el valor: ");
        ok=scanf("%f", &vent3);
        fflush(stdin);
	}
	sueldo=salbas+(vent1*com)+(vent2*com)+(vent3*com);
	printf("\n\n\tEl sueldo general que recibira con la comisión sera de: $ %.2f", sueldo);
	
	Sleep(8000);
	return 0;
}
