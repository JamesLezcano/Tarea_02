#include "EmpleadoAsalariado.h"
#include<iostream>
using namespace std;
EmpleadoAsalariado::EmpleadoAsalariado(std::string nombreCompleto, std::string correo, int tipoEmpleado,double sueldoBruto)
{
    this->nombreCompleto = nombreCompleto;
    this->correo = correo;
    this->tipoEmpleado = tipoEmpleado;
    this->sueldoBruto=sueldoBruto;
    this->impuestos = sueldoBruto*0.07;
    this->sueldoNeto = sueldoBruto - impuestos;
    
}

std::ostream& EmpleadoAsalariado::serializar(std::ostream& o) const {

    o << this->nombreCompleto << ", ";
    o << this->correo << ", ";
    o << this->tipoEmpleado<<", ";
    o << this->sueldoBruto<<", ";
    o << this->sueldoNeto<<", ",
    o << this->impuestos;
    return o;
}