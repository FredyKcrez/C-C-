#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	char nombre[30];
	
	printf("\n\n\t*** Digite su nombre ***\n\n\tNombre:\t");
	gets(nombre);
	printf("\n\n\tHola amigo %s", nombre);
	
	Sleep(5000);
	return 0;
}
