#include "NodoEmpleado.h"

NodoEmpleado::NodoEmpleado(Empleado* dato) {
	this->setDato(dato);  //recibe un empleado y lo almacena utilizando el setter
	this->siguiente = NULL;
}
NodoEmpleado::~NodoEmpleado(){
	delete dato; //el nodo es dueño del empleado: al destruirse lo libera, si no esa memoria se pierde
}
void NodoEmpleado::setDato(Empleado* dato){
	this->dato=dato;
}
void NodoEmpleado::setSiguiente(NodoEmpleado* siguiente){
	this->siguiente=siguiente;
}
Empleado* NodoEmpleado::getDato(){
	return this->dato;
}
NodoEmpleado* NodoEmpleado::getSiguiente(){
	return this->siguiente;
}
