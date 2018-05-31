#include<stdio.h>
#include<conio.h>
main()
{
	int a, ok;

	printf("\a\vDigite un numero:\t\b");
	ok=scanf("\n%d", &a);
	printf("%d\r", a);
  	while(ok!=1)
    {
        printf("\tOk %i", ok);
    	fflush(stdin);
        printf("\a\n\t*** Por Favor Digite Solo Numeros !! ***");
        printf("\n\n Digite el dato: ");
        ok=scanf("\n%d", &a);
        fflush(stdin);
	}
	printf("\tOk %i", ok);
	printf("\nEl dato ingresado es: %i",a);
	getch();
}
