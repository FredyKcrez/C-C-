//Copyright Joham Vanwilliam Cruz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pilas.h"
#include "lista.h"
#include "colas.h"
#define INF 99999
#define MaxNodos 6
#define SI_NODO_NO_EXISTE 1
#define SI_NO_GENERA_CICLO 0

int NODOS[2];//Nodo partida, Nodo destino
int ELECCION;

//Prototipo de funciones
void ImpMatriz(int *);
int ExistenArcos(int *);
int ExisteConexion(int *, int, int);
void CopiaMatriz(int *, int *);
void MultiplicaMatriz(int*, int*, int*, int*, int*, int*, int);
void InicializaMat(int *);
int menu_inicial(void);
char* menu(int);
int AnalizarNodos(char*, char*);
void longitudX (int*, int*, int*, int*, int*, int*, int);
int CaminoCorto (int*, int*, int*, int*, int* , int* , int, int, int);
int minimo (int, int);
int algo_dijkstra (int, int* , int);
int algo_warshall (int*, int*, int , int);
int algo_floyd(int*, int*, int, int);
int funcion_warshall(int, int, int, int*);
int matriz_simetrica(int*);

/* Imprimir el recorrido del grafo */
void mostrar_recorrido (int lista[], int NP, int i)
{
  int contador=0,j;
  if(lista[0] != NP)
  printf("\n\n\tLista Vacia");
  printf("\t");
  for(j=0;j<i;j++)
  {
           contador++;
           if(lista[j] == 0)printf("A");
           if(lista[j] == 1)printf("B");
           if(lista[j] == 2)printf("C");
           if(lista[j] == 3)printf("D");
           if(lista[j] == 4)printf("E");
           if(lista[j] == 5)printf("F");  
           if(j != (i-1))
           printf("-> ");
           if(contador%10 == 0)
           printf("\n\t");
  }
  printf("\n");
}

