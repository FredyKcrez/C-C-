#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define MaxNodos 6
void ImpMatriz(int *);
int ExistenArcos(int *);
void CopiaMatriz(int *, int *);
int MultiplicaMatriz(int*, int*, int*);
void InicializaMat(int *);
void longitudN(int *, int N);

main()
{
int N, s, nfila, ncol, f, c, Dspto;
//Relaciones identificadas en el grafo
int Adyacencia[MaxNodos][MaxNodos]={{0,1,1,1,0,0},
{0,0,1,0,1,1},
{0,0,0,1,1,0},
{0,0,0,0,1,0},
{0,0,0,0,0,1},
{0,0,0,0,0,0},};

// Pesos relacionados al grafo
int MatPesos[MaxNodos] [MaxNodos] = {{0,3,4,6,0,0},
{0,0,2,0,4,3},
{0,0,0,1,3,0},
{0,0,0,0,5,0},
{0,0,0,0,0,2},
{0,0,0,0,0,0},};
int MatResultante[MaxNodos][MaxNodos]= {{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},};
int MatAuxiliar[MaxNodos][MaxNodos]= {{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},
{0,0,0,0,0,0},};
int *MtzAdy=&Adyacencia[0] [0];
int *MtzPes =&MatPesos[0][0];
int *MtzAux =&MatAuxiliar[0][0];
int *MtzRes =&MatResultante[0][0];
//InicializaMat(MtzAdy);
printf("\t=============Matriz de adyacencia=============\n");
ImpMatriz(MtzAdy);
//getch();
printf("\n\t=============Matriz de Pesos=============\n");
ImpMatriz(MtzPes);
//getch();
printf("\n\nDesea buscar algun camino de logintud en el grafo\n1. SI\t 2. NO\n");
scanf("%i", &s);
while((s!=1)&&(s!=2))
{
        printf("Debe digitar 1 o 2\n");
        scanf("%i", &s);
}
if(s==1)
{
        printf("Digite longitud de camino a buscar:\t");
        scanf("%i", &N);
        longitudN(MtzAdy, N);
}
getch();
return 0;
} // Fin del programa del main()

//Muestra las relaciones almacenadas en la matriz de adyacencia
void ImpMatriz(int *MtzX)
{
int nfila,ncol,Dspto;
for(nfila=0; nfila<MaxNodos; nfila++) {
for(ncol=0; ncol<MaxNodos; ncol++)
{
//printf(" F[%d]C[%d]=", nfila, ncol);
Dspto=ncol+(nfila*MaxNodos);
printf("%d", *(MtzX+Dspto));
}
printf("\n");
}
}
// Asigna ceros a las posiciones de la matriz
void InicializaMat(int *MtzAdy )
{
int nfila,ncol,Dspto;
for(nfila=0; nfila<MaxNodos; nfila++) {
for(ncol=0; ncol<MaxNodos; ncol++)
{
Dspto=ncol+(nfila*MaxNodos);
(*(MtzAdy+Dspto))=0;
}
}
}

// Copia el contenido de una matriz en otra
void CopiaMatriz(int *MtzAdy,int *MtzAux)
{
int nfila,ncol,Dspto;
for(nfila=0; nfila<MaxNodos; nfila++)
for(ncol=0; ncol<MaxNodos; ncol++){
Dspto=ncol+(nfila*MaxNodos);
*(MtzAux+Dspto) = *(MtzAdy+Dspto);
}
}

//Verifica si existen conexiones para una matriz resultante
int ExistenArcos(int* MtzAdy)
{
int nfila,ncol,Dspto,Resultado=0;
for(nfila=0; nfila<MaxNodos; nfila++) {
for(ncol=0; ncol<MaxNodos; ncol++){
Dspto=ncol+(nfila*MaxNodos);
if (*(MtzAdy+Dspto)== 1){
nfila=ncol=MaxNodos+1;
Resultado= 1;
}
}
}
return Resultado;
}

// Multiplica dos matrices booleanas y devuelve resultado en Tercera matriz
int MultiplicaMatriz(int* MtzRes, int * MtzAdy, int* MtzAux)
{
int nfila,ncol,DsptoFila,DsptoCol,Resultado=0;
int nf,nc,Contador,nfila1,aux,Dspto;
int AuxFilas[MaxNodos] ;int AuxColum[MaxNodos];
for(nf=0;nf<MaxNodos;nf++){

// Vaciar una fila de la matriz hacia un arreglo unidireccional
for(ncol=0; ncol<MaxNodos; ncol++){
DsptoFila= ncol+(nf*MaxNodos);
AuxFilas[ncol]= *(MtzAdy+DsptoFila);

//printf("%d\t",AuxFilas[ncol]);
}

// Vaciar todas las columnas de la matriz
for(nc=0;nc<MaxNodos;nc++){

// Vaciar una Columna de la matriz hacia un arreglo unidireccional
for(nfila=0; nfila<MaxNodos; nfila ++){
DsptoCol=nc+(MaxNodos* nfila);
AuxColum[nfila]=(*(MtzAux+DsptoCol));
//printf("%d\n",AuxColum[nfila]);
}
//getch();
// Multiplicar una fila por una columna
for(Contador=0; Contador<MaxNodos ; Contador++)
if ((AuxFilas[Contador]== 1) && (AuxColum[Contador]== 1)) {
//printf(" [%d][%d] y [%d][%d] \n" ,nf,Contador,Contador, nc);
Dspto=nc+(nf*MaxNodos);
*(MtzRes+Dspto) = 1;
//printf("Existe Conexion Longitud 2 \n\n");
//printf("%d\t,%d\n",*(MtzRes+Dspto),Dspto);
// Rompe el ciclo al encontrar primera conexion
// Recuerde que es posible encontrar mas de una
Contador=MaxNodos+1;
}
}// Fin del ciclo nc<MaxNodos vaciar todas las columnas
} // Fin del ciclo nf<MaxNodos vaciar todas las filas
return Resultado;
}

void longitudN(int * MtzAdy, int N)
{
     
}
