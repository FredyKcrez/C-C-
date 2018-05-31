#include <iostream>
#include "Lista.h"
#include "Lista.cpp" //por errores de linking de tipo "undefined reference to" (estudiando)
 
using namespace std;
int main()
{
  Lista l1;
  Lista l2;
 
  int dim,pos;
  string archivo;
 
  cout << "Ingresa la dimension de la lista " << endl;
  cin >>dim;
 
  l1.llenar_aleatorio(dim);//llenar_teclado para otros tipos
 
  cout << "Lista A al inicio " << endl;
  l1.print();
 
  cout << "Agrega un elemento por la cabeza" << endl;
  cin >>l1.ele;
  l1.add_head(l1.ele);
  l1.print();
	 
  cout << "Lista invertida " << endl;
  l1.invertir();
  l1.print();
 
  cout << "Lista ordenada " << endl;
  l1.sort();
  l1.print();
 
  cout << "Agrega un elemento (Sera ordenado)" << endl;
  cin >>l1.ele;
  l1.add_sort(l1.ele);
  l1.print();
 
  cout << "Busca un elemento" << endl;
  cin >>l1.ele;
  l1.search(l1.ele);
 
  cout << "Elimina un elemento por dato" << endl;
  cin >>l1.ele;
  l1.del_dato(l1.ele);
  l1.print();
 
  cout << "Elimina un elemento por posicion" << endl;
  cin >>pos;
  l1.del_pos(pos);
  l1.print();
	 
  cout << "Cargar una lista desde archivo - Ingresa el nombre" << endl;
  cin >> archivo;//debe estar en el mismo directorio que este programa
  l2.load(archivo);
  cout << "Lista B" << endl;
  l2.print();
	 
  cout << "Guardar la lista en un archivo - Ingresa el nombre" << endl;
  cin >> archivo;//ingresa un nombre cualquiera *.*
  l2.save(archivo);
	 
  cout << "Interseccion entre las listas A y B " << endl;
  l1.interseccion(l2);
 
  cout << "Listas A y B concatenadas " << endl;
  l1.concat(l2);
  l1.print();
 
  l1.del_all();
  l1.print();
 
  return 0;
}
