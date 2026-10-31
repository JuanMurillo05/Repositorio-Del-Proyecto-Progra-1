#include "Empleado.h"

// Constantes del calculo salarial de CR :)
// Si cambia una tarifa, solo se modifica aqui
// Horas extra
const double horasMensuales = 240.0;
const double facHoraExtra = 1.5;
	
// Cuota CCSS + Banco Popular
const double porcentajeSEM = 0.0550; // Seguro de Enfermedad y Maternidad
const double porcentajePension = 0.0433; // Seguro de Invalidez y Muerte
const double porcentajeBP = 0.0100; // Banco Popular
	
// Impuesto sobre la renta de salarios
// No incluye creditos fiscales
const double rentaExento=918000.0;
const double rentaTramo1=1347000.0;
const double rentaTramo2=2364000.0;
const double rentaTramo3=4727000.0;
const double tasa1=0.10;
const double tasa2=0.15;
const double tasa3=0.20;
const double tasa4=0.25;

double menor(double a, double b){
	return a<b?a:b;
}
	
Empleado::Empleado(){
	nombre="";
	cedula="";
	codigoDepartamento=0;
	salarioBase=0;
	horasExtra=0;
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

// Setters y getters
void Empleado::setNombre(string nombre){
	this->nombre=nombre;
}

void Empleado::setCedula(string cedula){
	this->cedula=cedula;
}

void Empleado::setCodigoDepartamento(int codigoDepartamento){
	this->codigoDepartamento=codigoDepartamento;
}

void Empleado::setSalarioBase(double salarioBase){
	this->salarioBase=salarioBase;
}

void Empleado::setHorasExtra(int horasExtra){
	this->horasExtra=horasExtra;
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
	return salarioBase/horasMensuales;
}

double Empleado::calcularPagoHorasExtra(){
	return horasExtra*calcularValorHora()*facHoraExtra;
}

double Empleado::calcularSalarioBruto(){
	return salarioBase+calcularPagoHorasExtra()+calcularBonificaciones();
}

double Empleado::calcularCuotaCCSS(){
	return calcularSalarioBruto()*(porcentajeSEM+porcentajePension+porcentajeBP);
}

double Empleado::calcularImpuestoRenta(){
	double bruto=calcularSalarioBruto();
	double impuesto=0;
	
	if(bruto>rentaExento){
		impuesto+=(menor(bruto, rentaTramo1)-rentaExento)*tasa1;
	}
	
	if(bruto>rentaTramo1){
		impuesto+=(menor(bruto, rentaTramo2)-rentaTramo1)*tasa2;
	}
	
	if(bruto>rentaTramo2){
		impuesto+=(menor(bruto, rentaTramo3)-rentaTramo2)*tasa3;
	}
	
	if(bruto>rentaTramo3){
		impuesto+=(bruto-rentaTramo3)*tasa4;
	}
	
	return impuesto;
}

double Empleado::calcularDeducciones(){
	return calcularCuotaCCSS()+calcularImpuestoRenta();
}

double Empleado::calcularSalarioNeto(){
	return calcularSalarioBruto()-calcularDeducciones();
}

void Empleado::autoGuardar(ofstream& salida){
	salida<<fixed<<setprecision(2);
	salida<<getTipo()<<" "<<nombre<<" "<<cedula<<" "<<codigoDepartamento << " "<<salarioBase << " "<<horasExtra << " ";
}

string Empleado::toString(){
	stringstream x;
	x<<fixed<<setprecision(2);
	x<<"Tipo: "<<getTipo()<<endl;
	x<<"Nombre: "<<nombre<<endl;
	x<<"Cedula: "<<cedula<<endl;
	x<<"Codigo de departamento: "<<codigoDepartamento<<endl;
	x<<"Salario base: "<<salarioBase<<endl;
	x<<"Horas extra ("<<horasExtra<<") : "<<calcularPagoHorasExtra()<<endl;
	x<<"Bonificaciones : "<<calcularBonificaciones()<<endl;
	x<<"Salario bruto : "<<calcularSalarioBruto()<<endl;
	x<<"Cuota CCSS y Banco Popular : "<<calcularCuotaCCSS()<<endl;
	x<<"Impuesto sobre la renta : "<<calcularImpuestoRenta()<<endl;
	x<<"Total deducciones : "<<calcularDeducciones()<<endl;
	x<<"Salario neto : "<<calcularSalarioNeto()<<endl;
	
	return x.str();
}
