#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H
#include "Empleado.h"

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


