#include <stdio.h>
#include <conio.h>

main()
{
     int a;
     int *punt; //declaración de puntero.
     a=57; //inicialización de variable
     punt=&a; //asignación de dirección al puntero.
     printf("a = %d", a); //imprimo valor de variable
     printf("\n&a = %x", &a); //imprimo dirección variable apuntada (en hexadecimal)
     printf("\npunt = %x ", punt); //imprimo la dirección guardada (la de la variable apuntada)
     printf("\n*punt = %d", *punt); //imprimo el contenido de la dirección apuntada.
     printf("\ntama¤o puntero %d", sizeof(punt));
     
     getch();
     return 0;
}
