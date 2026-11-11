#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> //libreria para que asi se muestren numeros grandes ya que aveces si el calculo da un numero muy grande el numero no se muestra, por eso tambien usamos fixed(2) para que nos de dos numeros decimales
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

	//setters y getters
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

	// ---- Desglose del salario ----
	double calcularValorHora();
	double calcularPagoHorasExtra();

	// Cada tipo de empleado define sus propias bonificaciones
	// (guardias, turnos nocturnos, etc.).
	virtual double calcularBonificaciones() = 0;
	// Bruto = base + horas extra + bonificaciones
	virtual double calcularSalarioBruto();
	// Deducciones de ley
	double calcularCuotaCCSS();
	double calcularImpuestoRenta();
	virtual double calcularDeducciones();
	// Neto = bruto - deducciones
	virtual double calcularSalarioNeto();
	// Etiqueta del tipo: "MEDICO", "ENFERMERO", "ADMINISTRATIVO"
	virtual string getTipo() = 0;
	// Escribe el inicio del registro, separado por espacios:
	//   TIPO nombre cedula codDepto salarioBase horasExtra
	// Cada hija llama a Empleado::autoGuardar(salida), agrega sus propios campos y termina la linea con endl.
	virtual void autoGuardar(ofstream& salida);
	// Lee con >> el resto de un registro cuya etiqueta de tipo ya fue leida y devuelve un empleado nuevo (new). Se llama sobre un objeto del tipo correcto, que solo sirve para decidir cual hija hace la lectura.
	virtual Empleado* autoLeer(ifstream& entrada) = 0;
	// Texto con los datos y el desglose del salario (sin cout)
	virtual string toString();

protected:
	string nombre;
	string cedula;
	int codigoDepartamento;
	double salarioBase;
	int horasExtra;
};

#endif
