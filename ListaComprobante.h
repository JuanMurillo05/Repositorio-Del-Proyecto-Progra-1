#ifndef LISTACOMPROBANTE_H
#define LISTACOMPROBANTE_H
#include "NodoComprobante.h"

class ListaComprobante {
public:
	ListaComprobante();
	virtual~ListaComprobante();
	
	bool vacio();
	int contar();
	void agregarComprobante(ComprobantePago *comprobante);
	bool existePeriodo(int mes, int anio);//indica si ya se proceso la planilla de ese mes y anio
	int contarDeEmpleado(Empleado *empleado);//cuantos comprobantes tiene un empleado
	int contarDeDepartamento(Departamento *departamento);//cuantos comprobantes tiene un departamento
	string mostrar();
	
	void autoGuardar(ofstream& salida);
	void autoLeer(ifstream& entrada, ListaEmpleado& empleados, ListaDepartamento& departamentos);
	
private:
	
	NodoComprobante *cabeza;
	NodoComprobante *cola;
	
	//evitan que se copien listas lo cual provocaria que se liberen dos veces los mismos comprobantes
	ListaComprobante(const ListaComprobante&) = delete;
	ListaComprobante& operator=(const ListaComprobante&) = delete;
};

#endif
