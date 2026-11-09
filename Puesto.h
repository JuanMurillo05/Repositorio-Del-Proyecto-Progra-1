#ifndef PUESTO_H
#define PUESTO_H
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

//clase que representa un puesto dentro de un departamento

using namespace std;

class Puesto {
public:
	Puesto();
	Puesto(string nombrePuesto,int codigo);
	virtual~Puesto();
	
	void setNombrePuesto(string nombrePuesto);
	void setCodigo(int codigo);
	
	string getNombrePuesto();
	int getCodigo();
	
	void autoGuardar(ofstream& salida);
	void autoLeer(ifstream& entrada);
	string toString();
private:
	
	string *nombrePuesto;
	int *codigo;
	
};

#endif


