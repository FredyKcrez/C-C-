//2° Evaluado de Lab. Intro...lectura de 2 valores enteros y la respetiva operacion sobre ellos
#include<stdio.h>
#include<conio.h>
#include<windows.h>

main()
{	
	  int m, n, ok;
	  char OP;
	  float x, y, z;
	
	  printf("\n\n\t*** Digite dos enteros y la operacion (PRESIONE LETRA INDICADA) ***\n");
	  printf("\n\n\tS --> Suma\n\tR --> Resta\n\n\tOperacion:\t");
	  scanf("%c",&OP);
	  while((OP!='R')&&(OP!='S')&&(OP!='r')&&(OP!='s'))
      {
            fflush(stdin);
			printf("\n\t*** Por Favor Digite Solo Operaciones Indicadas !! ***\n\n\tOperacion:\t");
	  		scanf("%c",&OP);
            fflush(stdin);
      }
	  printf("\n\n\tValor 1:\t");
	  ok = scanf("%i",&m);
	  while(ok!=1)
      {
            fflush(stdin);
			printf("\n\t*** Por Favor Digite Solo Numeros !! ***");
            printf("\n\n\tValor 1:\t");
	  		ok = scanf("%i",&m);
            fflush(stdin);
      }
	  printf("\n\n\tValor 2:\t");
	  ok = scanf("%i",&n);
	  while(ok!=1)
      {
            fflush(stdin);
			printf("\n\t*** Por Favor Digite Solo Numeros !! ***");
            printf("\n\n\tValor 2:\t");
	  		ok = scanf("%i",&n);
            fflush(stdin);
      }
	  x = (m-n);
	  y = (m+n);
	  if(x!=y)
	  {
	      if(OP=='r')
	      {
	         z=x-y;
	      }
	      else
	        z=x+y;
	  }
	  else
	  {
	       switch(OP)
	       {
	          case 's':
		             z=x+y;
		             break;
		      case 'r':
		             z=x-y;
		             break;
		    }
	  }
	  printf("\n\n\tEl valor total de la operacion es:\t%.2f",z);
	  getch();
	  return 0;
}
