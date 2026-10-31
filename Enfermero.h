#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

class Enfermero : public Empleado {
public:
	Enfermero();
	Enfermero(string nombre, string cedula, int codigoDepartamento, double salarioBase, int horasExtra, int cantidadTurnosNocturnos, double pagoPorTurnoNocturno);
	virtual ~Enfermero();
	
	void setCantidadTurnosNocturnos(int cantidadTurnosNocturnos);
	void setPagoPorTurnoNocturno(double pagoPorTurnoNocturno);
	
	int getCantidadTurnosNocturnos();
	double getPagoPorTurnoNocturno();
	
	//Bonificacion=turnos nocturnos x pago por turno nocturno
	double calcularBonificaciones();
	
	string getTipo();
	void autoGuardar(ofstream& salida);
	Empleado* autoLeer(ifstream& entrada);
	string toString();
	
private:
	int cantidadTurnosNocturnos;
	double pagoPorTurnoNocturno;
};

#endif
