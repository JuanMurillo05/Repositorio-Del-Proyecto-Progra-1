#include "ListaComprobante.h"

ListaComprobante::ListaComprobante() {
	cabeza = NULL;
	cola = NULL;
}

ListaComprobante::~ListaComprobante() {
	while(cabeza != NULL){
		NodoComprobante *aux = cabeza;
		cabeza = cabeza->getSig();
		delete aux;
	}
	cola = NULL;
}

bool ListaComprobante::vacio(){
	return cabeza == NULL;
}

int ListaComprobante::contar(){
	NodoComprobante *aux = cabeza;
	int cont = 0;
	
	while(aux != NULL){
		cont++;
		aux = aux->getSig();
	}
	return cont;
}

void ListaComprobante::agregarComprobante(ComprobantePago *comprobante){
	if(comprobante == NULL){
		return;
	}
	
	NodoComprobante *nuevo = new NodoComprobante(comprobante);
	
	if(vacio()){
		cabeza = nuevo;
		cola = nuevo;
	}else{
		cola->setSig(nuevo);
		cola = nuevo;
	}
}

bool ListaComprobante::existePeriodo(int mes, int anio){
	NodoComprobante *aux = cabeza;
	
	while(aux != NULL){
		if(aux->getComprobante()->getMes() == mes && aux->getComprobante()->getAnio() == anio){
			return true;
		}
		aux = aux->getSig();
	}
	return false;
}

int ListaComprobante::contarDeEmpleado(Empleado *empleado){
	NodoComprobante *aux = cabeza;
	int cont = 0;
	
	while(aux != NULL){
		if(aux->getComprobante()->getEmpleado() == empleado){
			cont++;
		}
		aux = aux->getSig();
	}
	return cont;
}

int ListaComprobante::contarDeDepartamento(Departamento *departamento){
	NodoComprobante *aux = cabeza;
	int cont = 0;
	
	while(aux != NULL){
		if(aux->getComprobante()->getDepartamento() == departamento){
			cont++;
		}
		aux = aux->getSig();
	}
	return cont;
}

string ListaComprobante::mostrar(){
	NodoComprobante *aux = cabeza;
	stringstream x;
	
	if(vacio()){
		x << "No hay comprobantes registrados" << endl;
	}else{
		while(aux != NULL){
			x << aux->getComprobante()->toString();
			x << "-------------------------------------------" << endl;
			aux = aux->getSig();
		}
	}
	return x.str();
}

void ListaComprobante::autoGuardar(ofstream& salida){
	salida << contar() << endl;//primero la cantidad de comprobantes
	
	NodoComprobante *aux = cabeza;
	while(aux != NULL){
		aux->getComprobante()->autoGuardar(salida);
		aux = aux->getSig();
	}
}

void ListaComprobante::autoLeer(ifstream& entrada, ListaEmpleado& empleados, ListaDepartamento& departamentos){
	int cantidad = 0;
	entrada >> cantidad;
	
	if(!entrada || cantidad < 0){
		return;
	}
	
	for(int i = 0; i < cantidad; i++){
		ComprobantePago *comprobante = new ComprobantePago();
		
		if(comprobante->autoLeer(entrada, empleados, departamentos)){
			agregarComprobante(comprobante);
		}else{
			delete comprobante;//lectura fallida o empleado/departamento que ya no existe
			if(!entrada){
				break;
			}
		}
	}
}
