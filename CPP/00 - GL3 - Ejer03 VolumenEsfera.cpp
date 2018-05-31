/*Diseñe un Flujograma, que calcule y despliegue el volumen de una esfera dado su radio en
centímetros*/
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#define pi 3.1416

main()
{
	float vol, radio;
	int ok;
	
	printf("\n\n\t*** Calculo del volumen de una esfera ***\n\n\tIngrese el radio de la esfera\n\n\tRadio (cms): ");
	ok=scanf("%f", &radio);
	while((ok!=1)||(radio<0.00))
    {
          system("cls");
		  fflush(stdin);
          printf("\n\t*** Por Favor Digite Solo Valores positivos !! ***");
          printf("\n\n\tRadio: ");
          ok=scanf("%f", &radio);
          fflush(stdin);
	}
	vol=(4*pi*pow(radio,3))/3;
	system("cls");
	printf("\n\n\t\t\t*** Resultados ***\n\n\tEl cono de radio %.2f posee un volumen de:\n\n", radio);
	system("color 2");
	printf("\n\n\t\t****** %.2f (cms^3) ******", vol);

	Sleep(5000);
	return 0;
}
