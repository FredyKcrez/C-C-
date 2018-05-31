/*Dise�e un Flujograma que calcule y despliegue el monto a pagar en d�lares en una factura y
la comisi�n que se debe de pagar a un vendedor, dado el monto de la compra, a la cual se le
debe agregar el 13% de IVA. La comisi�n a pagar, es del 7% sobre el monto con IVA de la
factura*/
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define iva 0.13
#define com 0.07

main()
{
	float monto, salfin;
	int ok;
	
	printf("\n\n\t\tIngrese valor de la compra:\n\n\t\t$ ");
	ok=scanf("%f", &monto);
	while(ok!=1)
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00!! ***");
        printf("\n\n\t\t Digite el monto: $ ");
        ok=scanf("%f", &monto);
        fflush(stdin);
	}
	salfin=monto+(monto*iva);
	printf("\n\n\t\tEl monto a pagar por la factura es de %.2f,\n\t\ty la comision a pagar es de %.2f", salfin, salfin*com);
	
	Sleep(10000);
    return 0;
}
