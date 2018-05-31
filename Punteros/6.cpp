#include "stdio.h"
#include "conio.h"
main() {
int i,j;
int *p[4]; //array de punteros//
int **px=p; //px es un puntero a un puntero//
printf("Introduzca 16 valores enteros\n");
for (i=0; i<4; i++)
for (j=0; j<4; j++)
scanf ("%d", *(px+i)+j);
for (i=0; i<4; i++)
{
for (j=0; j<4; j++)
printf("%7d", *(*(px+i)+j));
printf("\n");
}
getch();
}
