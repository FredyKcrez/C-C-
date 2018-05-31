/*CODIFICACIÓN DEL EJEMPLO RESUELTO EN LA GUÍA DE TRABAJO N° 5*/

#include <stdio.h>
#include <conio.h>
#define CC 496.7 //definicion de constantes
#define LE 18.895
#define QU 7.6045
#define CO 22.2250
main()
{
	float Moneda, Moneda_E;
	int Opcion;
	puts("Digite la cantidad en Dolares a convertir: $");
	scanf("%f", &Moneda);
	puts("Elija la moneda a la que se convertirá:");
	printf("\n 1. Colones Costarricenses ");
	printf("\n 2. Lempiras");
	printf("\n 3. Quetzales");
	printf("\n 4. Cordobas");
	printf("Su opcion es:\n");
	scanf("%d", &Opcion);
	if ((Moneda > 0) && (Opcion >= 1 && Opcion <= 4)) // Restriccion
	if (Opcion == 1)
	{
		Moneda_E = Moneda * CC;
		printf("\n*** Cantidad en Dolares: %.2f \n*** Cantidad en Colones Costarricenses: %.2f", Moneda, Moneda_E);
	}
	else
	if (Opcion == 2)
	{
		Moneda_E = Moneda * LE;
		printf("\n*** Cantidad en Dolares: %.2f \n*** Cantidad en Lempiras: %.2f", Moneda, Moneda_E);
	}
	else
	if (Opcion == 3)
	{
		Moneda_E = Moneda * QU;
		printf("\n*** Cantidad en Dolares: %.2f \n*** Cantidad en Quetzales: %.2f", Moneda, Moneda_E);
	}
	else
	{
		Moneda_E = Moneda * CO;
		printf("\n*** Cantidad en Dolares: %.2f \n*** Cantidad en Cordobas: %.2f", Moneda, Moneda_E);
	}
	else // De la Restricción
		printf("\n \n ERROR EN DATOS DE ENTRADA !!!");
	getch();
	return 0;
}
