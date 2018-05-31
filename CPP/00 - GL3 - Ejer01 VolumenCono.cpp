//Desarrollo de expresiones matematicas
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#define pi 3.1416

main()
{
	float vol, radio, alt;
	int ok;
	
	printf("\n\n\t*** Calculo del volumen de un cono ***\n\n\tIngrese radio y altura del cono\n\n\tRadio: ");
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
	printf("\n\n\tAltura: ");
	ok=scanf("%f", &alt);
	while((ok!=1)||(alt<0.00))
    {
          system("cls");
		  fflush(stdin);
          printf("\n\t*** Por Favor Digite Solo Valores positivos !! ***");
          printf("\n\n\tAltura: ");
          ok=scanf("%f", &alt);
          fflush(stdin);
	}
	vol=(pi*pow(radio,2)*alt)/3;
	system("cls");
	printf("\n\n\t\t\t*** Resultados ***\n\n\tEl cono de radio %.2f y altura %.2f posee un volumen de:\n\n", radio, alt);
	system("color 2");
	printf("\n\n\t\t****** %.2f (mt^3) ******", vol);

	Sleep(5000);
	return 0;
}
