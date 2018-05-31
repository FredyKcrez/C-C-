/*La Universidad de El Salvador cuenta con 4 facultades con mayor demanda cuyo presupuesto anual
se reparte conforme al siguiente porcentaje:
• Facultad de Ingeniería y Arquitectura 14%
• Facultad de Medicina 12%
• Facultad de Jurisprudencia y Ciencias Sociales 12%
• Facultad de Ciencias Económicas 12%
• Otras Facultades 50%
Diseñe una solución que imprima la cantidad de dinero que le corresponde a cada Facultad.*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define FIA 0.14
#define FM 0.12
#define FJCS 0.12
#define FCE 0.12
#define OF 0.5

main()
{
	float presT;
	int ok;
	
	puts("\n\n\tIngrese el presupuesto asignado para la UES");
	printf("\tPresupuesto: $");
	ok=scanf("%f",&presT);
	while((ok!=1)||(presT<0))
    {
    	fflush(stdin);
        puts("\n\n\t*** Por favor ingrese un valor positivo ***");
        printf("\t Digite el dato: $");
        ok=scanf("\n%f", &presT);
        fflush(stdin);
	}
	system("cls");
	puts("\n\n\tEl presupuesto se reparte de la siguiente manera:");
	printf("\n\tFac. Ing. & Arq.: $%.2f\n\tFac. Medicina: $%.2f\n\tFac. Jur. & C.Soc.: $%.2f\n\tFac. Ciencias Eco.: $%.2f\n\tOtras Fac.: $%.2f",presT*FIA,presT*FM,presT*FJCS,presT*FCE,presT*OF);
	Sleep(20000);
	return 0;
}
