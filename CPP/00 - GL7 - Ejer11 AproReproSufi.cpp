/*En la Facultad de Ingeniería y Arquitectura, los alumnos que obtengan una nota de ciclo entre
5.0 y 5.94 inclusive, tiene derecho a realizar un examen de suficiencia con el cual tiene la
opción de aprobar la asignatura. Diseñe un algoritmo que permita conocer a partir de la nota de
ciclo de un grupo de 10 alumnos si el alumno reprobó (sin derecho a suficiencia), reprobó y
califica para hacer el examen de suficiencia ó si aprobó la asignatura. El mínimo para aprobar es
6.0 Además calcule e imprima la nota promedio.*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

main()
{
	char Name[10][20],nameC[20];
	int salir=0,ok,i,k;
	float nota=0.00,promG=0.00,promA[10],sumN=0.00,sumG=0.00;
	
	while(salir<10)
	{
		fflush(stdin);
		printf("\n\n\tDigite los datos del %i\247 estudiante:\n\n\tNombre: ",salir+1);
		gets(nameC);
		for(i=0;i<20;i++)
		{
			if(nameC[i]!='\0')
				Name[salir][i]=nameC[i];
			nameC[i]='\0';
		}
		printf("\n");
		for(k=0;k<3;k++)
		{
			printf("\n\tIngrese la %i nota: ",k+1);
			ok=scanf("%f",&nota);
			while((ok!=1)||((nota<0.00)||(nota>10.00)))
		    {
		    	fflush(stdin);
		        printf("\a\n\t*** Error. La nota debe estar entre 0.00 y 10.00 ***");
		        printf("\n\n\tDigite la nota: ");
		        ok=scanf("%f", &nota);
		        fflush(stdin);
			}
			sumN+=nota;
			nota=0.00;
		}
		promA[salir]=sumN/3.00;
		sumN=0.00;
		system("cls");
		salir++;
	}
	system("cls");
	printf("\n\n\t\t**** RESULATDOS ****\n\n\n");
	for(i=0;i<10;i++)
	{
		printf("\tEl estudiante ");
		k=0;
		while((Name[i][k]!=' ')&&(Name[i][k]!='\0'))
		{
			printf("%c",Name[i][k]);
			k++;
		}
		sumG+=promA[i];
		if(promA[i]<5.00)
			printf(" reprobo la materia\n");
		else
			if(promA[i]>5.94)
				printf(" aprobo la materia\n");
			else
				printf(" tiene derecho a suficiencia\n");
	}
	promG=sumG/10.00;
	printf("\n\n\n\tEl promedio general del grupo es de %.2f",promG);
	
	Sleep(20000);
	return 0;
}
