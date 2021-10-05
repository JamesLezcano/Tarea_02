
#ifndef UNIT_TEST

#include <iostream>
#include "ArbolPlanilla.h"
#include <fstream>
#include <string>
#include "Nodo.h"

int main() {

    std::ifstream ifs("Personas.txt", std::ifstream::in);
    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo Personas.txt" << std::endl;
        return -1;
    }

    ArbolPlanilla *arbol = new ArbolPlanilla();   
    ifs >> *arbol;


    std::ofstream file("Planilla.csv", std::ofstream::out);
    file<<"Supervisor, Id_Empleado, Nombre_Empleado, Sueldo_Neto   "<<std::endl<<"                     ";
    file<<*arbol;

    
    file.close();
    


    delete arbol;
    return 0;
}

#endif