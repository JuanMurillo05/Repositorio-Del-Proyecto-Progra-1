#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H
#include "ComprobantePago.h"

//clase que representa un nodo de la lista enlazada de comprobantes, cada nodo almacena un comprobante y un enlace hacia el siguiente

class NodoComprobante {
public:
	NodoComprobante(ComprobantePago *comprobante);
	virtual~NodoComprobante();
	
	void setSig(NodoComprobante *sig);
	
	ComprobantePago *getComprobante();
	NodoComprobante *getSig();
	
private:
	
	ComprobantePago *comprobante;
	NodoComprobante *sig;
};

#endif
