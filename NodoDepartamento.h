#ifndef LISTAEMPLEADO_H
#define LISTAEMPLEADO_H
#include "NodoEmpleado.h"
#include <string>
#include <sstream>

//clase encargada de administrar una lista enlazada de empleados
//la lista es dueña de los empleados que contiene: al destruirse los libera

class ListaEmpleado {
public:
	ListaEmpleado();
	~ListaEmpleado();

	bool vacio(); //funcion para comprobar si la lista esta vacia o no
	int contar();
	void agregarEmpleado(Empleado* empleado);//agrega empleados al final de la lista
	Empleado* buscarPorCedula(string cedula);//devuelve el empleado o NULL si no existe
	bool eliminarPorCedula(string cedula);//elimina el nodo y el empleado, devuelve false si no existe
	string mostrar();
	NodoEmpleado* getCabeza();//funcion para obtener el primer nodo de la lista enlazada se utiliza para la clase Planilla ya que esta necesita recorrer todos los empleados para asi hacer el calculo salarial

	void autoGuardar(ofstream& salida);//guarda primero la cantidad y luego cada empleado
	void autoLeer(ifstream& entrada);//lee la cantidad y crea cada empleado segun su tipo

private:
	NodoEmpleado *cabeza;
	NodoEmpleado *actual;
	NodoEmpleado *cola;

	//evitan que se copien listas lo cual provocaria que dos listas liberen los mismos empleados
	ListaEmpleado(const ListaEmpleado&) = delete;
	ListaEmpleado& operator=(const ListaEmpleado&) = delete;
};

#endif
