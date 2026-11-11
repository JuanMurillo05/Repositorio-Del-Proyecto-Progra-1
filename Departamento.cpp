#include "Departamento.h"

Departamento::Departamento() {
	
	codigoDepartamento = new int(0);
	nombreDepartamento = new string("");
	listaPuesto = new ListaPuesto();
}

Departamento::Departamento(int codigoDepartamento, string nombreDepartamento){
	
	this->codigoDepartamento = new int(codigoDepartamento);
	this->nombreDepartamento = new string(nombreDepartamento);
	listaPuesto = new ListaPuesto();
	
}

Departamento::~Departamento() {
	
	delete codigoDepartamento;
	delete nombreDepartamento;
	delete listaPuesto;
	
}

void Departamento::setCodigoDepartamento(int codigoDepartamento){
	*this->codigoDepartamento = codigoDepartamento;
}

void Departamento::setNombre(string nombreDepartamento){
	*this->nombreDepartamento = nombreDepartamento;
}

int Departamento::getCodigoDepartamento(){
	return *codigoDepartamento;
}

string Departamento::getNombre(){
	return *nombreDepartamento;
}

void Departamento::agregarPuesto(Puesto *puesto){
	listaPuesto->agregarPuesto(puesto);
}

Puesto *Departamento::buscarPuesto(int codigo){
	return listaPuesto->buscarPuesto(codigo);
}

bool Departamento::eliminarPuesto(int codigo){
	return listaPuesto->eliminarPuesto(codigo);
}

string Departamento::mostrarPuesto(){
	return listaPuesto->mostrarPuestos();
}

void Departamento::autoGuardar(ofstream& salida){
	
	salida<<*codigoDepartamento<<" "<<*nombreDepartamento<<endl;
	listaPuesto->autoGuardar(salida);
	
}

void Departamento::autoLeer(ifstream& entrada){
	
	entrada>>*codigoDepartamento>>*nombreDepartamento;
	listaPuesto->autoLeer(entrada);
	
}

string Departamento::toString(){
	stringstream a;
	
	a<<"codigo del departamento: "<<*codigoDepartamento<<endl;
	a<<"nombre del departamento: "<<*nombreDepartamento<<endl;
	a<<"puesto: "<<endl;
	a<<listaPuesto->mostrarPuestos();
	
	return a.str();
}
