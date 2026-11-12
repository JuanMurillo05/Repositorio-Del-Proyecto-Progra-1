//Principio SOLID sobre responsabilidad unica, lo podemos ver tanto en NodoEmpleado como en cualquier otro Nodo de nuestro codigo
//ya que los nodos solo se encargan de enlazar guardar un dato y un puntero al siguiente Nodo, no guardan ni buscan ni eliminan ya que esas funciones se encarga las Listas y por eso se cumple el principio
#include "NodoEmpleado.h"

NodoEmpleado::NodoEmpleado(Empleado* dato) {
	this->setDato(dato);  //recibe un empleado y lo almacena utilizando el setter
	this-> siguiente = NULL;
}
NodoEmpleado::~NodoEmpleado(){
	delete dato; //el nodo es dueño del empleado: al destruirse lo libera, si no esa memoria se pierde
}
void NodoEmpleado::setDato(Empleado* dato){
	this-> dato = dato;
}
void NodoEmpleado::setSiguiente(NodoEmpleado* siguiente){
	this->siguiente = siguiente;
}
Empleado* NodoEmpleado::getDato(){
	return this->dato;
}
NodoEmpleado* NodoEmpleado::getSiguiente(){
	return this->siguiente;
}
