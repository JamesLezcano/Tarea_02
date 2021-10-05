#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include <iostream>
#include "DatosEmpleado.h"

class EmpleadoAsalariado : public Empleado {
    
    double sueldoBruto;
    double sueldoNeto;
    double impuestos;
    
    protected:
    virtual std::ostream& serializar(std::ostream& out) const;

    public:
    EmpleadoAsalariado(std::string, std::string, int, double);

};

#endif