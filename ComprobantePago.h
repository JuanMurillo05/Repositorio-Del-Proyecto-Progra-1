#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include "ListaEmpleado.h"
#include "ListaDepartamento.h"

//relacion de agregacion: el comprobante solo guarda referencias (punteros) al empleado y al departamento
//no los crea ni los elimina, ellos siguen existiendo en sus propias listas aunque el comprobante desaparezca
//los montos se guardan al momento del pago, asi el comprobante no cambia si despues cambia el salario

class ComprobantePago {
public:
	ComprobantePago();
	ComprobantePago(int numero, int mes, int anio, Empleado* empleado, Departamento* departamento);
	virtual ~ComprobantePago();
	
	int getNumero();
	int getMes();
	int getAnio();
	Empleado* getEmpleado();
	Departamento* getDepartamento();
	
	void autoGuardar(ofstream& salida);
	bool autoLeer(ifstream& entrada, ListaEmpleado& empleados, ListaDepartamento& departamentos);
	string toString();
	
private:
	int numero;
	int mes;
	int anio;
	Empleado* empleado;
	Departamento* departamento;
	double salarioBruto;
	double deducciones;
	double salarioNeto;
};

#endif
