/*Diseñe un flujograma que calcule y despliegue el salario en Dólares Americanos de un empleado,
si se le descuenta el 10% para la Renta, el 7% para el pago de AFP y 3% para el pago del ISSS,
considerando que la entrada de datos es el sueldo en dólares americanos (debe ser mayor que 0.0)
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define renta 0.10
#define afp 0.07
#define isss 0.03

main()
{
	float salini, salfin;
	int ok;
	
	printf("\n\n\t\tIngrese Sueldo del empleado a costear:\n\n\t\t$ ");
	ok=scanf("%f", &salini);
	while((ok!=1)||(salini<0))
    {
    	fflush(stdin);
    	system("cls");
        printf("\n\t*** Por Favor Digite Solo Numeros Mayores a 0.00 ***");
        printf("\n\n\t\t Digite el saldo: $ ");
        ok=scanf("%f", &salini);
        fflush(stdin);
	}
	salfin=salini-(salini*renta)-(salini*afp)-(salini*isss);
	system("cls");
	printf("\n\n\t\tEl saldo que el empleado recibe es de $ %.2f", salfin);
	
	Sleep(7000);
    return 0;
}
