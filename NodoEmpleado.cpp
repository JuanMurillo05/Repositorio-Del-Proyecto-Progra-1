#include "NodoEmpleado.h"

NodoEmpleado::NodoEmpleado(Empleado* dato) {
	this->setDato(dato);
	this-> siguiente = NULL;
}
NodoEmpleado::~NodoEmpleado(){
	
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

