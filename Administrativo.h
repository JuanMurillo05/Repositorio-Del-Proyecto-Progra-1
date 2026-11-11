#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"

class Administrativo : public Empleado {
public:
	Administrativo();
	Administrativo(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra,
	               string puestoLaboral);
	virtual ~Administrativo();

	void setPuestoLaboral(string puestoLaboral);
	string getPuestoLaboral();

	// El personal administrativo no recibe guardias ni turnos nocturnos
	double calcularBonificaciones();

	string getTipo();
	void autoGuardar(ofstream& salida);
	Empleado* autoLeer(ifstream& entrada);
	string toString();

private:
	string puestoLaboral;
};

#endif
