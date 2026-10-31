#include "ListaPuesto.h"

ListaPuesto::ListaPuesto() {
	
	cabeza = NULL;
	cola = NULL;
	actual = NULL;
	
}

ListaPuesto::~ListaPuesto() {
	
	actual = cabeza;
	
	while(actual != NULL){
	NodoPuesto *siguiente = actual->getSig();
	delete actual;
	actual = siguiente;
	}
	
	cabeza = NULL;
	cola = NULL;
	actual = NULL;
}

void ListaPuesto::agregarPuesto(Puesto *puesto){
	
	if(puesto == NULL){
	return;
	}
	
	NodoPuesto *nuevo = new NodoPuesto(puesto);
	
	if(cabeza == NULL){
	
	cabeza = nuevo;
	cola = nuevo;
	
	}
	else{
	cola->setSig(nuevo);
	cola = nuevo;
	}
}

Puesto *ListaPuesto::buscarPuesto(int codigo){
	
	actual = cabeza;
	
	while(actual != NULL){
	if(actual->getPuesto()->getCodigo() == codigo){
	
	return actual->getPuesto();
	}
	actual = actual->getSig();
	}
	return NULL;
}

bool ListaPuesto::eliminarPuesto(int codigo){
	
	actual = cabeza;
	NodoPuesto *anterior = NULL;
	
	while(actual != NULL){
	
	if(actual->getPuesto()->getCodigo() == codigo){
	
	if(actual == cabeza){
	
	cabeza = actual->getSig();
	
	}
	else{
	
	anterior->setSig(actual->getSig());
	
	}
	if(actual == cola){
	
	cola = anterior;
	
	}
	
	delete actual;
	actual = NULL;
	return true;
	
    }
	
	anterior = actual;
	actual = actual->getSig();
	
	}
	
	return false;
	
}

string ListaPuesto::mostrarPuestos(){
	
	stringstream a;
	actual = cabeza;
	
	while(actual != NULL){
	
	a<<actual->getPuesto()->toString()<<endl;
	
	actual = actual->getSig();
	
	}
	
	return a.str();
	
}

void ListaPuesto::autoGuardar(ofstream& salida){
	int cantidad = 0;
	actual = cabeza;
	
	while(actual != NULL){
	cantidad++;
	actual = actual->getSig();
	}
	
	salida<<cantidad<<endl;
	actual = cabeza;
	
	while(actual != NULL){
	actual->getPuesto()->autoGuardar(salida);
	actual = actual->getSig();
	}
}

void ListaPuesto::autoLeer(ifstream& entrada){
	int cantidad;
	entrada>>cantidad;
	
	if(!entrada || cantidad < 0){
	return;
	}
	
	for(int i=0;i<cantidad;i++){
	Puesto *puesto = new Puesto();
	puesto->autoLeer(entrada);
	
	if(entrada){
	agregarPuesto(puesto);
	}else{
	delete puesto;
	break;
	}
	}
}

