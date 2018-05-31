/*Dado como dato la nota de ciclo de un alumno, diseñe una solución que determine si el alumno
aprobó o reprobó, siendo la nota mínima de aprobación 6.0*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	float nota;
	int ok;
	
	puts("\n\n\tIngrese la nota de ciclo del estudiante");
	printf("\n\tNota: ");
	ok=scanf("%f",&nota);
	while((ok!=1)||(nota<0.00)||(nota>10.00))
    {
    	fflush(stdin);
    	system("cls");
        puts("\n\n\t*** Por favor ingrese un valor entre 0.00 y 10.00 ***");
        printf("\n\tDigite la nota: ");
        ok=scanf("\n%f", &nota);
        fflush(stdin);
	}
	system("cls");
	if(nota>=6.00)
		puts("\n\n\tEl alumno aprobo la materia");
	else
		puts("\n\n\tEl alumno reprobo la materia");
	
	Sleep(7000);
	return 0;
}
