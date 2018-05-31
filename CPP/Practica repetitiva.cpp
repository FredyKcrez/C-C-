#include<stdio.h>
#include<conio.h>

main()
{
      int i = 1, cf = 0,cm = 0;
      float af = 0.0, am = 0.0, pf, pm;
      float est;
      char gen;
      
      while(i<=3)
      {
       printf("\nDigite estatura (mts): ");
       scanf("%f", &est);
            while(!(est>0))
            {
                printf("\n-----ERROR-----");
                printf("\n\nDigite nuevamente estatura (mts): ");
                scanf("%f", &est);
            }
       printf("\nDigite el genero de la persona:\n  f - femenino\n  m - masculino\nRespuesta: ");
       fflush(stdin);
       scanf("%c", &gen);
       fflush(stdin);
       while((gen!='f') && (gen!='m'))                       
       {
            printf("\nDigite nuevamente el genero: ");
            fflush(stdin);
            scanf("%c",&gen);
            fflush(stdin);
       }
       if(gen=='f')
       {
    		af += est;
    		cf++;
       }
       else
       {
            cm++;
            am += est;
       }
       i++;
      }
	  pf = af/cf;
	  pm = am/cm;

	printf("\n LA CANTIDAD FEMENINO ES: %i",cf);
	printf("\n LA CANTIDAD MASCULINA ES: %i",cm);
	printf("\n PROMEDIO FEMENINO =%.2f",pf);
	printf("\n PROMEDIO MASCULINO =%.2f",pm);

	getch();
	return 0;
}

