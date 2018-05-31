#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int ok,tz;
	float p,pvf,des;
	
	printf("\n\n\tSeleccione el tipo de zapato a comprar:\n\t1. Casual.\n\t2. Tennis.\n\t3. Tacones\n\tOpcion:\t");
	ok=scanf("%i",&tz);
	while(ok!=1)
    {
     	fflush(stdin);
     	system("cls");
        printf("\n\t*** Por favor seleccione una opcion existente ***");
        printf("\n\n\tDigite el dato: ");
        ok=scanf("%d", &tz);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el precio de los zapatos\n\t$");
	ok=scanf("%f",&p);
	while(ok!=1)
    {
     	fflush(stdin);
     	system("cls");
        printf("\n\t*** Por favor ingrese un valor positivo ***");
        printf("\n\n\tDigite el precio: $");
        ok=scanf("%f", &p);
        fflush(stdin);
	}
	system("cls");
	if(p>0.00)
	{
		if((tz==1)||(tz==2)||(tz==3))
		{
			switch(tz)
			{
				case 1:
					des=p*0.1;
					break;
				case 2:
					des=p*0.2;
					break;
				case 3:
					des=p*0.3;
					break;
			}
			pvf=p-des;
			printf("\n\n\t*** Informacion de la compra ***\n\n\tPrecio original: $%.2f\n\tDescuento: $%.2f\n\tPrecio final: $%.2f\n\t",p,des,pvf);
		}
		else
			printf("\n\n\t*** Error de dato de tipo de zapato ***");
	}
	else
		printf("\n\n\t*** El precio del producto es invalido ***");
	
	Sleep(7000);
	return 0;
}
