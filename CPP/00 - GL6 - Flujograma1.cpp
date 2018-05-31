#include<conio.h>
#include<stdio.h>
#include<windows.h>

main()
{
	int fi,ok,n1,n2;
	printf("\n\n\tIngrese dos numeros enteros, uno en cada linea:\n\t");
	ok=scanf("%i",&n1);printf("\t");
	fi=scanf("%i",&n2);
	while((ok!=1)||(fi!=1))
    {
		system("cls");
		fflush(stdin);
        puts("\n\t*** Por favor digite solo numeros enteros ***");
        printf("\n\tDigite los valores:\n\t");
        ok=scanf("%i",&n1);printf("\t");
		fi=scanf("\t%i",&n2);
		fflush(stdin);
	}
	if((n1>0)&&(n2>0))
	{
		if(n1==n2)
			printf("\n\n\t** Ambos valores son iguales **");
		else
			if(n1>n2)
				printf("\n\n\t** El primer valor es mayor que el segundo **");
			else
				printf("\n\n\t** El primer valor es menor que el segundo **");
	}
	else
		printf("\n\n\t** Al menos un dato es negativo **");
	
	Sleep(7000);
	return 0;
}
