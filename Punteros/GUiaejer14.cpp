#include <stdio.h>
#include <conio.h>
main() {
float mat[2][4] = {
{1.45, -2.35, -14.08, 17.3}, //primera fila
{20, 2.95, 0.082, 6.023} //segunda fila
};
int i, j;
puts("Imprimimos las direcciones de memoria y valores contenidos:");
puts("\nDireccción de memoria &mat[i][j] \t\tContenido mat[i][j]");
for(i=0;i<2; i++)
for(j=0; j<4; j++)
printf("\n\t&mat[%d][%d] = %p \t\t\t mat[%d][%d] = %g", i\
,j,&mat[i][j], i,j, mat[i][j]);
getch();
printf("\n\nRepetimos los resultados empleando notación de punteros:\n");
getch();
puts("\nDireccción de memoria *(mat+i)+j \t\tContenido *(*(mat+i)+j)");
for(i=0;i<2; i++)
for(j=0; j<4;j++)
printf("\n\t(mat+%d)+%d = %p \t\t\t *(*(mat+%d)+%d) = %g", i,j, *(mat+i)+j, i,j, *(*(mat+i)+j));
getch();
printf("\n\nVeamos algunos valores (sin escribir i cuando vale cero: ");
printf("\n*(*(mat)) = %g",*(*(mat)));
printf("\n*(*(mat)+1) = %g",*(*(mat)+1));
printf("\n*(*(mat+1)+1) = %g",*(*(mat+1)+1));
getch();
}
