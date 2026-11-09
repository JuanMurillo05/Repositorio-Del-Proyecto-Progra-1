#ifndef PLANILLA_H
#define PLANILLA_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "ListaEmpleado.h"
#include "ListaDepartamento.h"

//clase encargada de generar la planilla de los empleados, la cual para hacerlo trabaja con la listaEmpleado y la ListaDepartamento para obtener la informacion y asi poder hacer el calculo 

using namespace std;

class Planilla {
public:
	
	Planilla(ListaEmpleado* empleados, ListaDepartamento* departamentos);
	~Planilla();
	
	string generarPlanilla();
	
	double calcularTotalBruto();
	double calcularTotalDeducciones();
	double calcularTotalNeto();
	
private:
	
	ListaEmpleado* listaEmpleado;
	ListaDepartamento* listaDepartamento;
	
};

#endif


