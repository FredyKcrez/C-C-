#include <stdio.h>
#include <conio.h>

main()
{
     int a;
     int *punt; //declaraci�n de puntero.
     a=57; //inicializaci�n de variable
     punt=&a; //asignaci�n de direcci�n al puntero.
     printf("a = %d", a); //imprimo valor de variable
     printf("\n&a = %x", &a); //imprimo direcci�n variable apuntada (en hexadecimal)
     printf("\npunt = %x ", punt); //imprimo la direcci�n guardada (la de la variable apuntada)
     printf("\n*punt = %d", *punt); //imprimo el contenido de la direcci�n apuntada.
     printf("\ntama�o puntero %d", sizeof(punt));
     
     getch();
     return 0;
}
