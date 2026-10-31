#include "ListaDepartamento.h"

ListaDepartamento::ListaDepartamento() {
	
	cabeza = NULL;
	actual = NULL;
	cola = NULL;
}

ListaDepartamento::~ListaDepartamento() {
	
	while(cabeza != NULL){
	actual = cabeza;
	cabeza = cabeza->getSig();
	delete actual;
	}
	cola = NULL;
	actual = NULL;
}

bool ListaDepartamento::vacio(){
	return cabeza == NULL;
	
}

int ListaDepartamento::contar(){
	
	actual = cabeza;
	int cont = 0;
	
	while(actual != NULL){
	
	cont++;
	actual = actual->getSig();
	
	}
	
	return cont;
	
}

void ListaDepartamento::agregarDepartamento(Departamento *departamento){
	
	if(departamento == NULL){
	return;
	}
	
	NodoDepartamento *nuevo = new NodoDepartamento(departamento);
	
	if(vacio()){
	
	cabeza = nuevo;
	cola = nuevo;
	
	}else{
	
	cola->setSig(nuevo);
	cola = nuevo;
	
	}
}

Departamento *ListaDepartamento::buscarDepartamento(int codigoDepartamento){
	
	actual = cabeza;
	
	while(actual != NULL){
	
	if(actual->getDepartamento()->getCodigoDepartamento() == codigoDepartamento){
	
	return actual->getDepartamento();
	
	}
	actual = actual->getSig();
	}
	return NULL;
}

bool ListaDepartamento::eliminarDepartamento(int codigoDepartamento){
	actual = cabeza;
	NodoDepartamento *anterior = NULL;
	
	while(actual != NULL){
	if(actual->getDepartamento()->getCodigoDepartamento() == codigoDepartamento){
	if(anterior == NULL) cabeza = actual->getSig();
	else anterior->setSig(actual->getSig());
	
	if(actual == cola) cola = anterior;
	delete actual;
	return true;
	}
	anterior = actual;
	actual = actual->getSig();
	}
	return false;
}

string ListaDepartamento::mostrarDepartamentos(){
	actual = cabeza;
	stringstream a;
	
	if(vacio()){
	a<<"no hay departamentos registrados"<<endl;
	}else{
	while(actual != NULL){
	a<<"codigo del departamento: "<<actual->getDepartamento()->getCodigoDepartamento()<<endl;
	a<<"nombre del departamento: "<<actual->getDepartamento()->getNombre()<<endl;
	
	actual = actual->getSig();
	}
	}
	return a.str();
}

void ListaDepartamento::autoGuardar(ofstream& salida){
	salida<<contar()<<endl;
	actual = cabeza;
	
	while(actual != NULL){
	actual->getDepartamento()->autoGuardar(salida);
	actual = actual->getSig();
	}
}

void ListaDepartamento::autoLeer(ifstream& entrada){
	int cantidad;
	entrada>>cantidad;
	
	for(int i=0;i<cantidad;i++){
	Departamento *departamento = new Departamento();
	departamento->autoLeer(entrada);
	agregarDepartamento(departamento);
	}
}

