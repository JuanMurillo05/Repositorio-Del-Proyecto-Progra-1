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

//evitan que se copien listas lo cual podria provocar que dos listas compartan el mismo nodo y que se libere dos veces la misma memoria 
	ListaPuesto(const ListaPuesto&) = delete;
	ListaPuesto& operator=(const ListaPuesto&) = delete;
};

#endif


