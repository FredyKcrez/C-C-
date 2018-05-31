#include"String.h"
#include<stdlib.h>
#include<conio.h>

STRING S_crear(char X)
{
       STRING S;
       if((S=(STRING)malloc(sizeof(STRUCTSTR))) != NULL)
       {
           S->cad = X;
       }
       return(S);
}
STRING S_buscar(STRING S, char Elemento)
{
       int z, i, Resultado = 0;
       z = S_calong(S);
       i = 0;
       while(i<z)
         if(S[i]==Elemento)
         {
             Resultado = 1;
             i = z+1;
         }
         else
             i++;
         
         return(Resultado);
}
STRING S_copiar(STRING cad1, STRING cad2)
{
       S -> cad2;
       S -> cad1;
       z = S_calong(STRING cad1);
       
       while(i<=z)
       {
                  cad2[j] = cad1[i];
                  j++;
                  i++;
       }
       return(cad2);
}
int S_calong(STRING S)
{
    int i;
    while(S[i]!=null)
         i++;
    return(i);
}
void S_impr(STRING S)
{
     printf("\n\nCadena: %c", cad);
}
STRING S_invcad(STRING cad1, STRING cad2)
{
       S -> cad2;
       S -> cad1;
       i = calong(cad1);
       while(i>0)
       {
                 cad2[j] = cad1[i];
                 j++;
                 i--;
       }
       return (cad2);
}
