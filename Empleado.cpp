#include "Empleado.h"

// Constantes del calculo salarial (Costa Rica, periodo fiscal 2026).
// Si cambia una tarifa, solo se modifica aqui.
// Horas extra: jornada mensual (30 dias x 8 horas) y recargo del 50%
const double HORAS_MENSUALES = 240.0;
const double FACTOR_HORA_EXTRA = 1.5;

// Cuota obrera CCSS + Banco Popular (2026)
const double PORC_SEM = 0.0550;
const double PORC_IVM = 0.0433;
const double PORC_BANCO_POPULAR = 0.0100;

// Impuesto sobre la renta de salarios (tramos mensuales 2026)
// No incluye creditos fiscales por hijos ni conyuge.
const double RENTA_EXENTO = 918000.0;
const double RENTA_TRAMO_1 = 1347000.0;
const double RENTA_TRAMO_2 = 2364000.0;
const double RENTA_TRAMO_3 = 4727000.0;
const double TASA_1 = 0.10;
const double TASA_2 = 0.15;
const double TASA_3 = 0.20;
const double TASA_4 = 0.25;

double menor(double a, double b){
	return a < b ? a : b;
}

Empleado::Empleado() {
	nombre = "";
	cedula = "";
	codigoDepartamento = 0;
	salarioBase = 0;
	horasExtra = 0;
}
Empleado::Empleado(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra){
	this->nombre = nombre;
	this->cedula = cedula;
	this->codigoDepartamento = codigoDepartamento;
	this->salarioBase = salarioBase;
	this->horasExtra = horasExtra;
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
void Empleado::setSalarioBase(double salarioBase){
	this->salarioBase = salarioBase;
}
void Empleado::setHorasExtra(int horasExtra){
	this->horasExtra = horasExtra;
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
double Empleado::getSalarioBase(){
	return salarioBase;
}
int Empleado::getHorasExtra(){
	return horasExtra;
}

// ---- Desglose del salario ----
double Empleado::calcularValorHora(){
	return salarioBase / HORAS_MENSUALES;
}
double Empleado::calcularPagoHorasExtra(){
	return horasExtra * calcularValorHora() * FACTOR_HORA_EXTRA;
}
double Empleado::calcularSalarioBruto(){
	return salarioBase + calcularPagoHorasExtra() + calcularBonificaciones();
}
double Empleado::calcularCuotaCCSS(){
	return calcularSalarioBruto() * (PORC_SEM + PORC_IVM + PORC_BANCO_POPULAR);
}
double Empleado::calcularImpuestoRenta(){
	double bruto = calcularSalarioBruto();
	double impuesto = 0;

	if(bruto > RENTA_EXENTO){
		impuesto += (menor(bruto, RENTA_TRAMO_1) - RENTA_EXENTO) * TASA_1;
	}
	if(bruto > RENTA_TRAMO_1){
		impuesto += (menor(bruto, RENTA_TRAMO_2) - RENTA_TRAMO_1) * TASA_2;
	}
	if(bruto > RENTA_TRAMO_2){
		impuesto += (menor(bruto, RENTA_TRAMO_3) - RENTA_TRAMO_2) * TASA_3;
	}
	if(bruto > RENTA_TRAMO_3){
		impuesto += (bruto - RENTA_TRAMO_3) * TASA_4;
	}
	return impuesto;
}
double Empleado::calcularDeducciones(){
	return calcularCuotaCCSS() + calcularImpuestoRenta();
}
double Empleado::calcularSalarioNeto(){
	return calcularSalarioBruto() - calcularDeducciones();
}

// ---- Persistencia ----
void Empleado::autoGuardar(ofstream& salida){
	// Deja 2 decimales fijos en el flujo para las hijas.
	salida << fixed << setprecision(2);
	salida << getTipo() << " " << nombre << " " << cedula << " "
	       << codigoDepartamento << " " << salarioBase << " " << horasExtra << " ";
}

// ---- Texto ----
string Empleado::toString(){
	stringstream x;
	x << fixed << setprecision(2);
	x << "Tipo : " << getTipo() << endl;
	x << "Nombre : " << nombre << endl;
	x << "Cedula : " << cedula << endl;
	x << "Codigo de departamento : " << codigoDepartamento << endl;
	x << "Salario base : " << salarioBase << endl;
	x << "Horas extra (" << horasExtra << ") : " << calcularPagoHorasExtra() << endl;
	x << "Bonificaciones : " << calcularBonificaciones() << endl;
	x << "Salario bruto : " << calcularSalarioBruto() << endl;
	x << "Cuota CCSS y Banco Popular : " << calcularCuotaCCSS() << endl;
	x << "Impuesto sobre la renta : " << calcularImpuestoRenta() << endl;
	x << "Total deducciones : " << calcularDeducciones() << endl;
	x << "Salario neto : " << calcularSalarioNeto() << endl;
	return x.str();
}
