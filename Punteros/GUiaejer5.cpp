#include "stdio.h"
#include "conio.h"
#define FILAS 3
#define COLUMNAS 2
main() {
int i;
char mat[FILAS][COLUMNAS]= {{1,2},{3,4},{5,6}};
puts("Imprimimos como array:");
for(i=0; i<FILAS*COLUMNAS; i++)
printf("%d\n", (*mat)[i]);
puts("\nImprimimos utilizando punteros:");
for(i=0; i<FILAS*COLUMNAS; i++)
printf("%d\n", (**mat+i)); 
getch();
}
