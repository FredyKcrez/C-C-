#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define MaxNodos 6

// Funciones:
void ImpMatriz(int *);
int ExistenArcos(int *);
void CopiaMatriz(int *, int *);
int MultiplicaMatriz(int*, int*, int*);
void InicializaMat(int *);
void longitudN(int *, int *, int *, int);
int conexionPQ(int *, int *, int *, int , int );

main()
{
      int N, opc=0, nfila, ncol, b, bandera, Dspto, P, Q;
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
      
      while(opc!=5)
      {
            //pantalla del menu
            printf("\n\n\n\t********** Seleccione la opcion que desea realizar: **********\n\n\n");
            printf("1. Imprimir Matriz adyacente\n");
            printf("2. Imprimir Matriz de pesos\n");
            printf("3. Buscar N longitud de camino\n");
            printf("4. Buscar conexion de P a Q (P-->Q)\n");
            printf("5. Salir\n");
            printf("\nOpcion:\t");
            scanf("%i", &opc);
            while((opc!=1)&&(opc!=2)&&(opc!=3)&&(opc!=4)&&(opc!=5))
            {
                 printf("\n\nLa opcion %i no existe\n", opc);
                 printf("Opcion:\t");
                 scanf("%i", &opc);
            }
      
            switch(opc)
            {
                 //Opciones
                 case 1:
                      printf("\t=============Matriz de adyacencia=============\n");
                      ImpMatriz(MtzAdy);
                      getch();
                      break;
                 
                 case 2:
                      printf("\n\t===============Matriz de Pesos===============\n");
                      ImpMatriz(MtzPes);
                      getch();
                      break;
                 
                 case 3:  //Buscar longitud
                      printf("Digite longitud de camino a buscar:\t");
                      scanf("%i", &N);
                      CopiaMatriz(MtzAdy, MtzAux);
                      longitudN(MtzAdy, MtzAux, MtzRes, N);
                      getch();
                      break;
                      
                 case 4:    //Buscar conexion
                      while(b=1)
                      {
                                printf("\nValores numericos de los nodos:\n");
                                printf("A=1, B=2, C=3, D=4, E=5, F=6)\n");
                                printf("\nDigite el primer nodo:\t");
                                scanf("%d", &P);
                                while((P!=1)&&(P!=2)&&(P!=3)&&(P!=4)&&(P!=5)&&(P!=6))
                                {
                                    printf("\nEse nodo no existe, intente de nuevo:\t");
                                    scanf("%d", &P);
                                }
                                printf("\nDigite el segundo nodo:\t");
                                scanf("%d", &Q);
                                while((Q!=1)&&(Q!=2)&&(Q!=3)&&(Q!=4)&&(Q!=5)&&(Q!=6))
                                {
                                    printf("\nEse nodo no existe, intente de nuevo:\t");
                                    scanf("%d", &Q);
                                }
                                InicializaMat(MtzAux);
                                bandera=conexionPQ(MtzAdy, MtzAux, MtzRes, P, Q);
                      
                                if(bandera==1)
                                    printf("\nSi hay conexion de %i a %i (%i-->%i)", P, Q, P, Q);
                                else
                                    printf("\nNo hay conexion de %i a %i (%i-->%i)", P, Q, P, Q);
                                getch();
                                break;
                      }     
            }
      }
      //Salir del programa
      printf("\n\n\t\t===ADIOS===");
      getch();
      return 0;
}

// Funciones del programa
void ImpMatriz(int *MtzX)
{
     int nfila, ncol, Dspto;
     for(nfila=0; nfila<MaxNodos; nfila++)
     {
        printf("\t\t    ");
        for(ncol=0; ncol<MaxNodos; ncol++)
        {
            Dspto=ncol+(nfila*MaxNodos);
            printf("  %d", *(MtzX+Dspto));
        }
        printf("\n");
     }
}

void InicializaMat(int *MtzAdy)
{
     int nfila,ncol,Dspto;
     for(nfila=0; nfila<MaxNodos; nfila++)
     {
        for(ncol=0; ncol<MaxNodos; ncol++)
        {
            Dspto=ncol+(nfila*MaxNodos);
            (*(MtzAdy+Dspto))=0;
        }
     }
}

