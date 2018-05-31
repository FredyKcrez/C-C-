/*Dados el nombre y la altura de una persona en centímetros, diseñe un Flujograma que calcule e
imprima a cuanto equivale su altura en pulgadas ( 1 pulg. = 2.54 cms ).*/
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define pulg 2.54

main()
{
	float altcm, altplg;
	int ok;
	char name[30];
	
	printf("\n\n\tSe calculara la altura de una persona en pulgadas");
	printf("\n\n\n\tIngrese el nombre de la persona:\t");
	gets(name);
	printf("\n\n\tIngrese la altura que mide %s en cms:\t", name);
	ok = scanf("%f", &altcm);
	while((ok!=1)||(altcm<=0.00))
    {
     	fflush(stdin);
        printf("\n\t*** Error en dato!! ***\n\tDigite solo valores positivos");
        system("cls");
        printf("\n\n\tIngrese la altura que mide %s en cms:\t", name);
		ok = scanf("%f", &altcm);
        fflush(stdin);
	}
	altplg = altcm/pulg;
	printf("\n\n\n\tLa estatura de %s en pulgadas es de %.2f", name, altplg);
	
	Sleep(5000);
	return 0;
}
