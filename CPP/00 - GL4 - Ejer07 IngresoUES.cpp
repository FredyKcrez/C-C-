/*Calcular la nota promedio de un aspirante a ingresar a la UES, sabiendo que el resultado del
examen de aptitudes tiene un porcentaje del 70% y la prueba psicológica tiene un valor del 30%.*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define exA 0.7
#define exP 0.3

main()
{
	float nA,nP,nT;
	int ok;
	
	printf("\n\n\tIngrese la nota obtenida en el Examen de Aptitudes: ");
	ok=scanf("%f",&nA);
	while((ok!=1)||(nA<0.00)||(nA>10.00))
    {
		fflush(stdin);
		system("cls");
		system("color 0b");
        printf("\n\n\n\t*** Debe estar en un rango del 0.00 - 10.00 ***");
        printf("\n\n\t Digite el dato (Ex. Aptit.): ");
        ok=scanf("%f", &nA);
        system("cls");
		system("color 07");
		fflush(stdin);
	}
	printf("\n\n\tIngrese la nota obtenida en la Prueba Psicologica: ");
	ok=scanf("%f",&nP);
	while((ok!=1)||(nP<0.00)||(nP>10.00))
    {
        fflush(stdin);
        system("cls");
        system("color 0b");
        printf("\n\n\n\t*** Debe estar en un rango del 0.00 - 10.00 ***");
        printf("\n\n\t Digite el dato (Prueba Psic.): ");
        ok=scanf("%f", &nP);
        system("cls");
		system("color 07");
        fflush(stdin);
	}
	nT=(nA*exA)+(nP*exP);
	printf("\n\n\tLa nota de su Examen de Aptitud es: %.2f\n\tLa nota de su Prueba Psicologica es: %.2f",nA,nP);
	printf("\n\n\tLa nota promedio de aspirante es de: %.2f",nT);
	Sleep(7000);
	return 0;
}
