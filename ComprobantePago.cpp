#include "ComprobantePago.h"

ComprobantePago::ComprobantePago() {
	numero = 0;
	mes = 0;
	anio = 0;
	empleado = NULL;
	departamento = NULL;
	salarioBruto = 0;
	deducciones = 0;
	salarioNeto = 0;
}

ComprobantePago::ComprobantePago(int numero, int mes, int anio, Empleado* empleado, Departamento* departamento){
	this->numero = numero;
	this->mes = mes;
	this->anio = anio;
	this->empleado = empleado;
	this->departamento = departamento;
	
	//los montos se calculan una sola vez, al generar el comprobante
	salarioBruto = empleado->calcularSalarioBruto();
	deducciones = empleado->calcularDeducciones();
	salarioNeto = empleado->calcularSalarioNeto();
}

ComprobantePago::~ComprobantePago(){
	//no se elimina el empleado ni el departamento porque el comprobante no es su dueño (agregacion)
}

int ComprobantePago::getNumero(){
	return numero;
}

int ComprobantePago::getMes(){
	return mes;
}

int ComprobantePago::getAnio(){
	return anio;
}

Empleado* ComprobantePago::getEmpleado(){
	return empleado;
}

Departamento* ComprobantePago::getDepartamento(){
	return departamento;
}

//en el archivo no se pueden guardar punteros, por eso se guarda la cedula del empleado y el codigo del departamento
void ComprobantePago::autoGuardar(ofstream& salida){
	salida << fixed << setprecision(2);
	salida << numero << " " << mes << " " << anio << " "
		<< empleado->getCedula() << " " << departamento->getCodigoDepartamento() << " "
		<< salarioBruto << " " << deducciones << " " << salarioNeto << endl;
}

//al leer se vuelven a enlazar los punteros buscando el empleado y el departamento en sus listas
//devuelve false si la lectura falla o si alguno de los dos ya no existe
bool ComprobantePago::autoLeer(ifstream& entrada, ListaEmpleado& empleados, ListaDepartamento& departamentos){
	string cedula;
	int codigoDepartamento = 0;
	
	entrada >> numero >> mes >> anio >> cedula >> codigoDepartamento >> salarioBruto >> deducciones >> salarioNeto;
	if(!entrada){
		return false;
	}
	
	empleado = empleados.buscarPorCedula(cedula);
	departamento = departamentos.buscarDepartamento(codigoDepartamento);
	
	return empleado != NULL && departamento != NULL;
}

string ComprobantePago::toString(){
	stringstream x;
	x << fixed << setprecision(2);
	x << "Comprobante numero: " << numero << endl;
	x << "Periodo: " << mes << "/" << anio << endl;
	x << "Empleado: " << empleado->getNombre() << " (" << empleado->getCedula() << ")" << endl;
	x << "Departamento: " << departamento->getNombre() << endl;
	x << "Salario bruto: " << salarioBruto << endl;
	x << "Deducciones: " << deducciones << endl;
	x << "Salario neto: " << salarioNeto << endl;
	return x.str();
}
