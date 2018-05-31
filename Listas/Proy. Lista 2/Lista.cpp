#include "Lista.h"
	 
using namespace std;
 
//constructor por defecto
//template<typename T>
//Lista<T>::Lista()
Lista::Lista()
{
  num_nodos = 0;
  head = NULL;
}
 
//llenar la lista por teclado
//template<typename T>
//void Lista<T>::llenar_teclado(int dim)
void Lista::llenar_teclado(int dim)
{
  for(int i=0;i<dim;i++){
    cout << "Ingresa el elemento " << i + 1 << endl;
    cin >> ele;
    add_end(ele);
  }
}
 
//llenar la lista aleatoriamente para enteros
//template<typename T>
//void Lista<T>::llenar_aleatorio(int dim)
void Lista::llenar_aleatorio(int dim)
{
  srand(time(NULL));
  for(int i=0;i<dim;i++){
    add_end(rand() % 100);
  }
}
 
//imprimir la lista
//template<typename T>
//void Lista<T>::print()
void Lista::print()
{
  Nodo *temp = head;
  if(!head){
    cout << "La lista esta vacia " << endl;
  } else{
    while(temp){
      temp->print();
      if(!temp->sgte) cout << "NULL";
      temp = temp->sgte;
    }
  }
  cout << endl << endl;
}
 
//insertar al final
//template<typename T>
//void Lista<T>::add_end(T dato_)
void Lista::add_end(TipoDato dato_)
{
  Nodo *temp = head;
  Nodo *nuevo = new Nodo (dato_);

  if(!head){
      head = nuevo;
  } else{
    while(temp->sgte !=NULL){
      temp = temp->sgte;
    }
    temp->sgte = nuevo;
  }
  num_nodos++;
}
 
//insertar al inicio
//template<typename T>
//void Lista<T>::add_head(T dato_)
void Lista::add_head(TipoDato dato_)
{
  Nodo *temp = head;
  Nodo *nuevo = new Nodo(dato_);
 
  if(!head){
    head = nuevo;
  } else{
    nuevo->sgte = head;
    head = nuevo;
    while(temp){
      temp = temp->sgte;
    }
  }
  num_nodos++;
}
 
//insertar de manera ordenada
void Lista::add_sort(TipoDato dato_)
{
  Nodo *nuevo = new Nodo (dato_);
  Nodo *temp = head;
 
  if(!head){
    head = nuevo;
  } else{
    if(head->dato > dato_){
      nuevo->sgte = head;
      head = nuevo;
    } else{
      while((temp->sgte != NULL) && (temp->sgte->dato < dato_)){
        temp = temp->sgte;
      }
      nuevo->sgte = temp->sgte;
      temp->sgte = nuevo;
    }
  }
  num_nodos++;
}
 
//buscar el dato de un nodo
void Lista::search(TipoDato dato_)
{
  Nodo *temp = head;
  int cont = 1;
	  int cont2=0;
	  while(temp){
    if(temp->dato == dato_){
      cout << "El dato se encuentra en la posicion: " << cont << " (Para seres humanos)" << endl;
      cont2++;
    }
    temp = temp->sgte;
    cont++;
  }
  if(cont2 == 0){
    cout << "No existe el dato " << endl;
  }
  cout << endl << endl;
}
 
//eliminar por dato del nodo
void Lista::del_dato(TipoDato dato_)
{
  Nodo *temp = head;
  Nodo *temp1 = head->sgte;
 
  int cont=0;
 
  if(head->dato == dato_){
    head = temp->sgte;
  } else {
    while(temp1){
      if(temp1->dato == dato_){
        Nodo *aux = temp1;
        temp->sgte = temp1->sgte;
        delete aux;
        cont++;
        num_nodos--;
      }
      temp = temp->sgte;
      temp1 = temp1->sgte;
    }
  }
  if(cont == 0){
    cout << "No existe el dato " << endl;
  }
}
 
