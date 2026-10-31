#ifndef LISTAPUESTO_H
#define LISTAPUESTO_H
#include "NodoPuesto.h"

class ListaPuesto {
public:
	ListaPuesto();
	virtual~ListaPuesto();
	
	void agregarPuesto(Puesto *puesto);
	Puesto *buscarPuesto(int codigo);
	bool eliminarPuesto(int codigo);
	
	string mostrarPuestos();
	
	void autoGuardar(ofstream& salida);
	void autoLeer(ifstream& entrada);
private:
	
	NodoPuesto *cabeza;
	NodoPuesto *actual;
	NodoPuesto *cola;
	
	ListaPuesto(const ListaPuesto&) = delete;
	ListaPuesto& operator=(const ListaPuesto&) = delete;
};

#endif


