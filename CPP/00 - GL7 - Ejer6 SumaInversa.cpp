/*Diseñe una solución que calcule e imprima la suma de los primeros 10 números positivos pero en
orden inverso (10 + 9 + ... +1)*/

#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

main()
{
	int i,sum=0;
	for(i=10;i>0;i--)
		sum+=i;
	system("color 17");
	printf("\n\n\n\t\t*** WAIT ***");
	Sleep(5000);
	system("color 1b");
	system("cls");
	printf("\n\n\tLa sumatoria inversa de los primeros 10 digitos\n\tda un valor de %i",sum);
	
	Sleep(7000);
	return 0;
}
