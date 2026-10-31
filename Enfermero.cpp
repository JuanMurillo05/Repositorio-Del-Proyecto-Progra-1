#include "Enfermero.h"

Enfermero::Enfermero():Empleado() {
	cantidadTurnosNocturnos = 0;
	pagoPorTurnoNocturno = 0;
}
Enfermero::Enfermero(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra, int cantidadTurnosNocturnos, double pagoPorTurnoNocturno):Empleado(nombre, cedula, codigoDepartamento, salarioBase, horasExtra) {
	this->cantidadTurnosNocturnos=cantidadTurnosNocturnos;
	this->pagoPorTurnoNocturno=pagoPorTurnoNocturno;
}
Enfermero::~Enfermero(){
	
}
//setters y getters
void Enfermero::setCantidadTurnosNocturnos(int cantidadTurnosNocturnos){
	this->cantidadTurnosNocturnos=cantidadTurnosNocturnos;
}
void Enfermero::setPagoPorTurnoNocturno(double pagoPorTurnoNocturno){
	this->pagoPorTurnoNocturno=pagoPorTurnoNocturno;
}
int Enfermero::getCantidadTurnosNocturnos(){
	return cantidadTurnosNocturnos;
}
double Enfermero::getPagoPorTurnoNocturno(){
	return pagoPorTurnoNocturno;
}

double Enfermero::calcularBonificaciones(){
	return cantidadTurnosNocturnos*pagoPorTurnoNocturno;
}
string Enfermero::getTipo(){
	return "Enfermero";
}
void Enfermero::autoGuardar(ofstream& salida){
	Empleado::autoGuardar(salida);
	salida<<cantidadTurnosNocturnos<<" "<<pagoPorTurnoNocturno<<endl;
}
Empleado* Enfermero::autoLeer(ifstream& entrada){
	Enfermero* enfermero=new Enfermero();
	entrada>>enfermero->nombre>>enfermero->cedula>>enfermero->codigoDepartamento>>enfermero->salarioBase>>enfermero->horasExtra>>enfermero->cantidadTurnosNocturnos>>enfermero->pagoPorTurnoNocturno;
	return enfermero;
}
string Enfermero::toString(){
	stringstream x;
	x<<Empleado::toString();
	x<<fixed << setprecision(2);
	x<<"Turnos nocturnos: "<<cantidadTurnosNocturnos<<endl;
	x<<"Pago por turno nocturno: "<<pagoPorTurnoNocturno<<endl;
	return x.str();
}
