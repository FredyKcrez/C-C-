//implementacion en el grafo A del ejercicio 3.4 de la guia de lab.
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MaxNodos 6

//menu
void menu()
{
     //pantalla del menu
     printf("\n\n  ********** Seleccione la opcion que desea realizar: **********\n\n\n");
     printf("  1. Imprimir Matriz de adyacencia y de pesos\n");
     printf("  2. Buscar conexion de P a Q (P-->Q)\n");
     printf("  3. Camino mas corto de P a Q (P-->Q)\n");
     printf("  4. Buscar Longitud de Camino X de P a Q (P-->Q)\n");
     printf("  5. Matriz de pesos acumulados\n");
     printf("  6. Secuencia de vertices yendo de P a Q (P-->Q)\n");
     printf("  7. Salir\n");
}

// Funciones del programa
void ImpMatriz(int *MtzX)
{
     int nfila, ncol, Dspto;
     for(nfila=0; nfila<MaxNodos; nfila++)
     {
        printf("\t\t   ");
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
                printf("\nNo hay caminos de longitud %d\n", N);
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
int conexionPQ(int * MtzAdy, int * MtzAux, int * MtzRes, int P, int Q)
{
     int i,resultado=0, bandera, existencia, Dspto;
     Dspto=Q+(P*MaxNodos);
     
     if (*(MtzAdy+Dspto)==1)
            return resultado=1;
     else 
             bandera=0;
     
     CopiaMatriz(MtzAdy, MtzAux);//empieza a probar si hay conecte en otras longitudes
     while(bandera==0)
     {
                      InicializaMat(MtzRes);
                      MultiplicaMatriz(MtzRes, MtzAdy, MtzAux);
                      InicializaMat(MtzAux);
                      CopiaMatriz(MtzRes, MtzAux);
                      if (*(MtzRes+Dspto)==1)
                           return resultado=1;
                      existencia=ExistenArcos(MtzRes);//verifica si todavia pueden haber mas caminos
                      if (existencia!=1)
                         bandera=1;
     }
     return resultado;
}

//encuentra el camino con menor peso
int minimo(int a, int b, int i, int j, int *MtzPes)
{
    int Dspto;
    
    Dspto=j+(i*MaxNodos);
    if(((*(MtzPes+Dspto))+b) == a)
         return a;
    else
        if(((*(MtzPes+Dspto))+b) > a)
               return a;
    else
        return (*(MtzPes+Dspto))+b;
}

//Calcula el camino mas corto para viajar de un nodo a otro
int caminocorto(int * MtzAdy, int* MtzAux, int* MtzRes, int *MtzPes, int P, int Q)
{
    int i, j, infinito=999, Dspto, V[MaxNodos]={0,1,2,3,4,5}, D[MaxNodos], S[MaxNodos]={0}, menor, v, b;   

    for(i=0; i<MaxNodos; i++)   //Inicializa la matriz de pesos 
    {
             for(j=0; j<MaxNodos; j++)  
             {
                      Dspto=j+(i*MaxNodos);
                      if(i!=j)
                      {
                              if(*(MtzPes+Dspto) == 0)
                                                 *(MtzPes+Dspto)=infinito;
                      }
             }
    }
    S[0]=P;
    i=P;

    for(j=0; j<MaxNodos; j++)  
    {
              Dspto=j+(i*MaxNodos);
              D[j]=*(MtzPes+Dspto);
    }
     
    for(i=1; i<=MaxNodos; i++)
    {
         menor=10000;
         for(j=0; j<MaxNodos; j++)
         {  
            if((D[j]<menor)&&(j!=S[0])&&(j!=S[1])&&(j!=S[2])&&(j!=S[3])&&(j!=S[4])&&(j!=S[5]))
            {
                 menor=D[j];
                 S[i]=j;
            }              
         }
         for(j=0; j<MaxNodos; j++)
         {
            if((V[j]!=S[0])&&(V[j]!=S[1])&&(V[j]!=S[2])&&(V[j]!=S[3])&&(V[j]!=S[4])&&(V[j]!=S[5]))
            {
                   D[j]=minimo(D[j], D[S[i]], S[i], j, MtzPes);
            }  
         }                    
    }
    
    if(D[Q]==999)
          printf("\n  Es imposible ir de %d a %d.", P, Q);
    else
          printf("\n  El costo minimo de ir de %d a %d es:\t%d\n", P, Q, D[Q]);
    getch();
}

int PesAcum(int *MtzAdy, int *MtzAux, int *MtzRes, int *MtzPes, int N)
{
    int result=0, nfila, ncol, Dspto, i, existencia;
    if(N==1){
            for(nfila=0; nfila<MaxNodos; nfila++)
                                   for(ncol=0; ncol<MaxNodos; ncol++)
                                   {
                                               Dspto = ncol + (nfila*MaxNodos);
                                               result += *(MtzPes+Dspto);
                                   }
            return result;
    }
    else
        CopiaMatriz(MtzAdy, MtzAux);
        for (i=1; i<N; i++)
        {
             InicializaMat(MtzRes);
             MultiplicaMatriz(MtzRes, MtzAdy, MtzAux);
             InicializaMat(MtzAux);
             CopiaMatriz(MtzRes,MtzAux);
             existencia=ExistenArcos(MtzRes);
             if (existencia!=1)
                  return 0;
        }
        for(nfila=0; nfila<MaxNodos; nfila++)
                   for(ncol=0; ncol<MaxNodos; ncol++)
                   {
                          Dspto = ncol + (nfila*MaxNodos);
                          if(*(MtzAdy+Dspto)==1)
                              result += *(MtzPes+Dspto);
                   }
    return result;
}
//main
main()
{
      int N, opc=0, nfila, ncol, b, bandera, Dspto, P, Q, w=0;
      //Relaciones identificadas en el grafo
      int Adyacencia[MaxNodos][MaxNodos]={{0,0,0,1,0,0},
      {1,0,1,0,0,1},
      {0,0,0,1,0,0},
      {0,0,0,0,1,0},
      {0,0,0,0,0,0},
      {0,0,0,0,1,0},};
      
      // Pesos relacionados al grafo
      int MatPesos[MaxNodos] [MaxNodos] = {{0,0,0,5,0,0},
      {3,0,2,0,0,5},
      {0,0,0,3,0,0},
      {0,0,0,0,6,0},
      {0,0,0,0,0,0},
      {0,0,0,0,4,0},};
      
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
      
      int *MtzAdy =&Adyacencia[0] [0];
      int *MtzPes =&MatPesos[0][0];
      int *MtzAux =&MatAuxiliar[0][0];
      int *MtzRes =&MatResultante[0][0];
      
      system("cls");
      while(1) 
      {
            do
            {
                  system("color 7");
                  system("cls");
                  menu();
                  printf("\n  Opcion:\t");
                  scanf("%i", &opc);
                  if(opc<1||opc>7)
                  {
                                  printf("\n\n  No existe la opcion %i... Digite de nuevo", opc);
                                  getch();
                  }
            }

            while((opc!=1)&&(opc!=2)&&(opc!=3)&&(opc!=4)&&(opc!=5)&&(opc!=6)&&(opc!=7));
                         system("cls");
            
            system("color 2");
            switch(opc)
            {
                 //Opciones
                 case 1:
                      printf("\t=============Matriz de adyacencia=============\n");
                      ImpMatriz(MtzAdy);
                      printf("\n\t===============Matriz de Pesos===============\n");
                      ImpMatriz(MtzPes);
                      getch();
                      break;
                 
                 case 2: //Buscar conexion
                      while(b=1)
                      {
                                printf("\n Valores numericos de los nodos:\n");
                                printf(" A=0, B=1, C=2, D=3, E=4, F=5\n");
                                printf("\n Digite el primer nodo:  ");
                                scanf("%d", &P);
                                while((P!=1)&&(P!=2)&&(P!=3)&&(P!=4)&&(P!=5)&&(P!=0))
                                {
                                    printf("\n Ese nodo no existe, intente de nuevo:\t");
                                    scanf("%d", &P);
                                }
                                printf("\n Digite el segundo nodo:  ");
                                scanf("%d", &Q);
                                while((Q!=1)&&(Q!=2)&&(Q!=3)&&(Q!=4)&&(Q!=5)&&(Q!=0))
                                {
                                    printf("\n Ese nodo no existe, intente de nuevo:\t");
                                    scanf("%d", &Q);
                                }
                                InicializaMat(MtzAux);
                                bandera = conexionPQ(MtzAdy, MtzAux, MtzRes, P, Q);
                      
                                if(bandera==1)
                                    printf("\n Si hay conexion de %i a %i (%i-->%i)", P, Q, P, Q);
                                else
                                    printf("\n No hay conexion de %i a %i (%i-->%i)", P, Q, P, Q);
                                getch();
                                break;
                      }
                      break;
                 
                 case 3: //camino mas corto
                      while(b=1)
                      {
                                printf("\n  Valores numericos de los nodos:\n");
                                printf("  A=0, B=1, C=2, D=3, E=4, F=5\n");
                                printf("\n  Digite el vertice de partida:\t");
                                scanf("%d", &P);
                                while((P!=1)&&(P!=2)&&(P!=3)&&(P!=4)&&(P!=5)&&(P!=0))
                                {
                                    printf("\n  Ese nodo no existe, intente de nuevo:\t");
                                    scanf("%d", &P);
                                }
                                printf("\n  Digite el vertice de llegada:\t");
                                scanf("%d", &Q);
                                while((Q!=1)&&(Q!=2)&&(Q!=3)&&(Q!=4)&&(Q!=5)&&(Q!=0))
                                {
                                    printf("\n  Ese nodo no existe, intente de nuevo:\t");
                                    scanf("%d", &Q);
                                }
                                InicializaMat(MtzAux);
                                caminocorto(MtzAdy, MtzAux, MtzRes, MtzPes, P, Q);
                                getch();
                                break;
                      }
                      break;
                      
                 case 4:  //Buscar longitud
                      printf("  Digite longitud de camino a buscar:\t");
                      scanf("%i", &N);
                      CopiaMatriz(MtzAdy, MtzAux);
                      longitudN(MtzAdy, MtzAux, MtzRes, N);
                      break;
                      
                 case 5:  //pesos acumulados
                      printf("  Digite la longitud a utilizar para encontrar el peso acumulado:");
                      scanf("%i", &N);
                      w = PesAcum(MtzAdy, MtzAux, MtzRes, MtzPes, N);
                      if(w!=0)
                              printf("\n  El peso acumulado de la longitud %i es: %i", N, w);
                      else
                              printf("  Esa logintud no contiene pesos, no existe!!!!");
                      getch();
                      break;
                      
                 case 6:  //Secuencia de vertices
                      break;
                      
                 case 7://Salir del programa
                      
                      printf("\n\t      ***      *****    **  ******  *****");
                      printf("\n\t     ** **     **  **   **  **  **  **");
                      printf("\n\t    **   **    **   **  **  **  **  *****");
                      printf("\n\t   *********   **  **   **  **  **     **");
                      printf("\n\t  **       **  *****    **  ******  *****");
                      getch();
                      return 0;
            }
      }
      
}
