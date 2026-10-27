#ifndef LISTAEMPLEADO_H
#define LISTAEMPLEADO_H
#include "NodoEmpleado.h"
#include <string>
#include <sstream>

class ListaEmpleado {
public:
	ListaEmpleado();
	~ListaEmpleado();
	
	bool vacio();
	int contar();
	void agregarEmpleado(Empleado* empleado);
	string mostrar();
	
private:
	NodoEmpleado *cabeza;
	NodoEmpleado *actual;
	NodoEmpleado *cola;
};

#endif


