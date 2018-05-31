/*En la fábrica de bloques KART se produce una cantidad n de bloques (entero positivo), en un
día y se desea saber dado el monto (en $) invertido en mano de obra y monto (en $) en materiales
para producirlo cual es el costo por unidad.*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int n, ok;
	float montMO, montMA, motTOT;
	
	printf("\n\n\tIngrese la cantidad de bloques producidos al dia\n\tn: ");
	ok=scanf("%i",&n);
	while((ok!=1)||(n<=0))
    {
		fflush(stdin);
		system("cls");
        printf("\n\t*** Por favor digite solo valores numericos positivos ***");
        printf("\n\t Digite el dato (n): ");
        ok=scanf("\n%d", &n);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el monto invertido en Mano de Obra\n\tMO: $ ");
	ok=scanf("%f",&montMO);
	while((ok!=1)||(montMO<0))
    {
		fflush(stdin);
        system("cls");
		printf("\n\t*** Por favor digite solo valores numericos positivos ***");
        printf("\n\t Digite el dato (MO): $ ");
        ok=scanf("%f",&montMO);
        fflush(stdin);
	}
	printf("\n\n\tIngrese el monto invertido en Mano de Obra\n\tMA: $ ");
	ok=scanf("%f",&montMA);
	while((ok!=1)||(montMA<0))
    {
		fflush(stdin);
		system("cls");
        printf("\n\t*** Por favor digite solo valores numericos positivos ***");
        printf("\n\t Digite el dato (MA): $ ");
        ok=scanf("%f",&montMA);
        fflush(stdin);
	}
	system("cls");
	motTOT=(montMO+montMA)/n;
	printf("\n\n\tEl costo unitario de cada bloque es de: $%.2f",motTOT);
	Sleep(4000);
	return 0;
}
