/*Diseñe un programa que calcule e imprima la superfiicie y el volumen de un cilindro dado su radio
y altura en centimetros*/ 
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#define pi 3.1416

main()
{
	float r, h, area, vol;
	int ok;
	
	system("color 0a");
	printf("\n\n\tSe calculara el Area y Volumen de un cilindro, asi que\n\tproporcione los datos que se le solicitan\n\tPdt: Se trabaja con unidades de centimetro.");
	Sleep(7000);
	system("cls");
	system("color 07");
	printf("\n\n\tRadio (cm): ");
	ok=scanf("%f", &r);
	while(ok!=1)
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Valores Postitivos !! ***");
        printf("\n\n\tRadio (cm): ");
		ok=scanf("%f", &r);
		fflush(stdin);
	}
	printf("\n\n\tAltura (cm): ");
	ok=scanf("%f", &h);
	while(ok!=1)
    {
    	fflush(stdin);
        printf("\n\t*** Por Favor Digite Solo Valores Postitivos !! ***");
        printf("\n\n\tAltura (cm): ");
		ok=scanf("%f", &h);
		fflush(stdin);
	}
	system("cls");
	system("color 0a");
	area=(2*pi*r)*(r+h);
	vol=h*pow(r,2);
	printf("\n\n\tEl cilindro de radio %.2f y altura %.2f posee\n\tlas siguientes dimensiones\n\n\tArea: %.2f (cm^2)\n\n\tVolumen: %.2f (cm^3)", r, h, area, vol);

	Sleep(12000);
	return 0;
}
