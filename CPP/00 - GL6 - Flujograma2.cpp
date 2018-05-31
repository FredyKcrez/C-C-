#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define A1 0.25
#define A2 0.2
#define A3 0.1

main()
{
	float Sal_act,aum,Nue_sal;
	int ok;
	
	printf("\n\n\tDigite el salario actual: $");
	ok=scanf("%f",&Sal_act);
	while(ok!=1)
    {
     	fflush(stdin);
     	system("cls");
        printf("\n\t*** Por favor digite un valor positivo ***");
        printf("\n\n Digite el salario: $");
        ok=scanf("\n%f", &Sal_act);
        fflush(stdin);
	}
	if(Sal_act>=0)
	{
		if(Sal_act<201.00)
			aum=Sal_act*A1;
		else
			if(Sal_act<501.00)
				aum=Sal_act*A2;
			else
				aum=Sal_act*A2;
		Nue_sal=Sal_act+aum;
		printf("\n\n\tEl nuevo salario del empleado es de $%.2f",Nue_sal);
	}
	else
		printf("\n\n\t**** El salario no puede ser negativo ****");
	
	Sleep(6000);
	return 0;
}
