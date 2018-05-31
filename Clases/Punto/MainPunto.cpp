#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Punto.h"

using namespace std;

main()
{
      int y = 15000;
      Punto p1(1, 2);
      Punto* p2 = new Punto(2, 1);
      Punto p3;
      Punto p4;
      
      p3.fijarX(10);  //accede a la insercion por medio del .
      p3.fijarY(3);
      
      p4.fijarX(3);  //accede a la insercion por medio de ->
      p4.fijarY(10);
      
      cout << "\n\tEl punto 1 contiene las siguientes coordenadas:\n" ;
      cout << "\t\ten X = " << p1.leerX() << "\ten Y = " << p1.leerY() ;
      
      cout << "\n\n\tEl punto 2 contiene las siguientes coordenadas:\n" ;
      cout << "\t\ten X = " << p2 -> leerX() << "\ten Y = " << p2 -> leerY() ;
      
      cout << "\n\n\tLa coordenada X del punto 3 es: " << p3.leerX() ;
      cout << "\n\tLa coordenada Y del punto 4 es: " << p4.leerY() ;
      
      Sleep(y);
      return 0;
}
