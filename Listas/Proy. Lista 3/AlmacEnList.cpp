#include "Nodo.h"
#include "Lista.h"
#include <iostream>
using namespace std;

typedef int Dato;

main()
{
      Dato d=0;
      Dato x;
      Nodo* v;
      Lista lista;
      
      cout << "\nDigite -1 para terminar de ingresar datos a la lista" << endl;
      while(d != -1)
      {
           cin >> d;
           cout << "\nEn que posicion desea insertarlo" << endl;
           cout << "1. Al inicio de la lista." << endl;
           cout << "2. Entre 2 nodos." << endl;
           cout << "3. Al final de la lista." << endl;
           cout << "\nOpcion:\t" << endl;
           cin >> x;
           
           system("cls");
           switch(x)
           {
                    case 1:
                           lista.inserIniLis(d);
                           break;
                    case 2:
                           lista.inserUltLis(d);
                           break;
                    case 3:
                           cout << "\nLa lista contiene los siguientes elementos:" << endl;
                           lista.visualizarList();
                           /*cout << "\nPosicion:\t" << endl;
                           cin >> v;
                           lista.inserDentLis(d, v);*/
                           break;
           }
      }
      system("cls");
      cout << "\nElementos de la lista:" << endl;
      lista.visualizarList();

      return 0;
}