//eliminar por posicion del nodo
void Lista::del_pos(int pos)
{
  Nodo *temp = head;
  Nodo *temp1 = temp->sgte;
 
  if(pos < 1 || pos > num_nodos){
    cout << "Fuera de rango " << endl;
  } else if(pos==1){
    head = temp->sgte;
  } else{
    for(int i=2;i<=pos;i++){
      if(i==pos){
        Nodo *aux = temp1;
        temp->sgte = temp1->sgte;
        delete aux;
        num_nodos--;
      }
      temp = temp->sgte;
      temp1 = temp1->sgte;
    }
  }
}
 
//eliminar todos los nodos
void Lista::del_all()
{
  head->eliminar();
  head = 0;
}
 
//invertir la lista
void Lista::invertir()
{
  Nodo *temp = head;
  Nodo *prev = NULL;
  Nodo *next = NULL;
 
  while(temp){
    next = temp->sgte;
    temp->sgte = prev;
    prev = temp;
    temp = next;
  }
  head = prev;
}
 
//ordenar de manera ascendente
void Lista::sort()
{
  TipoDato aux2;
  Nodo *aux = head;
  Nodo *temp = aux;
 
  while(aux){
    temp=aux;
    while(temp->sgte){
      temp=temp->sgte;
 
      if(aux->dato>temp->dato){
        aux2=aux->dato;
        aux->dato=temp->dato;
        temp->dato=aux2;
      }
    }
    aux=aux->sgte;
  }
}
 
//cargar una lista de un archivo
void Lista::load(string archivo)
{
  ifstream in;
  in.open(archivo.c_str());
 
  if(!in.is_open()){
    cout << "No se puede abrir el archivo: " << archivo << endl << endl;
  } else{
    while(in >> line){
      add_end(line);
    }
  }
  in.close();
}
 
//guardar una lista en un archivo
void Lista::save(string archivo)
{
  Nodo *temp = head;
  ofstream out;
  out.open(archivo.c_str());
 
  if(!out.is_open()){
    cout << "No se puede guardar el archivo " << endl;
  } else{
    while(temp){
      out << temp->dato;
      out << " ";
      temp = temp->sgte;
    }
  }
  out.close();
}
 
//concatenar a otra lista
void Lista::concat(Lista Lista2)
{
  Nodo *temp2 = Lista2.head;
 
  while(temp2){
    add_end(temp2->dato);
    temp2 = temp2->sgte;
  }
}
 
//numeros que coinciden en 2 listas
void Lista::interseccion(Lista Lista2)
{
  Nodo *temp = head;
  Nodo *temp2 = Lista2.head;//cabeza de la segunda lista
  Lista lista_interseccion;//creo otra lista
 
  int num_nodos2 = Lista2.num_nodos;//nodos de la segunda lista
  int num_inter=0;//numero de coincidencias
 
  //creo 2 vectores dinamicos
  TipoDato *v1 = new TipoDato[num_nodos];
  TipoDato *v2 = new TipoDato[num_nodos2];
 
  //lleno los vectores v1 y v2 con los datos de la lista original y segunda lista respectivamente
  int i=0;
  while(temp){
    v1[i] = temp->dato;
    temp = temp->sgte;
    i++;
  }
 
  int j=0;
  while(temp2){
    v2[j] = temp2->dato;
    temp2 = temp2->sgte;
    j++;
  }
 
  //ordeno los vectores
  insert_sort(v1,num_nodos);
  insert_sort(v2,num_nodos2);
 
  int v1_i= 0;//indice del 1er vector (v1)
  int v2_i= 0;//indice del 2do vector (v2)
 
  //mientras no haya terminado de recorrer ambas listas
  while (v1_i < num_nodos && v2_i < num_nodos2) {
    if(v1[v1_i] == v2[v2_i]){//cuando los datos de ambas sean iguales
      lista_interseccion.add_end(v1[v1_i]);//utilizo mi metodo add_end para llenar la lista de intersecciones
      v1_i++;
      v2_i++;
      num_inter++;
    } else if(v1[v1_i] < v2[v2_i]){
      v1_i++;
	    } else{
      v2_i++;
    }
  }
 
  //Solo si hay alguna interseccion imprimo la nueva lista creada
  if(num_inter > 0) {
    cout << "Existen " << num_inter << " intersecciones " << endl;
    lista_interseccion.print();
  } else {
    cout << "No hay interseccion en ambas listas" << endl;
  }
}
  
Lista::~Lista(){}
