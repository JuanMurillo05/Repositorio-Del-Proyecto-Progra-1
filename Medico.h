#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

class Medico : public Empleado {
public:
	Medico();
	Medico(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra,
	       string especialidad, int cantidadGuardias, double pagoPorGuardia);
	virtual ~Medico();

	void setEspecialidad(string especialidad);
	void setCantidadGuardias(int cantidadGuardias);
	void setPagoPorGuardia(double pagoPorGuardia);

	string getEspecialidad();
	int getCantidadGuardias();
	double getPagoPorGuardia();

	// Bonificacion = guardias realizadas x pago por guardia
	double calcularBonificaciones();

	string getTipo();
	void autoGuardar(ofstream& salida);
	Empleado* autoLeer(ifstream& entrada);
	string toString();

private:
	string especialidad;
	int cantidadGuardias;
	double pagoPorGuardia;
};

#endif
