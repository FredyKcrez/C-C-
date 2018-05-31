/* GL03 - Ejemplo 5: Diseñe una solucion que permita dar a conocer el salario a pagar a un empleado,
sabiendo que se le descuebta el 3% de ISSS y que se le da el 10% de comision por venta */

#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define ISSS 0.03

main()
{
	char Nom_Emp[30];
	int ok, i=0;
	float sueldo, porc_isss, porc_com, salario;
	
	printf("\n\n\tIntroduzca el nombre del empleado...\n\tNombre: ");
	gets(Nom_Emp);
	printf("\n\n\tDigite el salario base...\n\n\tSalario Base: $ ");
	ok = scanf("%f", &sueldo);
	while((ok!=1)||(sueldo<0))
	{
		system("cls");
        fflush(stdin);
        printf("\n\t*** El salario debe ser mayor que cero [>0] !! ***\n\n\tSalario Base: $ ");
        ok = scanf("%f", &sueldo);
        fflush(stdin);
    }
    porc_isss = sueldo*ISSS;
    porc_com = sueldo*0.10;
    salario = sueldo-porc_isss+porc_com;
    system("cls");
    printf("\n\n\tEl/la empleado(a) ");
    while((Nom_Emp[i]!=' ')&&(Nom_Emp[i]!=0))
	{
		printf("%c", Nom_Emp[i]);
		i++;
	}
	printf(" recibe un salario de $ %.2f", salario);
	Sleep(7000);
	return 0;
}
