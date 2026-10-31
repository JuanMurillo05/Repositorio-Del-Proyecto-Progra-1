#include "NodoDepartamento.h"

NodoDepartamento::NodoDepartamento(Departamento *departamento){
	this->departamento = departamento;
	sig = NULL;
}

NodoDepartamento::~NodoDepartamento(){
	delete departamento;
}
	
	void NodoDepartamento::setDepartamento(Departamento *departamento){
	if(this->departamento != departamento){
	delete this->departamento;
	this->departamento = departamento;
	}
	}
	
	void NodoDepartamento::setSig(NodoDepartamento *sig){
	this->sig = sig;
	}
	
	Departamento *NodoDepartamento::getDepartamento(){
	return departamento;
	}
	
	NodoDepartamento *NodoDepartamento::getSig(){
	return sig;
	}


