/*Se tomó la estatura en metros de varias personas, además, se conoce la edad de cada persona. Se
requiere un algoritmo que calcule la edad promedio y la estatura promedio. Además, se necesita
conocer la edad de la persona más alta, y la estatura de la persona más joven*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int ok,i,edalta,n,sumaed=0,mened=100,edad;
	float sumaest=0.00,mayalt=0.00,est,esjoven,edprom,esprom;
	
	printf("\n\n\tDigite el numero de personas:\t");
	ok=scanf("%i",&n);
	while((ok!=1)||(n<=0))
    {
    	fflush(stdin);
    	system("cls");
        printf("\n\t*** Error, Intente de nuevo ***");
        printf("\n\n\tDigite el dato: ");
        ok=scanf("%d", &n);
        fflush(stdin);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\n\tDigite la estatura de la %i persona:\t",i);
		ok=scanf("%f",&est);
		while((ok!=1)||(est<=0.00))
	    {
	    	fflush(stdin);
	    	system("cls");
	        printf("\n\t*** Error, Intente de nuevo ***");
	        printf("\n\n\tDigite el dato: ");
	        ok=scanf("%f", &est);
	        fflush(stdin);
		}
		printf("\n\tDigite la edad de la %i persona:\t",i);
		ok=scanf("%i",&edad);
		while((ok!=1)||(edad<=0))
	    {
	    	fflush(stdin);
	    	system("cls");
	        printf("\n\t*** Error, Intente de nuevo ***");
	        printf("\n\n\tDigite el dato: ");
	        ok=scanf("%d", &edad);
	        fflush(stdin);
		}
		sumaest+=est;
		sumaed+=edad;
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
	edprom=sumaed/n;
	system("cls");
	printf("\n\n\t**** Informacion recolectada ****");
	printf("\n\n\tEdad promedio: %.2f\n\tEstatura promedio: %.2f\n\tEdad de la persona mas alta: %i\n\tEstatura de la persona mas joven: %.2f\n\t",edprom,esprom,edalta,esjoven);
	
	Sleep(10000);
	return 0;
}
