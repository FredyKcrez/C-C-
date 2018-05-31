/* Programa que imprime promedio de estatura, promedio de edad, estatura de la persona más joven y edad de la persona más alta. */

#include <stdio.h>
#include <conio.h>

main()
{
	int edad,ok,sumaed=0,mened=100,n,i,edalta;
	float est,sumaest=0,mayalt=0, esjoven, esprom, edprom;

	puts("Digite el número de personas:");
	ok=scanf("%i",&n);
	while((ok!=1)||(n<0))
	{
		fflush(stdin);
		puts("Error: Intente de nuevo.");
		ok=scanf("%i",&n);
		fflush(stdin);
	}
	for(i=0;i<n;i++)
	{
		puts("\nDigite la estatura:");
		ok=scanf("%f",&est);
		while((est<=0)||(ok!=1))
		{
			fflush(stdin);
			puts("\n Error: Intente de nuevo.");
			ok=scanf("%f",&est);
			fflush(stdin);
		}
		puts("\nDigite la edad:");
		ok=scanf("%i", &edad);
		while((edad<=0)||(ok!=1))
		{
			fflush(stdin);
			puts("\n Error: Intente de nuevo.");
			ok=scanf("%i",&edad);
			fflush(stdin);
		}
		sumaest=sumaest+est;
		sumaed=sumaed+edad;
		if(mayalt<est)
		{
			mayalt=est;
			edalta=edad;
		}
		if(mened>edad)
		{
			mened=edad;
			esjoven=est;
		}
	}
	esprom=sumaest/n;
	edprom=(float)sumaed/n; // (float)  Convierte a real el resultado de la división de enteros.
	printf("\n\n Edad promedio: %3.2f \n Estatura promedio: %3.2f", edprom, esprom);
	printf("\n Edad de la persona más alta: %d \n Estatura de la persona más joven: %3.2f", edalta, esjoven);

	getch();
	return 0;
}
