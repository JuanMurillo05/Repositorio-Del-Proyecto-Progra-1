#include "NodoComprobante.h"

NodoComprobante::NodoComprobante(ComprobantePago *comprobante){
	this->comprobante = comprobante;
	sig = NULL;
}

NodoComprobante::~NodoComprobante(){
	delete comprobante; //el nodo es dueño del comprobante, pero el comprobante no elimina al empleado ni al departamento
}
	
	void NodoComprobante::setSig(NodoComprobante *sig){
		this->sig = sig;
	}
	
	ComprobantePago *NodoComprobante::getComprobante(){
		return comprobante;
	}
	
	NodoComprobante *NodoComprobante::getSig(){
		return sig;
	}
