#ifndef LISTADEPARTAMENTO_H
#define LISTADEPARTAMENTO_H
#include "NodoDepartamento.h"

class ListaDepartamento {
public:
	ListaDepartamento();
	virtual~ListaDepartamento();
	
	bool vacio();
	int contar();
	void agregarDepartamento(Departamento *departamento);
	Departamento *buscarDepartamento(int codigoDepartamento);
	bool eliminarDepartamento(int codigoDepartamento);
	string mostrarDepartamentos();
	
	void autoGuardar(ofstream& salida);
	void autoLeer(ifstream& entrada);
	
private:
	
	NodoDepartamento *cabeza;
	NodoDepartamento *actual;
	NodoDepartamento *cola;
	
};

#endif


