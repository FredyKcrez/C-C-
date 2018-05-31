/*El siguiente es el programa del problema ejemplo, que en la guía Nº 3 se ha planteado,
analizado y se ha diseñado su Solución*/

#include <stdio.h>
#include <conio.h>
#define ISSS 0.03 //Definicion de constante

main()
{
	/* Declaracion de Variables */
	char Nom_Emp[50];
	float Sueldo, Porc_isss, Porc_com, Salario;
	
	/* Entrada de Datos */
	printf("\n Introduzca el Nombre del Empleado: ");
	scanf("%s", Nom_Emp); //Notese que no lleva & por ser cadena de caracteres o dato alfanumérico
	printf("\n Digite el Sueldo Base (Debe de ser > que cero): $");
	scanf("%f", &Sueldo);
	
	/* Proceso o calculos a hacer */
	Porc_isss = Sueldo * ISSS;
	Porc_com = Sueldo * 0.10;
	Salario = Sueldo - Porc_isss + Porc_com;
	
	/* Impresion de Resultados*/
	printf("\n\n\tNombre del Empleado: %s", Nom_Emp);
	printf("\n\n\tSalario a Recibir: $ %.2f", Salario);
	getch();
	return 0;
}
