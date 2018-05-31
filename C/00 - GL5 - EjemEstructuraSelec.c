/*Diseñe una solución que dada una cantidad en dólares (USD), le permita tener la opción de conocer
su equivalente ya sea en:
 °Colones costarricenses (CRC)				°Lempiras hondureños (HNL)
 °Quetzales guatemaltecos (GTQ)    ó		°Córdobas nicaragüenses (NIO)
Sabiendo que: Un Dólar equivale a: 496.7 Colones costarricenses, 18.895 Lempiras, 7.6045 Quetzales
y 22.2250 Córdobas*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define CC 496.7
#define LE 18.895
#define QU 7.6045
#define CO 22.2250

main()
{
	float moneda,monedaC;
	int ok,Opcion;
	
	printf("\n\n\tDigite la cantidad en dolares a convertir: $ ");
	ok=scanf("%f",&moneda);
	while((ok!=1)||(moneda<0))
    {
    	fflush(stdin);
    	system("cls");
        printf("\n\t*** Por favor digite solo valores positivos ***");
        printf("\n\n\tDigite el dato: $ ");
        ok=scanf("%f", &moneda);
        system("cls");
        fflush(stdin);
	}
	printf("\n\n\tElija la moneda a la que se convertira:\n\n\t1. Colones Costarricenses.\n\t2. Lempiras.\n\t3. Quetzales.\n\t4. Cordobas.\n\n\tOpcion: ");
	scanf("%i",&Opcion);
	while((Opcion!=1)&&(Opcion!=2)&&(Opcion!=3)&&(Opcion!=4))
    {
    	fflush(stdin);
    	system("cls");
        printf("\n\t*** Por favor escoja solo valores posibles ***");
        printf("\n\n\t1. Colones Costarricenses.\n\t2. Lempiras.\n\t3. Quetzales.\n\t4. Cordobas.\n\n\tOpcion: ");
        ok=scanf("%i", &Opcion);
        system("cls");
        fflush(stdin);
	}
	if(Opcion==1)
	{
		monedaC=moneda*CC;
		printf("\n\n\tDolares: $%.2f convertidos a Colones Costarricenses: %.2f",moneda,monedaC);
	}
	else
		if(Opcion==2)
		{
			monedaC=moneda*LE;
			printf("\n\n\tDolares: $%.2f convertidos a Lempiras: %.2f",moneda,monedaC);
		}
		else
			if(Opcion==3)
			{
				monedaC=moneda*QU;
				printf("\n\n\tDolares: $%.2f convertidos a Quetzales: %.2f",moneda,monedaC);
			}
			else
				if(Opcion==4)
				{
					monedaC=moneda*CO;
					printf("\n\n\tDolares: $%.2f convertidos a Cordobas: %.2f",moneda,monedaC);
				}
	
	Sleep(10000);
	return 0;
}
