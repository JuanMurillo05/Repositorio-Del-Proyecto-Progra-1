#include "Medico.h"

Medico::Medico():Empleado(){
	especialidad="";
	cantidadGuardias=0;
	pagoPorGuardia=0;
}
Medico::Medico(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra, string especialidad, int cantidadGuardias, double pagoPorGuardia):Empleado(nombre, cedula, codigoDepartamento, salarioBase, horasExtra) {
	this->especialidad=especialidad;
	this->cantidadGuardias=cantidadGuardias;
	this->pagoPorGuardia=pagoPorGuardia;
}
Medico::~Medico(){
	
}
//setters y getters
void Medico::setEspecialidad(string especialidad){
	this->especialidad=especialidad;
}
void Medico::setCantidadGuardias(int cantidadGuardias){
	this->cantidadGuardias=cantidadGuardias;
}
void Medico::setPagoPorGuardia(double pagoPorGuardia){
	this->pagoPorGuardia=pagoPorGuardia;
}
string Medico::getEspecialidad(){
	return especialidad;
}
int Medico::getCantidadGuardias(){
	return cantidadGuardias;
}
double Medico::getPagoPorGuardia(){
	return pagoPorGuardia;
}

double Medico::calcularBonificaciones(){
	return cantidadGuardias*pagoPorGuardia;
}
string Medico::getTipo(){
	return "Medico";
}
void Medico::autoGuardar(ofstream& salida){
	Empleado::autoGuardar(salida);
	salida<<especialidad<<" "<<cantidadGuardias<<" "<<pagoPorGuardia<<endl;
}
Empleado* Medico::autoLeer(ifstream& entrada){
	Medico* medico=new Medico();
	entrada>>medico->nombre>>medico->cedula>>medico->codigoDepartamento>>medico->salarioBase>>medico->horasExtra>>medico->especialidad>>medico->cantidadGuardias>>medico->pagoPorGuardia;
	return medico;
}
string Medico::toString(){
	stringstream x;
	x<<Empleado::toString();
	x<<fixed<<setprecision(2);
	x<<"Especialidad: "<<especialidad << endl;
	x<<"Guardias realizadas: "<<cantidadGuardias << endl;
	x<<"Pago por guardia: "<<pagoPorGuardia << endl;
	return x.str();
}
