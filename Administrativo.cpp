//Principio SOLID sustitucion de Liskov, en nuestra clase de Administrativo no le agregamos bonificaciones entonces devolvera 0 y no dara error
//ya que recordemos que este principio dice que donde espera un objeto de la clase padre debe de ser capaz de recibir uno de la clase hija 

#include "Administrativo.h"

Administrativo::Administrativo() : Empleado() {
	puestoLaboral = "";
}
Administrativo::Administrativo(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra,
                               string puestoLaboral)
	: Empleado(nombre, cedula, codigoDepartamento, salarioBase, horasExtra) {
	this->puestoLaboral = puestoLaboral;
}
Administrativo::~Administrativo(){

}
//setters y getters
void Administrativo::setPuestoLaboral(string puestoLaboral){
	this->puestoLaboral = puestoLaboral;
}
string Administrativo::getPuestoLaboral(){
	return puestoLaboral;
}

double Administrativo::calcularBonificaciones(){
	return 0;
}
string Administrativo::getTipo(){
	return "Administrativo";
}
void Administrativo::autoGuardar(ofstream& salida){
	Empleado::autoGuardar(salida); // campos comunes
	salida << puestoLaboral << endl;
}
Empleado* Administrativo::autoLeer(ifstream& entrada){
	Administrativo* administrativo = new Administrativo();
	entrada >> administrativo->nombre >> administrativo->cedula >> administrativo->codigoDepartamento
	        >> administrativo->salarioBase >> administrativo->horasExtra
	        >> administrativo->puestoLaboral;
	return administrativo;
}
string Administrativo::toString(){
	stringstream x;
	x << Empleado::toString();
	x << "Puesto laboral : " << puestoLaboral << endl;
	return x.str();
}
