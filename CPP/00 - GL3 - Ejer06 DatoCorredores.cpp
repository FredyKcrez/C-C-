/*Dados los nombres de dos corredores, los cuales realizan carreras de distancia 3 días a la semana,
diseñe un flujograma que tome como datos de entrada la cantidad de millas corridas por los corredores
para cada uno de esos días y que imprima los kilómetros que cada uno de ellos realiza por semana.
Conociendo: 1 milla = 1.6 km*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define km 1.6

main()
{
	char cor1[15], cor2[15];
	float a1=0, a2=0, total1=0, total2=0, conv1, conv2;
	int a, b;
	
	printf("\n\tIngrese el nombre del primer corredor:\t");
	gets(cor1);
	printf("\n\tIngrese el nombre del segundo corredor:\t");
	gets(cor2);
	
	system("cls");
	printf("\n\n\t\tIngrese las millas recorridas por ");
	a=strlen(cor1);
	for(int i=0; i<a; i++)
		printf("%c", cor1[i]);
	printf("\n\n\t\tPrimer dia: ");
	scanf("%f", &a1);
	total1+=a1;
	printf("\n\n\t\tSegundo dia: ");
	scanf("%f", &a1);
	total1+=a1;
	printf("\n\n\t\tTercer dia: ");
	scanf("%f", &a1);
	total1+=a1;
	
	system("cls");
	printf("\n\n\t\tIngrese las millas recorridas por ");
	b=strlen(cor2);
	for(int i=0; i<b; i++)
		printf("%c", cor2[i]);
	printf("\n\n\t\tPrimer dia: ");
	scanf("%f", &a2);
	total2+=a2;
	printf("\n\n\t\tSegundo dia: ");
	scanf("%f", &a2);
	total2+=a2;
	printf("\n\n\t\tTercer dia: ");
	scanf("%f", &a2);
	total2+=a2;
	
	conv1=total1*km;
	conv2=total2*km;
	
	system("cls");
	printf("\n\n\t\t******* Resultados *******");
	printf("\n\n\n\tEl corredor 1: ");
	for(int i=0; i<a; i++)
		printf("%c", cor1[i]);
	printf(" recorrio un total de %.2f kms", conv1);
	printf("\n\n\tEl corredor 2: ");
	for(int i=0; i<b; i++)
		printf("%c", cor2[i]);
	printf(" recorrio un total de %.2f kms", conv2);
	
	Sleep(10000);
    return 0;
}
