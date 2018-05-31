/*Diseñe un flujograma que resuelva el problema que tienen en una gasolinera con el registro en litros
que dan las bombas surtidoras, estando el precio (en $) de la gasolina fijado en galones. El
diagrama de flujo debe calcular y desplegar cuánto debe pagar el cliente por su compra de gasolina.
Considere: Precio por galón --> $ 3.77 ; 1 galón = 3.7854 litros*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define gal 3.77
#define litr 3.7854

main()
{
	float cgal, clit, precio;
	int ok;
	
	printf("\n\n\tIngrese la cantidad de gasolina a utilizar (en lts):\t");
	ok=scanf("%f", &clit);
	while((ok!=1)||(clit<0.00))
    {
     	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00!! ***");
        printf("\n\n\tDigite el dato: ");
        ok=scanf("%f", &clit);
        fflush(stdin);
	}
	cgal = clit/litr;
	precio = cgal*gal;
	printf("\n\n\tUsted ha adquirido %.2f galones a un precio de %.2f", cgal, precio);
	
	Sleep(8000);
	return 0;
}
