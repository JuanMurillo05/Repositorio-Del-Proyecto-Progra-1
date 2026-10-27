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
	NodoEmpleado *aux = new NodoEmpleado(empleado);
	
	if(vacio()){
		cabeza = aux;
	}else{
		actual = cabeza;
		
		while(actual->getSiguiente() != NULL){
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(aux);
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

