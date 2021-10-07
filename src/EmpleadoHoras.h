#ifndef EMPLEADOHORAS_H
#define EMPLEADOHORAS_H

#include <iostream>
#include "DatosEmpleado.h"

class EmpleadoHoras : public Empleado {
    private:
        double salarioHora;
        double horasTrabajadas;
        double sueldoBruto;
        double sueldoNeto;
        double impuestos;
    protected:
        virtual std::ostream& serializar(std::ostream& out) const;

    public:
        EmpleadoHoras(std::string, std::string, int, double, double);
        std::string getNombre();
        std::string getCorreo();
        int getTipoEmpleado();
        double getSueldoBruto();
        double getSueldoNeto();
        double getImpuestos();
};

#endif