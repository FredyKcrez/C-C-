/*Se tiene el registro de las ventas del día hechas por un almacén. Diseñe una solución que calcule e imprima monto total de ventas
al contado y el monto total de ventas al crédito. Además, determinar si la venta mayor y la venta menor fue realizada al crédito o
al contado.*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int ok,n=0,m,Tven,May,Men;
	float pArt,mcon=0.00,mcre=0.00,vMay=0.00,vMen=100000.00;
	
	printf("\n\n\tDigite la cantidad de articulos a registrar: ");
	ok=scanf("%i",&n);
	while((ok!=1)||(n<0))
    	{
	    	fflush(stdin);
	    	system("cls");
      		printf("\a\n\t*** Por favor digite un valor mayor que 0 ***");
	       printf("\n\n\tDigite el dato: ");
	       ok=scanf("%d", &n);
	       fflush(stdin);
	}
	m=n;
	system("cls");
    	while((n--)>0)
    	{
		printf("\n\n\tTipo de venta del articulo %i\n\t1. Credito\n\t2. Contado\n\n\tTipo: ",m-n);
		ok=scanf("%i",&Tven);
		while((Tven!=1)&&(Tven!=2))
		{
			fflush(stdin);
	    	system("cls");
	        printf("\a\n\t*** Error. Escoja entre las opciones posibles ***\n\n\t1. Credito\n\t2. Contado\n\n\tTipo: ");
	        ok=scanf("%d", &Tven);
	        fflush(stdin);
		}
		printf("\n\n\tIngrese precio del articulo %i:\t$",m-n);
		ok=scanf("%f",&pArt);
		while((ok!=1)||(pArt<0))
		{
			fflush(stdin);
	    	system("cls");
	        printf("\a\n\t*** Error. El precio debe ser mayor que 0 ***\n\n\tPrecio: $");
	        ok=scanf("%f", &pArt);
	        fflush(stdin);
		}
		if(Tven==1)
			mcre+=pArt;
		else
			mcon+=pArt;
		if(pArt>vMay)
		{
			vMay=pArt;
			May=Tven;
		}
		else
			if(pArt<vMen)
			{
				vMen=pArt;
				Men=Tven;
			}
	}
	system("cls");
	printf("\n\n\t*** Resultados ***\n\n\tMonto Total Contado: $%.2f\n\tMonto Total Credito: $%.2f\n\tMonto Global: $%.2f",mcon,mcre,mcon+mcre);
	printf("\n\n\tLa venta mayor se realizo al ");
	if(May==1)
		printf("credito.");
	else
		printf("contado.");
	printf("\n\n\tLa venta menor se realizo al ");
	if(Men==1)
		printf("credito.");
	else
		printf("contado.");
	
	Sleep(20000);
	return 0;
}
