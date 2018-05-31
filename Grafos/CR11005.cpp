#include<conio.h>
#include<stdio.h>
#define MaxNodos 6
#define Infi 99999

void imprMtz(int *MtzX)
{
     int i, j, Dspto;
     
     printf("\n");
     for(i=0; i<MaxNodos; i++)
     {
        for(j=0; j<MaxNodos; j++)
        {
                 Dspto = j+(i*MaxNodos);
                 printf("\t%d", *(MtzX+Dspto));
        }
        printf("\n");
     }
     
     getch();
}

void copiaMtz(int *MtzA, int *MtzB)
{
     int i, j, Dspto;
     for(i=0; i<MaxNodos; i++)
        for(j=0; j<MaxNodos; j++)
        {
                 Dspto = j+(i*MaxNodos);
                 *(MtzB+Dspto) = *(MtzA+Dspto);
        }
}

int caminominimo(int a, int b)
{
    if(a==b)
            return a;
    else
        if(b > a)
             return a;
        else
            if(b<a)
                 return b;
}

void algoirtmoFloyd(int *MtzPes, int *MtzAux)
{
     int i, j, k, Dspto;
     
     for(i=0; i<MaxNodos; i++)
         for(j=0; j<MaxNodos; j++)
         {
               Dspto = j+(i*MaxNodos);
               if(i!=j)
                       if(*(MtzPes+Dspto)==0)
                            *(MtzPes+Dspto) = Infi;   //Agregando un valor imposible
         }

     copiaMtz(MtzPes, MtzAux);
     for(k=1; k<MaxNodos; k++)
        for(i=0; i<MaxNodos; i++)
            for(j=0; j<MaxNodos; j++)
            {
                     Dspto = j+(i*MaxNodos);
                     *(MtzAux+Dspto) = caminominimo((*(MtzAux+Dspto)), (*(MtzAux+(k+(i*MaxNodos)))) + (*(MtzAux+(j+(k*MaxNodos)))));
            }
     imprMtz(MtzAux);
     
     printf("\n\n\tEl costo minimo para ir de A -> E es: %d", *(MtzAux+(4+(0*MaxNodos))));
}

main()
{
      int MtzAdyacencia[MaxNodos][MaxNodos]= {{0,1,1,0,0,0},
          {0,0,0,0,1,0},
          {0,0,0,0,1,0},
          {1,0,0,0,0,0},
          {0,0,0,1,1,0},
          {0,0,0,0,0,1}};
      
      int MtzPesos[MaxNodos][MaxNodos] = {{0,1,2,0,0,0},
          {0,0,0,0,4,0},
          {0,0,0,0,5,0},
          {3,0,0,0,0,0},
          {0,0,0,6,7,0},
          {0,0,0,0,0,7}};
          
      int MtzAuxiliar[MaxNodos][MaxNodos] = {{0,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,0,0},
          {3,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,0,0}};
      
      int *MtzAdy = &MtzAdyacencia[0][0];
      int *MtzPes = &MtzPesos[0][0];
      int *MtzAux = &MtzAuxiliar[0][0];
      
      printf("\n\n\t\t<<Matriz de Adyacencia>>\n");
      imprMtz(MtzAdy);
      printf("\n\n\n\t\t<<Matriz resultante de Floyd>>\n");
      algoirtmoFloyd(MtzPes, MtzAux);
      
      getch();
      return 0;
}
