#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <vector>
#include "DatosEmpleado.h"

class Nodo {

    int id_Empleado;
    Empleado *datos_Empleado;
    int id_Supervisor;
    std::vector<Nodo *> hijos;
    double SalarioBrutoTotal=0;
    
    public:
    Nodo(int id_Empleado, Empleado *Datos_Empleado,int id_Supervisor);
    ~Nodo();
    double sumaMonto(double );
    void AgregarHijo(Nodo *hijo);

    friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif