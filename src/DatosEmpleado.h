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
    virtual std::string getNombre()=0;
    virtual std::string getCorreo()=0;
    virtual int getTipoEmpleado()=0;
    virtual double getSueldoBruto()=0;
    virtual double getSueldoNeto()=0;
    virtual double getImpuestos()=0;
    friend std::ostream& operator << (std::ostream &o, const Empleado &empleado);
};

#endif