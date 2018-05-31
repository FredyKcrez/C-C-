/*Calcular el promedio final de un alumno a partir de la lectura de tres notas parciales que
tienen la misma ponderación*/

#include <stdio.h>
#include <conio.h>

main( )
{
	float nota_1,nota_2,nota_3, prom,suma;
	
	printf("\n Digite la primera nota (entre 0.0 y 10.0): ");
	scanf("%f", & nota_1);
	printf("\n Digite la segunda nota (entre 0.0 y 10.0): ");
	scanf("%f", & nota_2);
	printf("\n Digite la tercera nota (entre 0.0 y 10.0): ");
	scanf("%f", & nota_3);
	suma = nota_1+ nota_2+ nota_3;
	prom = suma / 3;
	printf("\n\n El promedio final del ciclo es: %.2f", prom);
	getch();
	return 0;
}
