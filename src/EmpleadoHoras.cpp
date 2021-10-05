#include "EmpleadoHoras.h"
#include<iostream>
using namespace std;

EmpleadoHoras::EmpleadoHoras(std::string nombreCompleto, std::string correo, int tipoEmpleado,double horasTrabajadas,double salarioHora)
{
    this->nombreCompleto = nombreCompleto;
    this->correo = correo;
    this->tipoEmpleado = tipoEmpleado;
    this->sueldoBruto=horasTrabajadas* salarioHora;
    this->impuestos = 0;
    this->sueldoNeto = sueldoBruto - impuestos;
}


string EmpleadoHoras::getNombre(){
    return nombreCompleto;
}

string EmpleadoHoras::getCorreo(){
    return correo;
}

int EmpleadoHoras::getTipoEmpleado(){
    return tipoEmpleado;
}

double EmpleadoHoras::getSueldoBruto(){
    return sueldoBruto;
}

double EmpleadoHoras::getSueldoNeto(){
    return sueldoNeto;
}

double EmpleadoHoras::getImpuestos(){
    return impuestos;
}

std::ostream& EmpleadoHoras::serializar(std::ostream& o) const {
    o << nombreCompleto << ", ";
    o << correo << ", ";
    o << tipoEmpleado<<", ";
    o << sueldoBruto<<", ";
    o << sueldoNeto<<", ";
    o << impuestos;
    return o;
}