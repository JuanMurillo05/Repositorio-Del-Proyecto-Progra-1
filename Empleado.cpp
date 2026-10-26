#include "Empleado.h"

Empleado::Empleado() {
	nombre = " ";
	cedula = " ";
	codigoDepartamento = 0;
}
Empleado::Empleado(string nombre, string cedula, int codigoDepartamento){
	this-> nombre = nombre;
	this-> cedula = cedula;
	this-> codigoDepartamento = codigoDepartamento;
}
Empleado::~Empleado(){
	
}
//setters y getters
void Empleado::setNombre(string nombre){
	this->nombre = nombre;
}
void Empleado::setCedula(string cedula){
	this->cedula = cedula;
}
void Empleado::setCodigoDepartamento(int codigoDepartamento){
	this->codigoDepartamento = codigoDepartamento;
}
string Empleado::getNombre(){
	return nombre;
}
string Empleado::getCedula(){
	return cedula;
}
int Empleado::getCodigoDepartamento(){
	return codigoDepartamento;
}


