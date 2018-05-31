/*Diseñe un Flujograma que imprima la cantidad en colones salvadoreños que existen en una
cantidad dada en Dólares Canadienses, si: USD$ 1 = ¢ 8.75 y CAD$ 1 = USD $ 0.99*/
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define USD 0.99
#define SVD 8.75

main()
{
	float colones, $can, $nort;
	printf("\n\t*** Conversion de Dolares Canadienses a Colones Salvadoreños ***");
	printf("\n\n\tIngrese la cantidad a convertir: $ ");
	scanf("%f", &$can);
	$nort=$can*USD;
	colones=$nort*SVD;
	printf("\n\n\tResultado: ¢ %.2f", colones);
	Sleep(6000);
	return 0;
}
