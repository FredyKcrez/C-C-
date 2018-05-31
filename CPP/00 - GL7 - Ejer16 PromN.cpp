/*Diseñe una solución que dadas las notas de un grupo de alumnos (cuya cantidad es conocida) calcule
e imprima la nota promedio*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

main()
{
	float sumN=0.00,prom=0.00,nota;
	int ok,n,i;
	
	printf("\n\n\tIngrese la cantidad de estudiantes a evaluar:\t");
	ok=scanf("%i",&n);
	while((ok!=1)||(n<1))
    {
    	fflush(stdin);
        printf("\a\n\t*** Error. El valor debe ser mayor que 0 ***");
        printf("\n\n\tDigite el dato: ");
        ok=scanf("%d", &n);
        system("cls");
        fflush(stdin);
	}
	system("cls");
	for(i=0;i<n;i++)
	{
		printf("\n\tDigite la nota del %i\247 estudiante: ",i+1);
		ok=scanf("%f",&nota);
		while((ok!=1)||(nota<0.00)||(nota>10.00))
	    {
	    	fflush(stdin);
	        printf("\a\n\t*** Error. La nota debe estar entre 0.00 y 10.00 ***");
	        printf("\n\tDigite el dato: ");
	        ok=scanf("%i", &nota);
	        system("cls");
	        fflush(stdin);
		}
		sumN+=nota;
	}
	prom=sumN/n;
	printf("\n\n\tEl promedio resultante es de %.2f",prom);
	
	Sleep(6000);
	return 0;
}
