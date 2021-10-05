
#ifndef UNIT_TEST

#include <iostream>
#include "ArbolPlanilla.h"
#include <fstream>
#include <string>

int main() {

    std::ifstream ifs("Personas.txt", std::ifstream::in);
    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo Personas.txt" << std::endl;
        return -1;
    }

    ArbolPlanilla *arbol = new ArbolPlanilla();   
    ifs >> *arbol;


    std::ofstream file("Planilla.txt", std::ofstream::out);
    file<<*arbol;
    file.close();

    //std::cout << *arbol;

    delete arbol;

    return 0;
}

#endif