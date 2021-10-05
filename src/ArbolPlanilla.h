#ifndef ARBOLPLANILLA_H
#define ARBOLPLANILLA_H

#include "nodo.h"
#include <map>
#include <iostream>
#include "DatosEmpleado.h"

class ArbolPlanilla {

    Nodo *raiz;
    std::map<int, Nodo *> elementos;

    double sueldoBrutoTotal=0;
    double sueldoNetoTotal=0;
    double impuestosTotales=0;

    public:
    ArbolPlanilla();
    ~ArbolPlanilla();
    void AgregarNodo(int id_Empleado, Empleado *datos_Empleado, int id_Supervisor);

    friend std::ostream& operator << (std::ostream &o, const ArbolPlanilla &arbol);
    friend std::istream& operator >> (std::istream &i, ArbolPlanilla &arbol);
};


#endif