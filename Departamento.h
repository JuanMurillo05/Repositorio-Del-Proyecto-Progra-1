#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include "ListaPuesto.h"

class Departamento {
public:
	Departamento();
	Departamento(int codigoDepartamento, string nombreDepartamento);
	virtual~Departamento();
	
	void setCodigoDepartamento(int codigoDepartamento);
	void setNombre(string nombreDepartamento);
	
	int getCodigoDepartamento();
	string getNombre();
	
	void agregarPuesto(Puesto *puesto);
	Puesto *buscarPuesto(int codigo);
	bool eliminarPuesto(int codigo);
	string mostrarPuesto();
	
	void autoGuardar(ofstream& salida);
	void autoLeer(ifstream& entrada);
	string toString();
private:
	
	int *codigoDepartamento;
	string *nombreDepartamento;
	ListaPuesto *listaPuesto;
};

#endif
