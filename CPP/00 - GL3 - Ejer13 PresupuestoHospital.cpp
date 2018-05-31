/*En un hospital existen tres áreas distintas: Ginecobstetricia, Pediatría y Traumatología. El
presupuesto anual del hospital se reparte conforme a la siguiente tabla:
Ginecobstetricia 40%
Pediatría 30%
Traumatología 30%*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define gine 0.4
#define pedi 0.3
#define trau 0.3

main()
{
	float pres_a,presg, presp, prest;
	
	printf("\n\n\tIngrese el presupuesto que recibe el hospital (>0): ");
	scanf("%f", &pres_a);
	presg=pres_a*gine;
	presp=pres_a*pedi;
	prest=pres_a*trau;
	printf("\n\n\tEl presupuesto del hospital se reparte de la siguiente manera:\n\tArea\t\t\tPresupuesto\n\tGinecobstetricia\t%.2f\n\tPediatría\t\t%.2f\n\tTraumatología\t\t%.2f",presg, presp, prest);
	
	Sleep(5000);
	return 0;
}
