#include "nodo.h"
#include <iostream>
#include "DatosEmpleado.h"

Nodo::Nodo(int id_Empleado, Empleado *datos_Empleado,int id_Supervisor)
{
    this->id_Empleado = id_Empleado;
    this->datos_Empleado = datos_Empleado;
    this->id_Supervisor = id_Supervisor;
}

Nodo::~Nodo()
{
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

std::ostream& operator << (std::ostream &o, const Nodo &nodo)
{
    
    // Imprimir información del nodo
    o << "   Id empleado: ";
    o << nodo.id_Empleado;
    o << ",     Datos: ";
    o << nodo.datos_Empleado->getNombre();
    o <<"     ";
    o << nodo.datos_Empleado->getSueldoNeto();
    o << ",     Padre: ";
    o << nodo.id_Supervisor;
    o << std::endl;
    
    

    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.hijos)
    {
        o << nodo.datos_Empleado->getNombre();
        o << *nodoHijo ;
       
    }

    return o;
}