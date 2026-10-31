#include "Puesto.h"

Puesto::Puesto() {
	
	nombrePuesto = new string("");
	codigo = new int(0);
	
}
Puesto::Puesto(string nombrePuesto,int codigo){
	
	this->nombrePuesto = new string(nombrePuesto);
	this->codigo = new int(codigo);
	
}
Puesto::~Puesto() {
	
	delete nombrePuesto;
	delete codigo;
	
}

void Puesto::setNombrePuesto(string nombrePuesto){
	*this->nombrePuesto = nombrePuesto;
}
void Puesto::setCodigo(int codigo){
	*this->codigo = codigo;
}

string Puesto::getNombrePuesto(){
	return *nombrePuesto;
}
int Puesto::getCodigo(){
	return *codigo;
}

void Puesto::autoGuardar(ofstream& salida){
	salida<<*codigo<<" "<<*nombrePuesto<<endl;
}

void Puesto::autoLeer(ifstream& entrada){
	entrada>>*codigo;
	entrada>>ws;
	getline(entrada,*nombrePuesto);
}

string Puesto::toString(){
	stringstream a;
	
	a<<"nombre del puesto: "<<*nombrePuesto<<endl;
	a<<"codigo: "<<*codigo<<endl;
	
	return a.str();
}

