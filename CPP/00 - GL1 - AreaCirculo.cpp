/*Programa para calcular el area de un circulo*/
#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()		//Cabecera de funcion
{
	float Radio, Area;      //Declaracion de variables
	int ok;
	
	printf("\n\n\t*** Ingrese los valores que se le solicitan ***\n\n\tRadio:\t");
	ok=scanf("%f",&Radio);
	while((ok!=1)||(Radio<0))		//Validacion de lectura de dato
    {
    	fflush(stdin);
    	system("cls");
    	fflush(stdin);
		printf("\n\t*** Por Favor Digite Solo Numeros Positivos ***");
        printf("\n\n\tDigite el Radio:\t");
        ok=scanf("%f",&Radio);
        fflush(stdin);
	}
	Area=Radio*3.1416;
	printf("\n\n\tArea de la circunferencia:\t%.4f", Area);
	
	Sleep(6000);
	return 0;
}
