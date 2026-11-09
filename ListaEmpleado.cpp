#include "ListaEmpleado.h"

ListaEmpleado::ListaEmpleado() {
	cabeza = cola = actual = NULL;
}
ListaEmpleado::~ListaEmpleado(){
	while(cabeza != NULL){
		
		actual = cabeza;
		
		cabeza = cabeza->getSiguiente();
		
		delete actual;
	}
}
NodoEmpleado* ListaEmpleado::getCabeza() {
		return cabeza;
	}
bool ListaEmpleado::vacio(){
	return cabeza == NULL;
}
int ListaEmpleado::contar(){
	actual = cabeza;
	int cont = 0;
	
	while(actual != NULL){
		actual = actual->getSiguiente();
		cont++;
	}
	return cont;
}
void ListaEmpleado::agregarEmpleado(Empleado* empleado){
	NodoEmpleado *aux = new NodoEmpleado(empleado); //crea memoria dinamica para crear un nuevo nodo 
	
	if(vacio()){   //comprueba si la lista esta vacia 
		cabeza = aux; //si esta vacia convierte al nuevo nodo en el primero 
	}else{
		actual = cabeza;
		
		while(actual->getSiguiente() != NULL){//recorre la lista hasta encontrar el ultimo para asi agregar el nuevo 
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(aux);//conecta el ultimo nodo con el nuevo 
	}
}
string ListaEmpleado::mostrar(){
	actual = cabeza;
	stringstream x;
	
	if(vacio()){
		x << "No hay empleado registrados" << endl;
	}else{
		while(actual != NULL){
			x << "Nombre : " << actual->getDato()->getNombre() << endl;
			x << "Cedula : " << actual->getDato()->getCedula() << endl;
			x << "Codigo de departamento : " << actual->getDato()->getCodigoDepartamento() << endl;
			x << "-------------------------------------------" << endl;
			
			actual = actual->getSiguiente();
		}
	}
	return x.str();
}

