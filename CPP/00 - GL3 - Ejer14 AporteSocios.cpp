/*Tres personas deciden invertir su dinero (en $) para fundar su empresa, cada una invierte una 
cantidad distinta. Obtener el porcentaje que cada quien aporta con respecto a la cantidad total
invertida*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	float p1, p2, p3, c1, c2, c3,ct;
	
	printf("\n\n\tIngrese el aporte de cada socio de la empresa\n\tSocio 1: $ ");
	scanf("%f", &c1);
	printf("\n\tSocio 2: $ ");
	scanf("%f", &c2);
	printf("\n\tSocio 3: $ ");
	scanf("%f", &c3);
	ct=c1+c2+c3;
	p1=(c1*100)/ct;
	p2=(c2*100)/ct;
	p3=(c3*100)/ct;
	printf("\n\n\tLa aportacion de cada socio es el siguiente\n\tSocio 1\t\t%.2f\n\tSocio 2\t\t%.2f\n\tSocio 3\t\t%.2f",p1,p2,p3);
	
	Sleep(10000);
	return 0;
}
