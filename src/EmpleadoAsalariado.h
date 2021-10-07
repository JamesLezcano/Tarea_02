#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include <iostream>
#include "DatosEmpleado.h"

class EmpleadoAsalariado : public Empleado {
    private:
        double sueldoBruto;
        double sueldoNeto;
        double impuestos;
    protected:
        virtual std::ostream& serializar(std::ostream& out) const;
    public:
        EmpleadoAsalariado(std::string, std::string, int, double);
        std::string getNombre();
        std::string getCorreo();
        int getTipoEmpleado();
        double getSueldoBruto();
        double getSueldoNeto();
        double getImpuestos();
};

#endif