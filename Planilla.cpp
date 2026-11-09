//en esta clase planilla podemos observar como se da el principio SOLID de inversion de dependencia, ya que la clase planilla trabaja directamente con la clase abstracta de Empleado y no con las clases concretas de medico administrativo y enfermero 
//esto tambien es gracias al polimorfismo ya que cada empleado ejecuta su propios metodos para realizar los calculos y esto permite poder agregar diferentes tipos de empleados sin tener que modificar la clase planilla 
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

