#include "nodo.h"
#include <iostream>
#include "DatosEmpleado.h"

Nodo::Nodo(int id_Empleado, Empleado *datos_Empleado,int id_Supervisor)
{
    this->id_Empleado = id_Empleado;
    this->datos_Empleado = datos_Empleado;
    this->id_Supervisor = id_Supervisor;
}

Nodo::~Nodo(){
    std::clog << "Borrando nodo " << this->id_Empleado << std::endl;
    for (Nodo* hijo : this->hijos)
    {
        delete hijo;
    }
    std::clog << "Termina de borrar nodo " << this->id_Empleado<< std::endl;
}

void Nodo::AgregarHijo(Nodo *hijo) {
    this->hijos.push_back(hijo);
}

std::string Jefe;
std::ostream& operator << (std::ostream &o, const Nodo &nodo){
    if(nodo.id_Supervisor==0){
        Jefe ="             ";
    }
    // Imprimir información del nodo
    o << nodo.id_Empleado;
    o << " ,       ";
    o << nodo.datos_Empleado->getNombre();
    o << " ,       ";
    o<< Jefe;
    o << " ,       ";
    o << nodo.datos_Empleado->getSueldoNeto(); 
    o << std::endl;
    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.hijos) {
        Jefe = nodo.datos_Empleado->getNombre();
        o << *nodoHijo ;  
    }
    return o;
}