#include <map>
#include "ArbolPlanilla.h"
#include "Nodo.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "EmpleadoAsalariado.h"
#include "EmpleadoHoras.h"
#include "DatosEmpleado.h"
using namespace std;

ArbolPlanilla::ArbolPlanilla() {
    this->raiz = nullptr;
}
ArbolPlanilla::~ArbolPlanilla() {

    // Este destructor arranca el proceso de destrucción de los nodos;
    if (this->raiz != nullptr)
    {
        delete this->raiz;    }

}

void ArbolPlanilla::AgregarNodo(int id_Empleado, Empleado *datos_Empleado, int id_Supervisor)
{
    Nodo *nodo = new Nodo(id_Empleado, datos_Empleado, id_Supervisor);
   
    // Si idPadre = 0, es el nodo raíz
    if (id_Supervisor == 0)
    {
        this->raiz = nodo;   
    }
    else
    {
        // Buscar ese nodo padre
        Nodo *nodoPadre = this->elementos.at(id_Supervisor);
        nodoPadre->AgregarHijo(nodo);        
    }

    // Agregar nodo al índice
    this->elementos.insert(std::pair<int,Nodo *>(id_Empleado, nodo));
}

std::ostream& operator << (std::ostream &o, const ArbolPlanilla &arbol)
{

    Nodo* raiz = arbol.raiz;
    o << *(raiz);
    return o;
}

std::istream& operator >> (std::istream &i, ArbolPlanilla &arbol){
    ifstream ifs2("Nomina.txt", ifstream::in);//////////----------->>>>>Recordar poner error
    if (!ifs2.is_open())
    {
        std::cerr << "Error leyendo archivo Nomina.txt" << endl;
    }
    string linea2 {""};//liena de la nomina
    int idEmpleadoNomina;//id de nomina
    double salarioBruto=0;
///////////////////////////////lee txt horas trabajadas ////////////////////////////
 ifstream ifs3("HorasTrabajadas.txt", ifstream::in);//////////----------->>>>>Recordar poner error
    if (!ifs3.is_open())
    {
        std::cerr << "Error leyendo archivo Nomina.txt" << endl;
    }
    string linea3 {""};//liena de la nomina
    int idEmpleadoHorasTrabajadas;//id de nomina
    double salarioHora=0;
    double horasTrabajadas=0;

////////////////////////////////////Datos de Personas.txt ////////////////////////////
    string linea {""};//linea de las personas
    int idEmpleado {0};
    string nombre {0};
    string apellido{""};
    string nombreCompleto{""};//une el nombre completo
    string correo{""};
    int tipo{0};
    int idSupervisor {0};    
    
    while (getline(i, linea)) {
        idEmpleado = 0;
        nombre = "";
        apellido="";
        nombreCompleto="";
        correo="";
        tipo=0;
        idSupervisor = 0;

        istringstream stream(linea); 
        
        stream >> idEmpleado;
        stream >> nombre;
        stream >>apellido;
        stream>>correo;
        stream>>tipo;
        stream>> idSupervisor;
        nombreCompleto = nombre +" "+ apellido;
        
        if(getline(ifs2,linea2)){
            istringstream stream2(linea2); 
            stream2>> idEmpleadoNomina >> salarioBruto;
            Empleado *EmpleadoAsalariadoNuevo = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
            arbol.AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo, idSupervisor);
        }
        else if(getline(ifs3,linea3)){
            istringstream stream3(linea3); 
            stream3>> idEmpleadoHorasTrabajadas>> horasTrabajadas>>salarioHora;
            Empleado *EmpleadoHorasNuevo = new EmpleadoHoras{nombreCompleto,correo,tipo,horasTrabajadas,salarioHora};
            arbol.AgregarNodo(idEmpleado, EmpleadoHorasNuevo, idSupervisor);
        }
        
    }
    


    return i;

}