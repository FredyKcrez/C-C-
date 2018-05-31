typedef int TipoDato;
#include "colalineal.h"
#include <stdio.h>

void crearCola(Cola* cola){
cola->frente = 0;
cola->final = -1;
}
Cola *crearColaDim(){
Cola *ColaDim;
ColaDim = (Cola*) malloc(sizeof(Cola));
ColaDim->frente=0;
ColaDim->final = -1;
return ColaDim;
}
void insertar(Cola* cola, TipoDato entrada){
if(colaLlena(*cola)){
puts("Cola completa.");
exit(1);
}
cola->final++;
cola->Elemento[cola->final]=entrada;
}
TipoDato quitar(Cola* cola){
TipoDato item;
if(colaVacia(*cola)){
puts("Se intenta sacar un elemento en cola vacia.");
exit(1);
}
item=cola->Elemento[cola->frente];
cola->frente++;
return item;
}
int colaVacia(Cola cola){
return cola.final<cola.frente;
}
int colaLlena(Cola cola){
return cola.final == MAXTAMQ -1;
}
TipoDato frente(Cola cola){
if(colaVacia(cola)){
puts("Error de ejecucion, cola vacia.");
exit(1);
}
return cola.Elemento[cola.frente];
}
