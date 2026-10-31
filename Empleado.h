#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

class Empleado {
public:
	Empleado();
	Empleado(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra);
	virtual ~Empleado();
	
	void setNombre(string nombre);
	void setCedula(string cedula);
	void setCodigoDepartamento(int codigoDepartamento);
	void setSalarioBase(double salarioBase);
	void setHorasExtra(int horasExtra);
	
	string getNombre();
	string getCedula();
	int getCodigoDepartamento();
	double getSalarioBase();
	int getHorasExtra();

	double calcularValorHora();
	double calcularPagoHorasExtra();
	virtual double calcularBonificaciones() = 0;
	virtual double calcularSalarioBruto();
	double calcularCuotaCCSS();
	double calcularImpuestoRenta();
	virtual double calcularDeducciones();
	virtual double calcularSalarioNeto();
	virtual string getTipo() = 0;
	virtual void autoGuardar(ofstream& salida);
	virtual Empleado* autoLeer(ifstream& entrada) = 0;
	virtual string toString();
	
protected:
	string nombre;
	string cedula;
	int codigoDepartamento;
	double salarioBase;
	int horasExtra;
};

#endif
