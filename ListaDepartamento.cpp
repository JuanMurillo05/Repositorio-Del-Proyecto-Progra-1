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
	salida<<contar()<<endl;//guarda primero la cantidad de departamentos gracias a la funcion que ya habiamos hecho de contar
	actual = cabeza;
	
	while(actual != NULL){//recorremos la lista para que cada departamento guarde sus propios datos y tambien los puestos que tienen
	actual->getDepartamento()->autoGuardar(salida);
	actual = actual->getSig();
	}
}

void ListaDepartamento::autoLeer(ifstream& entrada){
	int cantidad;
	entrada>>cantidad;//lee la cantidad de departamentos que hay 
	
	for(int i=0;i<cantidad;i++){//recorre la canridad que hay, luego crea la memoria dinamica, recupera los datos y finalmente agrega el departamento
	Departamento *departamento = new Departamento();
	departamento->autoLeer(entrada);
	agregarDepartamento(departamento);
	}
}

