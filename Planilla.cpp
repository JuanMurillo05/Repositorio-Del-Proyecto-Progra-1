//Principio SOLID inversion de dependencia, la clase planilla depende de la abstraccion Empleado, no de Medico, Enfermero o Administrativo
//ya que la funcion de calcularSalarioBruto se ejecuta dependiendo de la clase gracias al polimorfismo y por eso
//se pueden agregar tipos nuevos sin modificar la clase

#include "Planilla.h"

Planilla::Planilla(ListaEmpleado* empleados, ListaDepartamento* departamentos) {
	listaEmpleado = empleados;
	listaDepartamento = departamentos;
}
Planilla::~Planilla(){

}
string Planilla::generarPlanilla(){
	stringstream x;

	if(listaEmpleado == NULL || listaDepartamento == NULL){
		return "Listas vacias";
	}
	if(listaEmpleado->vacio()){
		return "No hay empleados registrados";
	}

	x << fixed << setprecision(2);

	x << "=============== PLANILLA DE HOSPITAL =============== " << endl;
	NodoEmpleado* actual = listaEmpleado->getCabeza();

	while(actual != NULL){
		Empleado* empleado = actual->getDato();

		Departamento* departamento = listaDepartamento->buscarDepartamento(empleado->getCodigoDepartamento());

		x << endl;
		x << "Empleado : " << empleado->getNombre() << endl;
		x << "Cedula : " << empleado->getCedula() << endl;

		if(departamento != NULL){
			x << "Departamento : " << departamento->getNombre() << endl;
		}else{
			x << "Departamento no encontrado " << endl;
		}

		x << "Salario Bruto : " << empleado->calcularSalarioBruto() << endl;
		x << "Deducciones : " << empleado->calcularDeducciones() << endl;
		x << "Salario Neto : " << empleado->calcularSalarioNeto() << endl;
		x << "--------------------------------------------------------" << endl;

		actual = actual->getSiguiente();
	}

	x << endl;
	x << "Total salario bruto : " << calcularTotalBruto() << endl;
	x << "Total deducciones : " << calcularTotalDeducciones() << endl;
	x << "Total salario neto : " << calcularTotalNeto() << endl;

	return x.str();

}
string Planilla::generarRegistro(int numero, int mes, int anio){
	if(listaEmpleado == NULL){
		return "";
	}

	stringstream x;
	x << fixed << setprecision(2);

	//formato: una linea de encabezado, una linea por empleado y una linea de totales
	x << "PLANILLA " << numero << " " << mes << " " << anio << " " << listaEmpleado->contar() << endl;

	NodoEmpleado* actual = listaEmpleado->getCabeza();

	while(actual != NULL){
		Empleado* empleado = actual->getDato();

		x << empleado->getCedula() << " " << empleado->getNombre() << " " << empleado->getCodigoDepartamento() << " ";
		x << empleado->calcularSalarioBruto() << " " << empleado->calcularDeducciones() << " " << empleado->calcularSalarioNeto() << endl;

		actual = actual->getSiguiente();
	}

	x << "TOTAL " << calcularTotalBruto() << " " << calcularTotalDeducciones() << " " << calcularTotalNeto() << endl;

	return x.str();
}
double Planilla::calcularTotalBruto(){
	double total = 0;

	NodoEmpleado* actual = listaEmpleado->getCabeza();

	while(actual != NULL){
		total = total + actual->getDato()->calcularSalarioBruto();
		actual = actual->getSiguiente();
	}
	return total;
}
double Planilla::calcularTotalDeducciones(){
	double total = 0;

	NodoEmpleado* actual = listaEmpleado->getCabeza();

	while(actual != NULL){
		total = total + actual->getDato()->calcularDeducciones();
		actual = actual->getSiguiente();
	}
	return total;
}
double Planilla::calcularTotalNeto(){
	double total =0;

	NodoEmpleado* actual = listaEmpleado->getCabeza();

	while(actual != NULL){
		total = total + actual->getDato()->calcularSalarioNeto();
		actual = actual->getSiguiente();
	}
	return total;
}
