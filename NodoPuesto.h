#ifndef NODOPUESTO_H
#define NODOPUESTO_H
#include "Puesto.h"

class NodoPuesto {
public:
	NodoPuesto(Puesto *puesto);
	virtual~NodoPuesto();
	
	void setPuesto(Puesto *puesto);
	void setSig(NodoPuesto *sig);
	
	Puesto *getPuesto();
	NodoPuesto *getSig();
	
private:
	
	Puesto *puesto;
	NodoPuesto *sig;
};

#endif


