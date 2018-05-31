#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main()
{
	float x, s;
	int ok;
	
	printf("\n\n\tIngrese un valor numerico a trabajar:\n\n\tValor:\t");
	ok = scanf("%f", &x);
	while(ok!=1)
	{
		fflush(stdin);
		system("cls");
		printf("\n\n\t\t*** El valor ingresado no es valido ***");
		printf("\n\n\tIngrese un valor numerico a trabajar:\n\n\tValor:\t");
		ok = scanf("%f", &x);
		fflush(stdin);
	}
	system("cls");
	printf("\n\n\t\t*** Operaciones sobre %.2f ****", x);
	if(x>=0)
		printf("\n\n\tValor absoluto:\t %.4f \n\tRaiz cuadrada:\t %.4f \n\tSeno:\t %.4f \n\tCoseno:\t %.4f \n\tTangente:\t %.4f \n\tExponencial:\t %.4f \n\tLogaritmo Neperiano:\t %.4f \n\tLogaritmo Decimal:\t %.4f \n\tPotenciacion (^3):\t %.4f \n\t", s=abs(x), s=sqrt(x), s=sin(x), s=cos(x), s=tan(x), s=exp(x), s=log(x), s=log10(x), s=pow(x,3));
	else
		printf("\n\n\tValor absoluto:\t %.4f \n\tRaiz cuadrada:\t %.4f (i) \n\tSeno:\t %.4f \n\tCoseno:\t %.4f \n\tTangente:\t %.4f \n\tExponencial:\t %.4f \n\tLogaritmo Neperiano:\t Indefinido \n\tLogaritmo Decimal:\t Indefinido \n\tPotenciacion (^3):\t %.4f \n\t", s=abs(x), s=sqrt(abs(x)), s=sin(x), s=cos(x), s=tan(x), s=exp(x), s=pow(x,3));
		
	getch();
	return 0;
}
