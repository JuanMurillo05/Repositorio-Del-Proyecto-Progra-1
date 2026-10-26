#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Empleado {
public:
	Empleado();
	Empleado(string nombre, string cedula, int codigoDepartamento);
	virtual ~Empleado();
	
	//setters y getters
	
	void setNombre(string nombre);
	void setCedula(string cedula);
	void setCodigoDepartamento(int codigoDepartamento);
	
	string getNombre();
	string getCedula();
	int getCodigoDepartamento();
	
	virtual float calcularSalarioBruto() =0;
	virtual float calcularDeducciones() =0;
	virtual float calcularSalarioNeto() =0;
	
private:
	string nombre;
	string cedula;
	int codigoDepartamento;
	
};

#endif


