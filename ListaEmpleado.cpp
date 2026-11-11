#include "ListaEmpleado.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"

ListaEmpleado::ListaEmpleado() {
	cabeza = cola = actual = NULL;
}
ListaEmpleado::~ListaEmpleado(){
	while(cabeza != NULL){

		actual = cabeza;

		cabeza = cabeza->getSiguiente();

		delete actual; //el nodo tambien elimina su empleado
	}
	cola = actual = NULL;
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
	if(empleado == NULL){
		return;
	}

	NodoEmpleado *aux = new NodoEmpleado(empleado);

	if(vacio()){
		cabeza = cola = aux;
	}else{
		cola->setSiguiente(aux); //se agrega directo al final sin recorrer toda la lista
		cola = aux;
	}
}
Empleado* ListaEmpleado::buscarPorCedula(string cedula){
	NodoEmpleado* aux = cabeza;

	while(aux != NULL){
		if(aux->getDato()->getCedula() == cedula){
			return aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return NULL;
}
bool ListaEmpleado::eliminarPorCedula(string cedula){
	NodoEmpleado* anterior = NULL;
	NodoEmpleado* aux = cabeza;

	while(aux != NULL && aux->getDato()->getCedula() != cedula){
		anterior = aux;
		aux = aux->getSiguiente();
	}

	if(aux == NULL){
		return false; //no existe esa cedula
	}

	if(anterior == NULL){
		cabeza = aux->getSiguiente(); //era el primero
	}else{
		anterior->setSiguiente(aux->getSiguiente());
	}

	if(aux == cola){
		cola = anterior; //era el ultimo
	}

	delete aux; //elimina el nodo y tambien su empleado
	return true;
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
NodoEmpleado* ListaEmpleado::getCabeza(){
	return cabeza;
}
void ListaEmpleado::autoGuardar(ofstream& salida){
	salida << contar() << endl; //primero la cantidad de empleados

	NodoEmpleado* aux = cabeza;
	while(aux != NULL){
		aux->getDato()->autoGuardar(salida); //cada empleado guarda su tipo y sus datos
		aux = aux->getSiguiente();
	}
}
void ListaEmpleado::autoLeer(ifstream& entrada){
	int cantidad = 0;
	entrada >> cantidad;

	if(!entrada || cantidad < 0){
		return;
	}

	for(int i = 0; i < cantidad; i++){
		string tipo;
		entrada >> tipo; //la primera palabra de cada registro indica que clase crear
		if(!entrada){
			break;
		}

		Empleado* empleado = NULL;

		if(tipo == "Medico"){
			Medico modelo;
			empleado = modelo.autoLeer(entrada);
		}else if(tipo == "Enfermero"){
			Enfermero modelo;
			empleado = modelo.autoLeer(entrada);
		}else if(tipo == "Administrativo"){
			Administrativo modelo;
			empleado = modelo.autoLeer(entrada);
		}else{
			break; //tipo desconocido: el archivo esta danado
		}

		if(entrada){
			agregarEmpleado(empleado);
		}else{
			delete empleado; //la lectura fallo a medias: se libera lo que se creo
			break;
		}
	}
}
