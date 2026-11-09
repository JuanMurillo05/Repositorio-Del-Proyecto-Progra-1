#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H
#include "Empleado.h"

//clase que representa un nodo de la lista enlazada de empleados
//cada nodo almacena un puntero a un objeto Empleado y un puntero al siguiente nodo de la lista 

class NodoEmpleado {
public:
	NodoEmpleado(Empleado* dato);
	virtual ~NodoEmpleado();
	
	void setDato(Empleado* dato);
	void setSiguiente(NodoEmpleado* siguiente);
	
	Empleado* getDato();
	NodoEmpleado* getSiguiente();
	
private:
	
	Empleado* dato;
	NodoEmpleado* siguiente;
};

#endif


