#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAXCOL 30

main()
{
     int nfila, ncol, f, c,(*a)[MAXCOL];
     puts("Intro n§ de filas:");
     scanf("%d", &f);
     puts("Introducir numero de columnas:");
     scanf("%d", &c);
     puts("Llenamos el array:");
     for(nfila=0; nfila<f; nfila++)
     for(ncol=0; ncol<c; ncol++)
     {
     printf("(*(a+%d)+%d) = ", nfila, ncol);
     scanf("%d", *(a+nfila)+ncol);
     }
     puts("Imprimimos el array:");
     for(nfila=0; nfila<f; nfila++)
     {
     for(ncol=0; ncol<c; ncol++)
     printf(" %d",*(*(a+nfila)+ncol));
     puts("");
     }
     getch();
}
