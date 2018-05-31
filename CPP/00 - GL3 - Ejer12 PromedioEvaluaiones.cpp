/*Un alumno desea saber cuál será su calificación final en la materia de lógica computacional. La
nota final se obtiene mediante los siguientes porcentajes:
55% El promedio de sus tres notas parciales
30% La nota del examen final
15% La nota de un trabajo ex-aula*/

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define pparc 0.55
#define exfin 0.30
#define texau 0.15

main()
{
	float nt1, nt2, nt3, nf;
	
	printf("\n\n\tIngrese las notas que se le solicitan a continuacion");
	printf("\n\n\tPromedio Parciales: ");
	scanf("%f", &nt1);
	printf("\n\tExamen Final: ");
	scanf("%f", &nt2);
	printf("\n\tTarea Ex-aula: ");
	scanf("%f", &nt3);
	nf=(nt1*pparc)+(nt2*exfin)+(nt3*texau);
	printf("\n\n\tSu promedio final es de: %.2f", nf);
	
	Sleep(5000);
	return 0;
}
