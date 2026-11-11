#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H
#include "Departamento.h"

//clase que representa un nodo de la lista enlazada de departamentos, cada nodo almacena un departamento y un enlace hacia el siguiente 

class NodoDepartamento {
public:
	NodoDepartamento(Departamento *departamento);
	virtual~NodoDepartamento();
	
	void setDepartamento(Departamento *departamento);
	void setSig(NodoDepartamento *sig);
	
	Departamento *getDepartamento();
	NodoDepartamento *getSig();
	
private:
	Departamento *departamento;
	NodoDepartamento *sig;
};

#endif
