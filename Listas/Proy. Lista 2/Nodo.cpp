#include "Nodo.h"
 
//constructor por defecto
//template<typename T>
//Nodo<T>::Nodo(){
Nodo::Nodo(){
  dato = -1;
  sgte = NULL;
}
	 
//constructor por parametro
//template<typename T>
//Nodo<T>::Nodo(TipoDato dato_)
Nodo::Nodo(TipoDato dato_)
{
  dato = dato_;
  sgte = NULL;
}
	 
//imprimir un nodo
//template<typename T>
//void Nodo<T>::print()
void Nodo::print()
{
  //cout << "Nodo-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << sgte << endl;
  cout << dato << "-> ";
}
 
//eliminar todos los nodos
//template<typename T>
//void Nodo<T>::eliminar()
void Nodo::eliminar()
{
  if(sgte)
    sgte->eliminar();
  delete this;
}
 
//template<typename T>
//Nodo<T>::~Nodo(){}
Nodo::~Nodo(){}
