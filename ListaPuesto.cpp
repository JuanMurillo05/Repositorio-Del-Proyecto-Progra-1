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
	
	while(actual != NULL){//recorre la lista para contar los puestos 
	cantidad++;
	actual = actual->getSig();
	}
	
	salida<<cantidad<<endl;
	actual = cabeza;
	
	while(actual != NULL){//guardar la informacion de cada puesto 
	actual->getPuesto()->autoGuardar(salida);
	actual = actual->getSig();
	}
}

void ListaPuesto::autoLeer(ifstream& entrada){
	int cantidad;
	entrada>>cantidad; //lee la cantidad de puestos que deben recuperarse 
	
	if(!entrada || cantidad < 0){//comprueba que la lectura fuera correcta y que la cantidad no sea negativa 
	return;
	}
	
	for(int i=0;i<cantidad;i++){//recorre el proceso segun la cantidad de puestos registrados 
	Puesto *puesto = new Puesto();
	puesto->autoLeer(entrada);
	
	if(entrada){//comprueba de que la lectura haya sido correcta 
	agregarPuesto(puesto);//si lo es agrega el puesto a la lista 
	}else{//y sino libera la memoria del puesto 
	delete puesto;
	break;
	}
	}
}

