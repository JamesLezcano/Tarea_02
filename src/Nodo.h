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
    
    public:
    Nodo(int id_Empleado, Empleado *Datos_Empleado,int id_Supervisor);
    ~Nodo();

    void AgregarHijo(Nodo *hijo);

    friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif