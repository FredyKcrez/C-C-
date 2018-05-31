/* Nombre:PALINDRO
Objetivo: Determinar todas las frases palindromo de un archivo de texto*/
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Colas.h"
#include "Pilas.h"

main() {
   /* Variable */
  QUEUE PalindromeCola;
  STACK PalindromePila;
  QUEUELEMENT DatoCola;
  STACKELEMENT DatoPila;
  char Frase[100];
  int p;
  int Valido;

  FILE * archivo;
  /* Inicializaciones */
  //clrscr();
  Make(&PalindromeCola);
  Clear(&PalindromePila);
   archivo=fopen("frases.txt","r");
  /*Encabezado de la salida*/
   printf("\n%s\n\n","EVALUACION DE FRASES") ;

   while (!feof(archivo)) {
              Valido = TRUE;
                Make(&PalindromeCola);           /* limpiar cola */
                Clear(&PalindromePila);            /* limpiar pila */
               fscanf(archivo, "%s \n", Frase);
	 /*Colocar la frase en la cola y en la pila*/
	 for( p=0;p<=strlen(Frase) - 1; p++) {
	     DatoCola=Frase[p];
	      DatoPila=Frase[p];
	     Insert(&PalindromeCola,DatoCola);
	     Push(&PalindromePila,DatoPila);
	      } // For
	  /*Comparacion para verificar si la frase es un palindrome*/
	  while (! Empty(&PalindromePila) && ! IsEmpty(&PalindromeCola) && Valido)   {
	     DatoCola= Remove(&PalindromeCola);
	     DatoPila= Pop(&PalindromePila);
	     if (DatoCola != DatoPila)      {
                           Valido=FALSE ;
                       }
	  } // While
	/*Resultados*/
	 printf("%s", Frase);
	if (Valido)
	    printf("%s\n\n"," ==> Es Palindrome");
	else
	    printf("%s\n\n"," ==> No Es Palindrome");
   }/* fin While (!feof(archivo)) */
  getch();
  fclose(archivo);
} /* main */
