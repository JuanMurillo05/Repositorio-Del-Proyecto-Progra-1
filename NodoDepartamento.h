#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H
#include "Departamento.h"

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