void CopiaMatriz(int * MtzAdy,int * MtzAux)
{
     int nfila,ncol,Dspto;
     for(nfila=0; nfila<MaxNodos; nfila++)
         for(ncol=0; ncol<MaxNodos; ncol++)
         {
              Dspto=ncol+(nfila*MaxNodos);
              *(MtzAux+Dspto) = *(MtzAdy+Dspto);
         }
}

int ExistenArcos(int* MtzAdy)
{
    int nfila,ncol,Dspto,Resultado=0;
    for(nfila=0; nfila<MaxNodos; nfila++)
    {
        for(ncol=0; ncol<MaxNodos; ncol++)
        {
           Dspto=ncol+(nfila*MaxNodos);
           if (*(MtzAdy+Dspto)== 1)
           {
               nfila=ncol=MaxNodos+1;
               Resultado= 1;
           }
        }
    }
    return Resultado;
}

int MultiplicaMatriz(int* MtzRes, int * MtzAdy, int* MtzAux)
{
    int nfila,ncol,DsptoFila,DsptoCol,Resultado=0;
    int nf,nc,Contador,nfila1,aux,Dspto;
    int AuxFilas[MaxNodos] ;int AuxColum[MaxNodos];
    for(nf=0;nf<MaxNodos;nf++)
    {
        for(ncol=0; ncol<MaxNodos; ncol++)
        {
                    DsptoFila= ncol+(nf*MaxNodos);
                    AuxFilas[ncol]= *(MtzAdy+DsptoFila);
        }
        for(nc=0;nc<MaxNodos;nc++)
        {
             for(nfila=0; nfila<MaxNodos; nfila ++)
             {
                    DsptoCol=nc+(MaxNodos* nfila);
                    AuxColum[nfila]=(*(MtzAux+DsptoCol));
             }
             for(Contador=0; Contador<MaxNodos ; Contador++)
                    if ((AuxFilas[Contador]== 1) && (AuxColum[Contador]== 1))
                    {
                          Dspto=nc+(nf*MaxNodos);
                          *(MtzRes+Dspto) = 1;
                          Contador=MaxNodos+1;
                    }
        }
    }
    return Resultado;
}

//funcion para calcular N longitud de camino
void longitudN(int * MtzAdy, int * MtzAux, int* MtzRes, int N)
{
     int i, existencia;
     if(N==1)
     {
             printf("\n\t\tMatriz de longitud %d es\n", N);
             ImpMatriz(MtzAdy);
     }
     else
     if(N!=1)
     {
         CopiaMatriz(MtzAdy, MtzAux);
         for (i=1; i<N; i++)
         {
             InicializaMat(MtzRes);
             MultiplicaMatriz(MtzRes, MtzAdy, MtzAux);
             InicializaMat(MtzAux);
             CopiaMatriz(MtzRes,MtzAux);
             existencia=ExistenArcos(MtzRes);
             if (existencia!=1)
             {
                printf("No hay caminos de longitud %d\n", N);
                getch();
                return;
             }
         }
         printf("\n\t\tMatriz de longitud %d es\n", N);
         ImpMatriz(MtzRes);
     }
     getch();
     return ;
}

//funcion para verificar la conexion entre nodos
int conexionPQ(int* MtzAdy, int* MtzAux, int * MtzRes, int P, int Q)
{
     int i, resultado=0, bandera, existencia;
     
     if (*(MtzAdy+P)+Q==1 || *(MtzAdy+Q)+P==1 )
            return resultado=1;
     else 
             bandera=0;
     
     CopiaMatriz(MtzAdy, MtzAux);
     while(bandera==0)
     {
         InicializaMat(MtzRes);
         MultiplicaMatriz(MtzRes, MtzAdy, MtzAux);
         InicializaMat(MtzAux);
         CopiaMatriz(MtzRes, MtzAux);
         if (*(MtzRes+P)+Q==1 || *(MtzRes+Q)+P==1 )
             return resultado=1;
         
         existencia=ExistenArcos(MtzRes);
         if (existencia!=1)
            bandera=1; 
     }
     return resultado;
}
