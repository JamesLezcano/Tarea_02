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


string EmpleadoAsalariado::getNombre(){
    return nombreCompleto;
}

string EmpleadoAsalariado::getCorreo(){
    return correo;
}

int EmpleadoAsalariado::getTipoEmpleado(){
    return tipoEmpleado;
}

double EmpleadoAsalariado::getSueldoBruto(){
    return sueldoBruto;
}

double EmpleadoAsalariado::getSueldoNeto(){
    return sueldoNeto;
}

double EmpleadoAsalariado::getImpuestos(){
    return impuestos;
}

std::ostream& EmpleadoAsalariado::serializar(std::ostream& o) const {
    o << nombreCompleto << ", ";
    o << correo << ", ";
    o << tipoEmpleado<<", ";
    o << sueldoBruto<<", ";
    o << sueldoNeto<<", ";
    o << impuestos;
    return o;
}
 
