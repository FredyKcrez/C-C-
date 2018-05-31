#ifndef LISTA_H
#define LISTA_H
 
#include <iostream>
#include "time.h"
#include <fstream>
#include <string>
#include "Nodo.h"
#include "Nodo.cpp"
 
using namespace std;
	 
//template <class T>
class Lista{
  private:
    int dim,num_nodos;
    TipoDato line;
    string archivo;
 
  public:
    TipoDato ele;
    //Nodo<T> *head;
    Nodo *head;
    Lista();
    ~Lista();
 
    void llenar_teclado(int);
    void llenar_aleatorio(int);
    void print();
    void add_end(TipoDato);
    void add_head(TipoDato);
    void add_sort(TipoDato);
    void search(TipoDato);
    void del_dato(TipoDato);
    void del_pos(int);
    void del_all();
 
    void invertir();
    void sort();
    void load(string);
    void save(string);
 
    void concat(Lista);
    void interseccion(Lista);
};

//usado por el metodo interseccion
void insert_sort(TipoDato a[],int tam)
{
  TipoDato temp;
  for(int i=0;i<tam;i++){
    for(int j=i-1;j >=0 && a[j+1] < a[j];j--){
      temp = a[j+1];
      a[j+1] = a[j];
      a[j] = temp;
    }
  }
}


#endif // LISTA_H
