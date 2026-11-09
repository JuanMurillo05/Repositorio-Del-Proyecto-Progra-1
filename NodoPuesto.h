#ifndef NODOPUESTO_H
#define NODOPUESTO_H
#include "Puesto.h"

//ejemplo de composicion, la podemos ver entre la clase puesto y departamento, ya que un departamento esta conformado de varios puestos, y si se llega a eliminar un departamento pues tambien se eliminarian los puestos 

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


