#include <stdio.h>
#include <conio.h>

main()
{
     char carac='A', *r;
     int a=12,b=45, c;
     int *p, *q;
     printf("Dirección de a=%p\n", &a);
     printf("Dirección de b=%p\n", &b);
     printf("a = %d b = %d\n", a, b);
     printf("Dirección de caract = %p\n", &carac);
     printf("carac = %c\n", carac);
     printf("Valor ASCII de carac = %d\n", carac);
     printf("Dirección de p = %p\n", &p);
     printf("Dirección de q = %p\n", &q);
     printf("Dirección de r = %p\n", &r);
     p = &a;
     q = &b;
     r = &carac;
     printf("El puntero p apunta a la dirección: %p\n", p);
     printf("Y su contenido es: %d\n", *p);
     printf("El puntero q apunta a la dirección: %p\n", q);
     printf("Y su contenido es: %d\n", *q);
     printf("El puntero r apunta a la dirección: %p\n", r);
     printf("Y el contenido de *r es: %d\n", *r);
     printf("Como caracter ASCII *r contiene: %c\n", *r);
     
     getch();
}
