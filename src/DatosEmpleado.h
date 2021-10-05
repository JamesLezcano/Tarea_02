#ifndef DATOSEMPLEADO_H
#define DATOSEMPLEADO_H
#include<iostream>
#include <string>

class Empleado {
    
    protected:
    std::string nombreCompleto;
    std::string correo;
    int tipoEmpleado;
    double sueldoBruto;
    double sueldoNeto;
    double impuestos;
    
    virtual std::ostream& serializar(std::ostream& out) const;

    

    public:
    Empleado(){};
    ~Empleado(){};

    friend std::ostream& operator << (std::ostream &o, const Empleado &empleado);
};

#endif