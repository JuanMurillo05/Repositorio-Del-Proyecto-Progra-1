#include "NodoPuesto.h"

NodoPuesto::NodoPuesto(Puesto *puesto) {
	
	this->puesto = puesto;
	sig = NULL;
	
}

NodoPuesto::~NodoPuesto() {
	
	delete puesto;
	
}

void NodoPuesto::setPuesto(Puesto *puesto){
	
	if(this->puesto != puesto){
	
	delete this->puesto;
	this->puesto = puesto;
	
	}
}

void NodoPuesto::setSig(NodoPuesto *sig){
	this->sig = sig;
}

Puesto *NodoPuesto::getPuesto(){
	return puesto;
}

NodoPuesto *NodoPuesto::getSig(){
	return sig;
}