//Muestra secuencias de vertices segun caminos escogidos
Lista mostrar_secuencias(int* MtzAdy, int* MtzPes,int algo)
{
     int i,j;
     Lista *LA,*LB,*LC,*LD,*LE,*LF;
     if ((LA = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     if ((LB = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     if ((LC = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     if ((LD = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     if ((LE = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     if ((LF = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     inicializacion(LA); inicializacion(LB); inicializacion(LC);
     inicializacion(LD); inicializacion(LE); inicializacion(LF);
     for(i=0;i<MaxNodos;i++)
     for(j=0;j<MaxNodos;j++)
         if(*(MtzAdy + j +(i*MaxNodos))==1)
         {
               if(i==0)
               {
                        if(LA->tamano == 0)                              
                        ins_en_lista_vacia(LA,i,j,*(MtzPes + j + (i*MaxNodos)));                
                        else                                               
                        ins_fin_lista(LA,LA->fin,i,j,*(MtzPes + j + (i*MaxNodos)));
               }
               if(i==1)
               {
                        if(LB->tamano == 0)                              
                        ins_en_lista_vacia(LB,i,j,*(MtzPes + j + (i*MaxNodos)));                
                        else                                               
                        ins_fin_lista(LB,LB->fin,i,j,*(MtzPes + j + (i*MaxNodos)));
               }
               if(i==2)
               {
                        if(LC->tamano == 0)                              
                        ins_en_lista_vacia(LC,i,j,*(MtzPes + j + (i*MaxNodos)));                
                        else                                               
                        ins_fin_lista(LC,LC->fin,i,j,*(MtzPes + j + (i*MaxNodos)));
               }
               if(i==3)
               {
                        if(LD->tamano == 0)                              
                        ins_en_lista_vacia(LD,i,j,*(MtzPes + j + (i*MaxNodos)));                
                        else                                               
                        ins_fin_lista(LD,LD->fin,i,j,*(MtzPes + j + (i*MaxNodos)));
               }
               if(i==4)
               {
                        if(LE->tamano == 0)                              
                        ins_en_lista_vacia(LE,i,j,*(MtzPes + j + (i*MaxNodos)));                
                        else                                               
                        ins_fin_lista(LE,LE->fin,i,j,*(MtzPes + j + (i*MaxNodos)));
               }
               if(i==5)
               {
                        if(LF->tamano == 0)                              
                        ins_en_lista_vacia(LF,i,j,*(MtzPes + j + (i*MaxNodos)));                
                        else                                               
                        ins_fin_lista(LF,LF->fin,i,j,*(MtzPes + j + (i*MaxNodos)));
               }
               
         }
         Element *actual;
         //me retorna la lista de adyacencia  que necesito
         if(algo == 0)
         return *LA;
         if(algo == 1)
         return *LB;
         if(algo == 2)
         return *LC;
         if(algo == 3)
         return *LD;
         if(algo == 4)
         return *LE;
         if(algo == 5)
         return *LF;
}

//sirve para comprobar si el nodo me formara un ciclo en el arbol de expansion o si existe en una lista
int sin_ciclos(Element *nodo, Lista *listaAE, int algo)
{
    int i, N=2, control = 0, resultado = 1, control2 = 0,t1,cont2 = 2;
    Element *actual, *temp1, *temp2, *aux;
    temp1 = NULL;
    temp2 = NULL;
    aux = NULL;
    actual = listaAE->inicio;
    for(i=0;i<N;i++)
    {
        temp1 = aux;
        aux = NULL;
        if(i>0)
        actual = temp1;
        while(actual != NULL)
        {
             if(algo == SI_NO_GENERA_CICLO)//si necesito encontrar meramente ciclos
             {
                 //captura los nodos que se van a comparar posteriormente
                 if(control==0 || control2==2)
                 if(actual->NodoPartida == nodo->NodoPartida || actual->NodoDestino == nodo->NodoPartida || actual->NodoPartida == nodo->NodoDestino || actual->NodoDestino == nodo->NodoDestino)
                 {
                    if(temp1 == NULL && temp2 != actual)
                    {
                        temp1=actual;
                        control2 = 1;
                    }
                 }
                 if(control==0 || control2==1)
                 if(actual->NodoPartida == nodo->NodoPartida || actual->NodoDestino == nodo->NodoPartida || actual->NodoPartida == nodo->NodoDestino || actual->NodoDestino == nodo->NodoDestino)
                 {
                    if(temp2== NULL && temp1 != actual)
                    {
                        temp2=actual;
                        control2 = 2;
                        N++;
                        if(aux==NULL)
                        aux = temp2;
                    }
                 }
                 if(temp1!=NULL && temp2!=NULL)//se asegura si ya estan los nodos a comparar
                 {
                     /*if(nodo->NodoPartida==3 && nodo->NodoDestino == 4)
                                       {
                                           printf("\n\n\ttemp1->NodoPartida(%d) == temp2->NodoPartida(%d)",temp1->NodoPartida, temp2->NodoPartida);
                                           printf("\n\ttemp1->NodoPartida(%d) == temp2->NodoDestino(%d)",temp1->NodoPartida, temp2->NodoDestino);
                                           printf("\n\ttemp1->NodoDestino(%d) == temp2->NodoPartida(%d)",temp1->NodoDestino, temp2->NodoPartida);
                                           printf("\n\ttemp1->NodoDestino(%d) == temp2->NodoDestino(%d)",temp1->NodoDestino, temp2->NodoDestino);
                                           getch(); 
                                       }*/
                     //guarda en una variable el vertice que se esta comparando para verificar que no forme parte del nodo pasado como argumento
                     if (temp1->NodoPartida == temp2->NodoPartida)
                     t1 = temp1->NodoPartida;
                     if (temp1->NodoPartida == temp2->NodoDestino)
                     t1 = temp1->NodoPartida;
                     if (temp1->NodoDestino == temp2->NodoPartida)
                     t1 = temp1->NodoDestino;
                     if (temp1->NodoDestino == temp2->NodoDestino)
                     t1 = temp1->NodoDestino;
                     if((t1 != nodo->NodoPartida) && (t1 != nodo->NodoDestino))
                     {
                           resultado = 0;
                           actual=listaAE->fin;
                     }
                 }
             }
             else
             {
                 //comprueba si el nodo pasado como argumento ya esta en la lista
                 if((nodo->NodoPartida == actual->NodoPartida || nodo->NodoPartida == actual->NodoDestino) && (nodo->NodoDestino == actual->NodoPartida || nodo->NodoDestino == actual->NodoDestino))
                 {
                       resultado = 0;
                       actual=listaAE->fin;
                 }
             }
             actual = actual->siguiente;
             temp2=NULL;
        }//fin del while
    }//fin del for
    return resultado;
}//fin de sin_ciclos

//Comprobar si un vertice ya esta en un vector
int Pertenece_a_Vector (int nodo, int S[])
{
     int i, resultado = 0;
     for(i=0;i<MaxNodos;i++)
     if(nodo == S[i])
     resultado = 1;
     return resultado;
}

//Recorrido en anchura del grafo
void recorrido_anchura(int NP, int* MtzAdy)
{
     int Visitados[MaxNodos], LR[MaxNodos],cont = 1, i=0;
     Lista *LAux;
     Element *actual;
     NodoCola a;
     if ((LAux = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     inicializacion(LAux);
     Cola ColaRecorrido;
     VaciaC(&ColaRecorrido);
     AnadeC(&ColaRecorrido,NP);//insertar el nodo origen en la cola
     Visitados[0] = NP;
     do
     {                                
         a = PrimeroC(ColaRecorrido);
         LR[i]=a.vertice;         
         BorraC(&ColaRecorrido);
         *LAux = mostrar_secuencias(MtzAdy,MtzAdy,LR[i]);
         //Se pasa dos veces MtzAdy solo por cuestiones de programacion (no afecta a la funcion)
         actual = LAux->inicio;
         while(actual != NULL)
         {
              if(Pertenece_a_Vector(actual->NodoDestino,Visitados) == 0)
              {
                  AnadeC(&ColaRecorrido,actual->NodoDestino);
                  Visitados[cont] = actual->NodoDestino;
                  cont++;
              }
              actual = actual ->siguiente;
         }
         i++;
     }while(!EsVaciaC(ColaRecorrido));
     printf("\n\n\tLista Resultante:\n\n");
     mostrar_recorrido(LR,NP,i);
}

//recorrido en profundidad de un grafo
int recorrido_profundidad(int NP, int* MtzAdy, int indicador)
{
     int Visitados[MaxNodos], LR[MaxNodos], Vertices[MaxNodos],cont = 1,i=0,j;
     Element *actual; pNodo actual_pila;
     Lista *LAux; Pila PilaRecorrido;
     if ((LAux = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     inicializacion(LAux); inicializarPila(&PilaRecorrido);
     for(j=0;j<MaxNodos;j++)
     Vertices[j]=j;
     push(&PilaRecorrido,NP);
     Visitados[0]=NP;
     do
     {
         if(Pertenece_a_Vector(UltimoP(&PilaRecorrido),LR) == 0)
         {
              LR[i]=UltimoP(&PilaRecorrido);
              i++;
         }
         actual_pila = PilaRecorrido.ultimo;
         *LAux = mostrar_secuencias(MtzAdy,MtzAdy,actual_pila->vertice);
         //Se pasa dos veces MtzAdy solo por cuestiones de programacion (no afecta a la funcion)
         actual = LAux->inicio;
         if(actual == NULL)
         pop(&PilaRecorrido);
         while(actual!=NULL)
         {
              if(Pertenece_a_Vector(actual->NodoDestino,Visitados) == 0)
              {
                   push(&PilaRecorrido,actual->NodoDestino);
                   Visitados[cont] = actual->NodoDestino;
                   cont++;
                   actual = NULL;
              }
              else
              {
                  if(actual->siguiente == NULL)
                  pop(&PilaRecorrido);
                  actual = actual->siguiente;
              }
         } 
     }while(!empty(&PilaRecorrido));
     if(indicador!=0)
     {
         printf("\n\n\tLista Resultante:\n\n");
         mostrar_recorrido(LR,NP,i);
     }
     //FIN de RECORRIDO en PROFUNDIDAD 
     
     //SABER SI SE ALCANZARON TODOS LOS NODOS
     cont=0;
     int retorno = 0;
     for(i=0;i<MaxNodos;i++)
     if(Pertenece_a_Vector(LR[i],Vertices))
     cont++;
     if(cont == MaxNodos)
     retorno = 1;
     return retorno;
}


//si un grafo es conexo
int grafo_conexo(int *MtzAdy)
{
    int i,resultado = 0;
    for(i=0;i<MaxNodos;i++)
    {
         resultado = recorrido_profundidad(i,MtzAdy,0);
         if(resultado == 1)
         return resultado;
    }
    return resultado;
}

//Devuelve el menor valor del vector D utilizado en el algoritmo de Dijkstra    
int menor_valor (int D[], int contador)
{
    int i,j,aux, retorno, AUX[MaxNodos];
    for(i=0;i<MaxNodos;i++)
    AUX[i]=D[i];    
    for(i=0;i<MaxNodos-1;i++)
    for(j=i+1;j<MaxNodos;j++)
    {
        if(AUX[j]>AUX[i])
        {
            aux=AUX[j];
            AUX[j]=AUX[i];
            AUX[i]=aux;
        }
    }
    
    retorno = AUX[MaxNodos-2-contador];
    
    return retorno;
}

//ordena una lista unidireccional segun costos del grafo
void ordenar(Lista *lista)
{
     int arreglo[MaxNodos*MaxNodos], i, aux, j, contador=0,var;
     int cont = 0;
     Element *actual; 
     Lista *listaAux;
     if ((listaAux = (Lista *) malloc (sizeof (Lista))) == NULL) exit(1);
     inicializacion(listaAux);
     actual=lista->inicio;
     while(actual!=NULL)
     {
         if (listaAux->tamano == 0)
         ins_en_lista_vacia(listaAux,actual->NodoPartida,actual->NodoDestino,actual->Costo);
         else
         ins_fin_lista(listaAux,listaAux->fin,actual->NodoPartida,actual->NodoDestino,actual->Costo);
         actual=actual->siguiente;
     }
     actual = listaAux->inicio;
    while(actual!=NULL)
    {
         arreglo[contador]= actual->Costo;
         actual=actual->siguiente;
         var = ++contador;
    }
    destruir(lista);
        for(i=0; i<(contador-1); i++)
        for (j=i+1; j<contador; j++)
        {
            if(arreglo[j]>arreglo[i])
            {
                aux=arreglo[j];
                arreglo[j]=arreglo[i];
                arreglo[i]=aux;
            }
        }
    for(i=0;i<var;i++)
    {
        actual = listaAux->inicio;
        while(actual!=NULL)
        {
             if(arreglo[i] == actual->Costo)
                 if (lista->tamano == 0)
                 {
                       if(sin_ciclos(actual,lista,SI_NODO_NO_EXISTE) == 1)
                       {
                           ins_en_lista_vacia(lista,actual->NodoPartida,actual->NodoDestino,actual->Costo);
                           cont++;
                           break;
                       }
                 }
                 else
                 {
                       if(sin_ciclos(actual,lista,SI_NODO_NO_EXISTE) == 1) 
                       {
                           ins_inicio_lista(lista,actual->NodoPartida,actual->NodoDestino,actual->Costo);
                           cont++;
                           break;
                       }    
                 }
             actual=actual->siguiente;
        }
        if(cont == var)
        i=var;
    }
}


int comparar_vertices(int U[], int* MtzPes, int* MtzAdy, Lista *lista, Lista *listaAristasDisponibles)
{
     int i,k,AuxFila[MaxNodos],costo,coste;
     int v, u, resultado, resultado2;
     Element *nodo, *nuevo;
     if ((nuevo = (Element *) malloc (sizeof (Element))) == NULL)
     exit(1);
     //llenado de la lista que contiene las aristas disponibles a agregar
     for(i=0;i<MaxNodos;i++)
     {
           if(Pertenece_a_Vector(i,U)==1)
           {
                  for(k=0;k<MaxNodos;k++)
                  {
                      if((*(MtzAdy + k +(i*MaxNodos))) == 1)
                      {
                             costo = *(MtzPes + k + (i*MaxNodos));
                             if(listaAristasDisponibles->tamano == 0)
                             ins_en_lista_vacia(listaAristasDisponibles,i,k,costo); 
                             else
                             {
                                   nuevo->NodoPartida = i;
                                   nuevo->NodoDestino = k;
                                   nuevo->Costo = costo;
                                   resultado = sin_ciclos(nuevo,listaAristasDisponibles,SI_NODO_NO_EXISTE);
                                   if(resultado == 1)
                                   ins_fin_lista(listaAristasDisponibles,listaAristasDisponibles->fin,i,k,costo);
                             }  
                      }
                  }
           }
     }
     printf("\n\n\tLISTAS DE ARISTAS DISPONIBLES\n");
     mostrar(listaAristasDisponibles);
     ordenar(listaAristasDisponibles);//Ordena la lista segun costos de menor a mayor
     printf("\n\n\tLISTAS DE ARISTAS DISPONIBLES ORDENADAS\n");
     mostrar(listaAristasDisponibles);
     nodo = listaAristasDisponibles->inicio;
     while(nodo!=NULL)
     {
            resultado = sin_ciclos(nodo,lista,SI_NO_GENERA_CICLO);
            resultado2 = sin_ciclos(nodo,lista,SI_NODO_NO_EXISTE);
            if((resultado == 1) && (resultado2 == 1))
            {
                   u = nodo->NodoPartida;
                   v = nodo->NodoDestino;
                   coste = nodo->Costo;
                   nodo = listaAristasDisponibles->fin;
            }
            nodo = nodo->siguiente;
     }
     printf("\n\tu = %d",u);
     printf("\n\tv = %d",v);
     printf("\n\tcoste = %d",coste);              
     NODOS[0] = v; //El vertice destino
     NODOS[1] = u; //El vertice origen
     destruir(listaAristasDisponibles);
     return coste; //El Costo
}

//algoritmo de prim para arbol de expansion de costos minimos
void algo_prim(Lista *lista, int* MtzPes, int* MtzAdy)
{
     Lista *listaAristasDisponibles;
     if ((listaAristasDisponibles = (Lista *) malloc (sizeof (Lista))) == NULL)
     exit(1);
     inicializacion(listaAristasDisponibles);
     int U[MaxNodos], K=0, i, menor_costo;
     for(i=0;i<MaxNodos;i++)
     U[i] = INF;
     for(i=1;i<MaxNodos;i++)
     {
           U[0]=0;
           menor_costo = comparar_vertices(U,MtzPes,MtzAdy,lista,listaAristasDisponibles);
           U[i] = NODOS[0];
           if (lista->tamano == 0)
           ins_en_lista_vacia (lista, NODOS[1],NODOS[0], menor_costo);
           else
           ins_fin_lista (lista,lista->fin,NODOS[1],NODOS[0], menor_costo);
           destruir(listaAristasDisponibles);
           printf("\n\n\tLISTA DE ARBOL DE EXPANSION DE COSTOS MINIMOS: \n\n");
           mostrar(lista);
           printf("\n\t---------------------------------------------------------------");
           getch();
     }
     return;
}

//algoritmo de kruskal para arbol de expansion de costos minimos
void algo_kruskal(Lista *lista, int* MtzPes)
{
     Lista *listaAE;
     if ((listaAE = (Lista *) malloc (sizeof (Lista))) == NULL)
     exit(1);
     inicializacion(listaAE);
     int i,j,controlador=1,resultado;
      for(i=0;i<MaxNodos;i++)
      {
          for(j=controlador;j<MaxNodos;j++)
          {     
               if (lista->tamano == 0)
               {   
                   if( *(MtzPes+j+(i*MaxNodos)) != 0)
                   if( *(MtzPes+j+(i*MaxNodos)) !=INF)
                   ins_en_lista_vacia(lista,i,j,*(MtzPes+j+(i*MaxNodos)));
               }
               else if( *(MtzPes+j+(i*MaxNodos)) != 0)
               if(*(MtzPes+j+(i*MaxNodos)) !=INF)
               ins_fin_lista(lista,lista->fin,i,j,*(MtzPes+j+(i*MaxNodos)));
          }
          controlador++;
      } 
      printf("\n\n\tLISTA DE ARISTAS: \n\n");
      mostrar(lista);
      ordenar(lista);
      printf("\n\n\tLISTA ORDENADA: \n\n");
      mostrar(lista);
      Element *actual = lista->inicio;
      for(i=0;i<lista->tamano;i++)
      {
            if(i>1)
            {
                resultado = sin_ciclos(actual,listaAE,SI_NO_GENERA_CICLO);
                if(resultado == 1)
                ins_fin_lista(listaAE,listaAE->fin,actual->NodoPartida,actual->NodoDestino,actual->Costo);
            }
            else
            {
                if(listaAE->tamano == 0)
                ins_en_lista_vacia(listaAE,actual->NodoPartida,actual->NodoDestino,actual->Costo);
                else
                ins_fin_lista(listaAE,listaAE->fin,actual->NodoPartida,actual->NodoDestino,actual->Costo);
            }
      actual = actual->siguiente;
      }
      printf("\n\n\tLISTA DE ARBOL DE EXPANSION DE COSTOS MINIMOS: \n\n");
      mostrar(listaAE);
      return;
}



int main()
{
    int nfila, ncol, f, c, Dspto, X, i, algo;
    Lista *lista;
    Element *actual;
    if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)
    return -1;
    inicializacion(lista);
    char* opcion; 
    opcion = (char*) malloc (5*sizeof(char));
    char* NP; // NP = Nodo de partida
    NP = (char*) malloc (5*sizeof(char));
    char* ND; // ND = Nodo de destino
    ND = (char*) malloc (5*sizeof(char));
    //Relaciones identificadas en el grafo
    int Adyacencia[MaxNodos][MaxNodos]={{0,0,1,0,0,0},
    {0,0,0,0,1,0},
    {0,0,0,1,1,0},
    {0,0,0,0,1,0},
    {0,0,0,1,0,0},
    {0,0,1,1,0,0},};
    // Pesos relacionados al grafo
    int MatPesos[MaxNodos] [MaxNodos] = {{0,3,4,INF,8,INF},
    {INF,0,INF,INF,5,INF},
    {INF,INF,0,INF,3,INF},
    {INF,INF,INF,0,INF,INF},
    {INF,INF,INF,7,0,3},
    {INF,INF,INF,2,INF,0},};
    //Relaciones identificadas en el grafo no dirigido
    int AdyacenciaNoDir[MaxNodos][MaxNodos]={
    {0,1,0,1,0,0},
    {1,0,1,0,0,1},
    {0,1,0,1,0,0},
    {1,0,1,0,1,0},
    {0,0,0,1,0,1},
    {0,1,0,0,1,0},};
    // Pesos relacionados al grafo no dirigido
    int MatPesosNoDir[MaxNodos][MaxNodos] = {
    {0,3,INF,4,INF,INF},
    {3,0,2,INF,INF,5},
    {INF,2,0,3,INF,INF},
    {4,INF,3,0,6,INF},
    {INF,INF,INF,6,0,4},
    {INF,5,INF,INF,4,0},};
    int MatResultante[MaxNodos][MaxNodos]= {{0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},};
    int MatPesosAcumulado[MaxNodos][MaxNodos]= {{0,0,0,0,0,0},
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
    int MatAuxiliarPesos[MaxNodos][MaxNodos]= {{0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},};
    int *MtzAdy=&Adyacencia[0][0];
    int *MtzPes =&MatPesos[0][0];
    int *MtzAdyNoDir=&AdyacenciaNoDir[0][0];
    int *MtzPesNoDir =&MatPesosNoDir[0][0];
    int *MtzAux =&MatAuxiliar[0][0];
    int *MtzRes =&MatResultante[0][0];
    int *MtzPesAcum = &MatPesosAcumulado[0][0];
    int *MtzAuxPes = &MatAuxiliarPesos[0][0];
    int verif, bandera_inicial=0;
    while(bandera_inicial == 0)
    {
        int bandera = 0;
        ELECCION = menu_inicial();
        if(ELECCION==3)
           bandera = bandera_inicial = 1;
        while(bandera == 0)
        {   
            if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)
            return -1;
            inicializacion(lista);
            system("cls");
            opcion=menu(ELECCION);
                    if((strcmp(opcion,"a"))==0)// si opcion es igual a "a"
                    {
                             printf("\tMatriz de adyacencia\n");
                             ImpMatriz(MtzAdy);
                             if(ELECCION == 1)
                             {
                                  printf("\n\tMatriz de Pesos\n");
                                  ImpMatriz(MtzPes);
                                  printf("\n\tMatriz de Pesos No Dirigido\n");
                                  ImpMatriz(MtzPesNoDir);
                             }
                             getch();
                             system("cls");
                    }
                    else if((strcmp(opcion,"b"))==0)
                    {
                             printf("\n\tLista de los vertices (nodos):\n");
                             printf("\n\tA - B - C - D - E - F\n");
                             printf("\n\tDigite el nodo de partida: ");
                             fflush(stdin);
                             gets(NP);
                             printf("\n\tDigite el nodo de destino: ");
                             fflush(stdin);
                             gets(ND);
                             verif = AnalizarNodos(NP,ND);
                             if (verif == 2) 
                             verif = ExisteConexion(MtzAdy,NODOS[0],NODOS[1]);
                             if (verif == 1)
                             printf("\n\tExiste conexion entre los nodos escogidos");
                             if (verif == 0)
                             printf("\n\tNO Existe conexion entre los nodos escogidos");
                             getch();
                             system("cls");
                    }
                    else if((strcmp(opcion,"c"))==0)
                    {
                             printf("\n\tLista de los vertices (nodos):\n");
                             printf("\n\tA - B - C - D - E - F\n");
                             printf("\n\tDigite el nodo de partida: ");
                             fflush(stdin);
                             gets(NP);
                             printf("\n\tDigite el nodo de destino: ");
                             fflush(stdin);
                             gets(ND);
                             verif = AnalizarNodos(NP,ND);                  
                             if (verif == 2)
                             {
                                 verif = ExisteConexion(MtzAdy,NODOS[0],NODOS[1]);
                                 if (verif == 1)//Se analiza primero si el nodo partida y el nodo destino son adyacentes
                                 {
                                       int camino = CaminoCorto(MtzAdy, MtzRes, MtzAux, MtzPes, MtzPesAcum, MtzAuxPes,verif,NODOS[0],NODOS[1]);
                                       printf("\n\tEl camino mas corto entre %s y %s es: %d", NP,ND,camino);
                                 }
                                 if (verif == 0)//Si el NP y el ND no son adyacentes se procede con sus adyacentes
                                 {
                                       int camino = CaminoCorto(MtzAdy, MtzRes, MtzAux, MtzPes, MtzPesAcum, MtzAuxPes,verif+2,NODOS[0],NODOS[1]);         
                                       printf("\n\tEl camino mas corto entre %s y %s es: %d", NP,ND,camino);
                                 }
                             }
                             else
                             {
                                 verif = ExisteConexion(MtzAdy,NODOS[0],NODOS[1]);
                                 printf("\n\tNO Existe conexion entre los nodos escogidos");
                             }
                             getch();
                             system("cls");
                             
                    }
                    else if((strcmp(opcion,"d"))==0)
                    {
                             printf("\n\tDigite la longitud de camino que desea encontrar: ");
                             scanf("%d",&X);
                             printf("\n\tMatriz de Longitud %d\n",X);
                             longitudX(MtzAdy, MtzRes, MtzAux, MtzPes, MtzPesAcum, MtzAuxPes,X);
                             ImpMatriz(MtzRes);
                             getch();
                             system("cls");
                    }
                    else if((strcmp(opcion,"e"))==0  && (ELECCION == 1))
                    {
                             printf("\n\tDigite la longitud de camino \n\tpara mostrar su correspondiente matriz de peso acumulada -> ");
                             scanf("%d",&X);
                             longitudX(MtzAdy,MtzRes,MtzAux,MtzPes,MtzPesAcum, MtzAuxPes,X);
                             ImpMatriz(MtzPesAcum);
                             getch();
                             system("cls");
                    }
                    else if((strcmp(opcion,"f"))==0)
                    {
                             printf("\n\tDigite la longitud de camino \n\tpara mostrar las secuencias correspondientes -> ");
                             scanf("%d",&X);
                             printf("\n");
                             mostrar_secuencias(MtzAdy,MtzPes,X);
                             printf("\nPor el momento no esta completa la funcion...");
                             getch();
                             system("cls");
                    }
                    else if((strcmp(opcion,"g"))==0)//ARBOL DE EXPANSION
                    {
                            if(ELECCION == 1)
                            {
                                 if(matriz_simetrica(MtzPesNoDir)==1)//Comprobar si la matriz pertenece a un grafo NO Dirigido
                                 {
                                     printf("\n\tCual algoritmo desea utilizar?\n");
                                     printf("\n\t1- Prim.\n\t2- Kruskal.\n\n\t-> ");
                                     scanf("%d",&algo);
                                     if(algo == 1)
                                     algo_prim(lista,MtzPesNoDir,MtzAdyNoDir);
                                     else if(algo == 2)
                                     algo_kruskal(lista,MtzPesNoDir);
                                     else
                                     printf("\n\tERROR AL DIGITAR EL NODO");
                                     destruir(lista);
                                 }
                                 else
                                 {
                                     printf("\n\n\tLa matriz ingresada no pertenece a un grafo no dirigido.");
                                     printf("\n\tCorriga la matriz a modo que sea simetrica con la diagonal.");
                                 }                                                     
                            }
                            else
                            printf("\n\tSe necesita un GRAFO VALORADO NO DIRIGIDO.");
                            getch();
                            system("cls");
                    }
                    else if((strcmp(opcion,"h"))==0)//WARSHALL
                            {
                                printf("\n\tLista de los vertices (nodos):\n");
                                printf("\n\tA - B - C - D - E - F\n");
                                printf("\n\tDigite el nodo de partida: ");
                                fflush(stdin);
                                gets(NP);
                                printf("\n\tDigite el nodo de destino: ");
                                fflush(stdin);
                                gets(ND);
                                AnalizarNodos(NP,ND);//NODOS[0] = NP  NODOS[1] = ND
                                algo = algo_warshall(MtzAdy,MtzAux,NODOS[0],NODOS[1]);
                                if(algo == 1)
                                printf("\n\n\tSi existe un camino entre %s y %s",NP,ND);
                                else
                                printf("\n\n\tNo existe un camino entre %s y %s",NP,ND);
                                getch();
                                system("cls");
                            }
                    else if((strcmp(opcion,"i"))==0)//RECORRIDOS
                            {
                                printf("\n\tLista de los vertices (nodos):\n");
                                printf("\n\tA - B - C - D - E - F\n");
                                printf("\n\tDigite el nodo de partida: ");
                                fflush(stdin);
                                gets(NP);
                                strcpy(ND,"C");//se agrega por cuestiones de programacion
                                AnalizarNodos(NP,ND);//NODOS[0] = NP  NODOS[1] = ND
                                printf("\n\n\tCual recorrido desea utilizar: ");
                                printf("\n\t1- Anchura.\n\t2- Profundidad.\n\n\t-> ");
                                scanf("%d",&algo);
                                if(algo == 1)
                                recorrido_anchura(NODOS[0],MtzAdy);
                                else if(algo == 2)
                                recorrido_profundidad(NODOS[0],MtzAdy,1);
                                getch();
                                system("cls");
                            }
                    else if((strcmp(opcion,"j"))==0)//SI UN GRAFO ES CONEXO
                            {
                                algo = grafo_conexo(MtzAdy);
                                if(algo == 1)
                                printf("\n\tEL GRAFO ES CONEXO. ");
                                else
                                printf("\n\tEL GRAFO NO ES CONEXO. ");
                                getch();
                                system("cls");
                            }
                    else if((strcmp(opcion,"k"))==0)//SALIR
                            {
                                bandera = 1;
                                system("cls");
                            }
                    else
                    {
                           printf("\n\tOpcion invalida!!!");
                           getch();
                           system("cls");
                    }
                            
            } //fin bandera
        }//fin bandera inicial                                      
    return 0;
} // Fin del programa del main()
//Muestra las relaciones almacenadas en la matriz de adyacencia
void ImpMatriz(int *MtzX)
{
    int nfila,ncol,Dspto;
    for(nfila=0; nfila<MaxNodos; nfila++) {
    for(ncol=0; ncol<MaxNodos; ncol++)
    {
        Dspto=ncol+(nfila*MaxNodos);
        if(*(MtzX+Dspto) != INF)
        printf(" %d ", *(MtzX+Dspto));
        else
        printf(" %c ", 240);
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


//verifica si una matriz es simetrica con respecto a la diagonal
int matriz_simetrica (int* MtzPesNoDir)
{
    int i,j,k = 0,z = 0,cont = 0,res = 0;
    for(i=0;i<MaxNodos;i++)
    {
        for(j=0;j<MaxNodos;j++)
        {
              /*printf("\n\n\tM[%d][%d]:(%d)  ==  M[%d][%d]:(%d)",i,j,*(MtzPesNoDir + j + (i*MaxNodos)),k,z,*(MtzPesNoDir + z + (k*MaxNodos)));
              getch();*/
              if(*(MtzPesNoDir + j + (i*MaxNodos)) == *(MtzPesNoDir + z + (k*MaxNodos)))
              cont++;
              k++;
        }
        z++;
        k = 0;
    }
    if(cont == (MaxNodos*MaxNodos))
    res = 1;
    
    return res;
}

// Multiplica dos matrices booleanas y devuelve resultado en Tercera matriz
void MultiplicaMatriz(int* MtzRes, int* MtzPes, int* MtzAux, int* MtzAdy, int* MtzPesAcum, int* MtzAuxPes)
{
int nfila,ncol,DsptoFila,DsptoCol;
int nf,nc,Contador,nfila1,Dspto;
int AuxFilas[MaxNodos] ;int AuxColum[MaxNodos]; int PesosFilas[MaxNodos];
int PesosColum[MaxNodos];
for(nf=0;nf<MaxNodos;nf++){
    // Vaciar una fila de la matriz hacia un arreglo unidireccional
    for(ncol=0; ncol<MaxNodos; ncol++){
    DsptoFila= ncol+(nf*MaxNodos);
    AuxFilas[ncol]= *(MtzAdy+DsptoFila);
    PesosFilas[ncol]= *(MtzPes+DsptoFila);
    }
    // Vaciar todas las columnas de la matriz
    for(nc=0;nc<MaxNodos;nc++){
        // Vaciar una Columna de la matriz hacia un arreglo unidireccional
        for(nfila=0; nfila<MaxNodos; nfila ++){
        DsptoCol=nc+(MaxNodos* nfila);
        AuxColum[nfila]=(*(MtzAux+DsptoCol));
        PesosColum[nfila]=(*(MtzAuxPes+DsptoCol));
        }
        // Multiplicar una fila por una columna
        for(Contador=0; Contador<MaxNodos ; Contador++)
        if ((AuxFilas[Contador]== 1) && (AuxColum[Contador]== 1)) 
        {
        Dspto=nc+(nf*MaxNodos);
        *(MtzRes+Dspto) = 1;
        //Acumular el peso
        *(MtzPesAcum+Dspto) = *(MtzPesAcum+Dspto) + PesosFilas[Contador] + PesosColum[Contador] + *(MtzPes+ (nc+(Contador*MaxNodos)));
        Contador=MaxNodos+1;
        }
    }// Fin del ciclo nc<MaxNodos vaciar todas las columnas
} // Fin del ciclo nf<MaxNodos vaciar todas las filas
return;
}

int menu_inicial()
{
    int opcion;
    printf("\n\t\t\tMENU INICIAL\n");
    printf("\n\t1) GRAFO VALORADO");
    printf("\n\t2) GRAFO NO VALORADO");
    printf("\n\t3) SALIR");
    printf("\n\n\t\t Seleccione una opcion-> ");
    scanf("%d",&opcion);
    return opcion;
}

char* menu(int opcion)
{
     char* seleccion;
     seleccion = (char*) malloc (5*sizeof(char));// Esto es solamente para asignar memoria a la variable seleccion
     printf("\n\t\t\t\tMENU\n");
     if(opcion == 1)
     printf("\n\ta) Mostrar matrices de adyacencia y pesos.");
     else
     printf("\n\ta) Mostrar matriz de adyacencia.");
     
     
     printf("\n\tb) Identificar la existencia de conexion entre un vertice P y otro Q.");
     printf("\n\tc) Encontrar el camino mas corto entre pares de nodos escogidos.");
     printf("\n\td) Encontrar caminos de longitud x, entre pares de nodos.");
     
     if(opcion == 1)
     printf("\n\te) Encontrar matrices de pesos acumulados (segun longitud).");
     
     
     printf("\n\tf) Mostrar secuencias de vertices para caminos indicados por el usuario");
     printf("\n\tg) Encontrar arbol de expansion de costos minimos.");
     printf("\n\th) Identificar si existe conexion entre P y Q directa o indirectamente.");
     printf("\n\ti) Recorrer el grafo (Anchura o Profundidad).");
     printf("\n\tj) Determinar si un grafo es conexo.");
     printf("\n\tk) Salir al menu inicial.");
     printf("\n\n\t\t Seleccione una opcion-> ");
     fflush(stdin);
     gets(seleccion);
     return seleccion;
}

int AnalizarNodos(char* NP, char* ND)
{
     int nfila, ncol, verif,comprobar;
     if((strcmp(NP,"A"))==0)nfila=0;
     else if((strcmp(NP,"B"))==0)nfila=1;
     else if((strcmp(NP,"C"))==0)nfila=2;
     else if((strcmp(NP,"D"))==0)nfila=3;
     else if((strcmp(NP,"E"))==0)nfila=4;
     else if((strcmp(NP,"F"))==0)nfila=5;
     else
     {
          printf("\n\tERROR!!! Digite un nodo de partida de la lista en mayusculas...");
          return verif = -1;
     }
     //Nodo de destino
     if((strcmp(ND,"A"))==0)ncol=0;
     else if((strcmp(ND,"B"))==0)ncol=1;
     else if((strcmp(ND,"C"))==0)ncol=2;
     else if((strcmp(ND,"D"))==0)ncol=3;
     else if((strcmp(ND,"E"))==0)ncol=4;
     else if((strcmp(ND,"F"))==0)ncol=5;
     else
     {
          printf("\n\tERROR!!! Digite un nodo de destino de la lista en mayusculas...");
          return verif = -1;
     }
     NODOS[0] = nfila;
     NODOS[1] = ncol;
     return verif = 2;
}
                         
//verifica si existe conexion entre un nodo P y un nodo Q
int ExisteConexion(int* MtzAdy, int nfila, int ncol)
{
    int Dspto,Resultado=0;
    Dspto=ncol+(nfila*MaxNodos);
    if (*(MtzAdy+Dspto)== 1)
       Resultado = 1;
    return Resultado;
}

//Modificar la Matriz de Pesos Acumulados y la Matriz de Longitud de Camino X
void longitudX (int* MtzAdy, int* MtzRes, int* MtzAux, int* MtzPes, int* MtzPesAcum, int* MtzAuxPes, int X)
{
     int i;
     CopiaMatriz(MtzAdy,MtzAux);
                         if(X>1)
                            for(i=0;i<X-1;i++)
                            {
                                InicializaMat(MtzRes);
                                InicializaMat(MtzPesAcum);
                                MultiplicaMatriz(MtzRes, MtzPes, MtzAux, MtzAdy, MtzPesAcum, MtzAuxPes);
                                CopiaMatriz(MtzRes,MtzAux);
                                CopiaMatriz(MtzPesAcum,MtzAuxPes);
                            }
                         else 
                         {
                             if (X==1)
                                  {
                                      CopiaMatriz(MtzPes,MtzPesAcum);
                                      CopiaMatriz(MtzAdy,MtzRes);
                                  }
                             else
                                 printf("\n\tError de datos\n");
                         }
                         
}

//Retorno el camino mas corto entre un nodo P y un nodo Q
int CaminoCorto (int* MtzAdy, int* MtzRes, int* MtzAux, int* MtzPes, int* MtzPesAcum, int* MtzAuxPes, int X, int NP, int ND)
{
    int camino, i, algo;
         longitudX(MtzAdy, MtzRes, MtzAux, MtzPes, MtzPesAcum, MtzAuxPes,X);
         int Dspto = ND+(NP*MaxNodos);
         if (ELECCION == 1)
         {
             printf("\n\tCual algoritmo desea utilizar?\n");
             printf("\n\t1- Dijkstra.\n\t2- Floyd.\n\n\t-> ");
             scanf("%d",&algo);
             if(algo == 1)
             return algo_dijkstra(NP,MtzPes,ND);
             else if(algo == 2)
             return algo_floyd(MtzPes,MtzPesAcum,NP,ND);
         }
         else
         return camino = *(MtzRes + Dspto);
}


int algo_dijkstra (int NP, int* MtzPes, int NQ)
{
    int S[MaxNodos], D[MaxNodos], i, v, w, camino;
    int ncol,Dspto, j, contador = 0;
    for(ncol=0; ncol<MaxNodos; ncol++)
        {
         Dspto=ncol+(NP*MaxNodos);
         D[ncol]=(*(MtzPes+Dspto));
        }
    S[0]=NP;//Se agrega Nodo origen a vector S
    for(i=1;i<MaxNodos;i++)
    {
         for(j=0;j<MaxNodos;j++) //Elegir v en (V-S), D[v] es el minimo valor
         {
              if( (D[j] == menor_valor(D,contador)))
              {
                  v = j;
                  S[i] = v;
                  j = MaxNodos;
              }
         }
         for(j=0;j<MaxNodos;j++) //Repetir para cada vértice w en (V-S)
         {
              if( (Pertenece_a_Vector(j,S) == 0))
              {
                  w = j;
                  D[w] = minimo(D[w],D[v]+(*(MtzPes+w+(v*MaxNodos)))); //M[v][w]
              }
         }
         contador++;
    }
    
    printf("\n\n Vector D -> ");
    for(i = 0; i < MaxNodos; i++)
    {
       if(D[i] != INF)
       printf("  %d  ",D[i]);
       else
       printf("  Inf  ");
    }
    printf("\n\n");
    camino = D[NQ];//NQ es el nodo de destino en numeros, si es A entonces es 0, si es B es 1
    return camino;
}     

//retorna el valor minimo entre 'x' y 'y'
int minimo (int x, int y)
{
    if(x<y)
    return x;
    else
    return y;
}

int algo_warshall (int* MtzAdy, int* MtzAux, int NP, int NQ)
{
    int k,i,j,camino;
    CopiaMatriz(MtzAdy,MtzAux);
    for(k = 1; k < MaxNodos; k++)
    for(i = 0; i < MaxNodos; i++)
    for(j = 0; j < MaxNodos; j++)
    *(MtzAux + j + (i*MaxNodos))  = funcion_warshall(i,j,k,MtzAux);
    printf("\n\n\tMatriz Resultante de Warshall\n\n");
    ImpMatriz(MtzAux);
    return camino = *(MtzAux + NQ + (NP*MaxNodos));
}

int funcion_warshall(int i, int j, int k, int* MtzAux)
{
    if((*(MtzAux + j + (i*MaxNodos)) == 1) || ((*(MtzAux + k + (i*MaxNodos)) == 1)&&(*(MtzAux + j + (k*MaxNodos)) == 1)))
    return 1;
    else
    return 0; 
}

int algo_floyd(int* MtzPes, int* MtzPesAcum, int NP, int NQ)
{
     int k,i,j,camino;
     CopiaMatriz(MtzPes,MtzPesAcum);
     for(k = 1; k < MaxNodos; k++)
     for(i = 0; i < MaxNodos; i++)
     for(j = 0; j < MaxNodos; j++)
     *(MtzPesAcum + j + (i*MaxNodos))  = minimo(*(MtzPesAcum + j + (i*MaxNodos)),*(MtzPesAcum + k + (i*MaxNodos)) + *(MtzPesAcum + j + (k*MaxNodos)));
     printf("\n\n\tMatriz Resultante de Floyd\n\n");
     ImpMatriz(MtzPesAcum);
     return camino = *(MtzPesAcum + NQ + (NP*MaxNodos));
}                                                  
