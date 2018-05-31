/*Se tienen las 4 calificaciones de cada uno de 5 alumnos, se necesita conocer: el promedio de cada estudiante y el promedio de
todos.*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

main ()
{
    float nt[4][2], pt=0.00, sup[4];
    int n, a, ok;
    
    printf("\n\n\tEste programa muestra el promedio de 4 estudiantes");
    Sleep(3000);
    system("cls");
    for(a=0;a<=3;a++)
    {
        printf("\n\n\t*** Notas de alumno %i ***\n",a+1);
        for(n=0;n<=1;n++)
        {
            printf("\n\tIngrese la nota %i:\t",n+1);
            ok = scanf("%f", &nt[a][n]);
            while((ok!=1)||(nt[a][n]<0)||(nt[a][n]>10))
			{
				fflush(stdin);
				printf("\n\n\t*** ERROR ***\n\tDebe ingresar un valor entre 0.00 y 10.00\n\n\tIngrese la nota %i:\t",n+1);
				ok = scanf("%f", &nt[a][n]);
				fflush(stdin);
			}
        }
    }
    system("cls");
    printf("\n\n\t\t*** Resultados ***");
    for(a=0;a<=3;a++)
    {
        sup[a]=0;
        for(n=0;n<=1;n++)
            sup[a]+=nt[a][n];
        printf("\n\n\tNota promedio de %i es: %.2f",a+1,sup[a]/=2);
    }
    for(a=0;a<=3;a++)
    	pt+=sup[a];
    printf("\n\n\n\n\tNota promedio total es: %.2f", pt/4);
    
	Sleep(8000);
    return 0;
}
