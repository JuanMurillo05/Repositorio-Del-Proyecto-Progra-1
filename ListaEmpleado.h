#ifndef LISTAEMPLEADO_H
#define LISTAEMPLEADO_H
#include "NodoEmpleado.h"
#include <string>
#include <sstream>

//clase encargada de administrar una lista enlazada de empleados

class ListaEmpleado {
public:
	ListaEmpleado();
	~ListaEmpleado();
	
	bool vacio(); //funcion para comprobar si la lista esta vacia o no 
	int contar();
	void agregarEmpleado(Empleado* empleado);//agrega empleados al final de la lista 
	string mostrar();
	NodoEmpleado* getCabeza();//funcion para obtener el primer nodo de la lista enlazada se utiliza para la clase Planilla ya que esta necesita recorrer todos los empleados para asi hacer el calculo salarial 
	
	
private:
	NodoEmpleado *cabeza;
	NodoEmpleado *actual;
	NodoEmpleado *cola;
};

#endif


