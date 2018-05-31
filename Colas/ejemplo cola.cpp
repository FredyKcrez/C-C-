#include <stdio.h>
#include <stdlib.h>

#define MAXTAMQ 100

typedef int tipo_elem;
typedef enum {FALSE = 0, TRUE = 1} boolean;
class Cola{
   private:
       int frente, final;
       tipo_elem listaCola[MAXTAMQ];     
   public:
       void insertar(tipo_elem elem);
       tipo_elem quitar();
       boolean colaLlena();
       boolean colaVacia();  
       int siguiente(int n);
       Cola(){
          frente=0;
          final=MAXTAMQ-1;
       };
};
int Cola::siguiente(int n){
   return (n+1)%MAXTAMQ;    
}

void Cola::insertar(tipo_elem elem){
   final=siguiente(final);
   listaCola[final]=elem;
}

tipo_elem Cola::quitar(){
   tipo_elem item;
   item = listaCola[frente];
   frente=siguiente(frente);
   return item;   
}
boolean Cola::colaLlena(){
   return boolean (frente==siguiente(siguiente(final)));
}

boolean Cola::colaVacia(){
   return boolean (frente==siguiente(final));
}
int main(){
   int x=0;
   Cola cola;
   puts("Insercion de los elementos: \n");
   for(x=0;x<10;x++){
      if (!cola.colaLlena()){
         cola.insertar(x*2);
         printf("\nse inserto %i",x*2);
      }else{
         printf("\nNo se pueden ingresar mas datos.\n");
         x=11;
         }
   }
puts("\n\nLista de elementos: \n");
   for(x=0;x<10;x++){
      if (!cola.colaVacia()){
         printf("Elemento es: %i\n",cola.quitar());
      }else
         x=11;
   }
   system("pause");
   return 0;
}
