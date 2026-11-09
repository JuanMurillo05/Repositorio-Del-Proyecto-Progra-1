#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>//libreria para que asi se muestren numeros grandes ya que aveces si el calculo da un numero muy grande el numero no se muestra, por eso tambien usamos fixed(2) para que nos de dos numeros decimales 
#include <fstream>
//la clase empleado es una clase abstracta quiere decir que como tal no se puede crear un objeto de tipo empleado sino que sera de tipo medico, administativo o enfermero
//por eso tenemos atributos protegidos para que asi estos los hereden las clases hijas
//se utiliza el principio SOLID sobre responsabilidad unica ya que esta clase se encarga de obtener la informacion del empleado y de hacer los calculos salariales
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
