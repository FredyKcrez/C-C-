/* calcula el número combinatorio */

#include <stdio.h>
#include <conio.h>

long leer(void);
long factorial(long n);

main()
{
	long ne, tm, fact1, fact2, fact3, com;
	
	printf("\n\nIngrese los datos en el siguiente orden:");
	printf("\n\t 1. Cantidad de elementos");
	printf("\n\t 2. Tamaño de la muestra");
	ne=leer();
	tm=leer();
	fact1=factorial(ne);
	fact2=factorial(tm);
	fact3=factorial(ne-tm);
	com=fact1/(fact2*fact3);
	printf("\n\nEl numero de combinaciones posibles es: %i",com);
	
	getch();
	return 0;
}

long leer(void)
{
	long dato;
	printf("\n\n\nDigite el numero entero: ");
	scanf("%i",&dato);
	while(dato<0)
	{
		printf("\nError: intente denuevo. ");
		scanf("%i",&dato);
	}
	return dato;
}

long factorial(long n)
{
	long f;
	int i;
	f=1;
	if(n>=2)
	{
		for(i=2; i<=n; i++)
			f=f*i;
	}
	return f;
}
