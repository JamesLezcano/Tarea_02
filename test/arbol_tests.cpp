#include <gtest/gtest.h>
#include <string>
#include <sstream>

#include "../src/ArbolPlanilla.h"
#include "../src/EmpleadoAsalariado.h"
#include "../src/EmpleadoHoras.h"
#include "../src/DatosEmpleado.h"

namespace {
    TEST(ArbolTests, Test_ConstructorEmpleadoTipo1) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        int idEmpleado=1;
        int idSupervisor=0;
        std::string nombreCompleto="Denis Tyler";
        std::string correo="denis_tyler@biz.com";
        int tipo=1;
        double salarioBruto=4600.98;


        Empleado *EmpleadoAsalariadoNuevo = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo, idSupervisor);

        std::ostringstream streamSalida {};
        streamSalida <<*arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        EXPECT_EQ("1 ,       Denis Tyler ,                     ,       4278.91\n\nSueldo Bruto Total:        Sueldo Neto Total:         Total Impuestos: \n4600.980000             4278.911400             322.068600", actual);
    }

    TEST(ArbolTests, Test_ConstructorEmpleadoTipo2) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        int idEmpleado=1;
        int idSupervisor=0;
        std::string nombreCompleto="Ryan Webster";
        std::string correo="Ryan_Webster6612@hourpy.biz";
        int tipo=2;
        double horasTrabajadas=55;
        double salarioHora=42.26;
           
        Empleado *EmpleadoAsalariadoNuevo = new EmpleadoHoras{nombreCompleto,correo,tipo,horasTrabajadas,salarioHora};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo, idSupervisor);

        std::ostringstream streamSalida {};
        streamSalida <<*arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        EXPECT_EQ("1 ,       Ryan Webster ,                     ,       2324.3\n\nSueldo Bruto Total:        Sueldo Neto Total:         Total Impuestos: \n6925.280000             6603.211400             322.068600", actual);
    }    


    TEST(ArbolTests, Test_Agregar_Nodo_Empleado_Tipo1_Tipo2) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        ///////////////////////    EMPLEADO TIPO1    ////////////////////////////
        int idEmpleado=1;
        int idSupervisor=0;
        std::string nombreCompleto="Denis Tyler";
        std::string correo="denis_tyler@biz.com";
        int tipo=1;
        double salarioBruto=4600.98;
        Empleado *EmpleadoAsalariadoNuevo = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo, idSupervisor);   
        ///////////////////////    EMPLEADO TIPO2    ////////////////////////////  
        idEmpleado=2;
        idSupervisor=1;
        nombreCompleto="Ryan Webster";
        correo="Ryan_Webster6612@hourpy.biz";
        tipo=2;
        double horasTrabajadas=55;
        double salarioHora=42.26;
           
        Empleado *EmpleadoAsalariadoNuevo2 = new EmpleadoHoras{nombreCompleto,correo,tipo,horasTrabajadas,salarioHora};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo2, idSupervisor);
        ///////////////////////    SALIDA DE DATOS    //////////////////////////// 
        std::ostringstream streamSalida {};
        streamSalida <<*arbol;
        std::string actual = streamSalida.str();
        delete arbol;
        //////////////////////  DATOS ESPERADOS      ////////////////////////////7
        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1 ,       Denis Tyler ,                     ,       4278.91\n";
        streamSalidaEsperada << "2 ,       Ryan Webster ,       Denis Tyler ,       2324.3\n\n";
        streamSalidaEsperada << "Sueldo Bruto Total:        Sueldo Neto Total:         Total Impuestos: \n13850.560000             13206.422800             644.137200";
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTests, Test_Agregar_Nodos_UnNivel_Tipo1_Tipo2_Variados) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
         ///////////////////////    EMPLEADO TIPO1    ////////////////////////////
        int idEmpleado=1;
        int idSupervisor=0;
        std::string nombreCompleto="Denis Tyler";
        std::string correo="denis_tyler@biz.com";
        int tipo=1;
        double salarioBruto=4600.98;
        Empleado *EmpleadoAsalariadoNuevo = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo, idSupervisor);   
        ///////////////////////    EMPLEADO TIPO2    ////////////////////////////  
        idEmpleado=2;
        idSupervisor=1;
        nombreCompleto="Ryan Webster";
        correo="Ryan_Webster6612@hourpy.biz";
        tipo=2;
        double horasTrabajadas=55;
        double salarioHora=42.26;   
        Empleado *EmpleadoAsalariadoNuevo2 = new EmpleadoHoras{nombreCompleto,correo,tipo,horasTrabajadas,salarioHora};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo2, idSupervisor);
        ///////////////////////    EMPLEADO TIPO2    ////////////////////////////
        idEmpleado=3;
        idSupervisor=1;
        nombreCompleto="Clarissa Parker";
        correo="clarissa_parker@biz.com";
        tipo=1;
        salarioBruto=3097.50;
        Empleado *EmpleadoAsalariadoNuevo3 = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo3, idSupervisor);   


        ///////////////////////    SALIDA DE DATOS    //////////////////////////// 
        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;
        //////////////////////  dATOS ESPERADOS      ////////////////////////////7
        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1 ,       Denis Tyler ,                     ,       4278.91\n";
        streamSalidaEsperada << "2 ,       Ryan Webster ,       Denis Tyler ,       2324.3\n";
        streamSalidaEsperada << "3 ,       Clarissa Parker ,       Denis Tyler ,       2880.68\n\n";
        streamSalidaEsperada << "Sueldo Bruto Total:        Sueldo Neto Total:         Total Impuestos: \n23873.340000             22690.309200             1183.030800";
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }
   
    TEST(ArbolTests, Test_Agregar_Nodos_DosNiveles_Tipo1_Tipo2_Variados) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        ///////////////////////    EMPLEADO TIPO1    ////////////////////////////
        int idEmpleado=1;
        int idSupervisor=0;
        std::string nombreCompleto="Denis Tyler";
        std::string correo="denis_tyler@biz.com";
        int tipo=1;
        double salarioBruto=4600.98;
        Empleado *EmpleadoAsalariadoNuevo = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo, idSupervisor);   
        ///////////////////////    EMPLEADO TIPO2    ////////////////////////////  
        idEmpleado=2;
        idSupervisor=1;
        nombreCompleto="Ryan Webster";
        correo="Ryan_Webster6612@hourpy.biz";
        tipo=2;
        double horasTrabajadas=55;
        double salarioHora=42.26;   
        Empleado *EmpleadoAsalariadoNuevo2 = new EmpleadoHoras{nombreCompleto,correo,tipo,horasTrabajadas,salarioHora};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo2, idSupervisor);
        ///////////////////////    EMPLEADO TIPO2    ////////////////////////////
        idEmpleado=3;
        idSupervisor=1;
        nombreCompleto="Clarissa Parker";
        correo="clarissa_parker@biz.com";
        tipo=1;
        salarioBruto=3097.50;
        Empleado *EmpleadoAsalariadoNuevo3 = new EmpleadoAsalariado{nombreCompleto,correo,tipo,salarioBruto};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo3, idSupervisor);   
        ///////////////////////    EMPLEADO TIPO2    ////////////////////////////  
        idEmpleado=4;
        idSupervisor=3;
        nombreCompleto="Emmanuelle Tennant";
        correo="Emmanuelle_Tennant8391@deavo.com";
        tipo=2;
        horasTrabajadas=43;
        salarioHora=34.84;   
        Empleado *EmpleadoAsalariadoNuevo4 = new EmpleadoHoras{nombreCompleto,correo,tipo,horasTrabajadas,salarioHora};
        arbol->AgregarNodo(idEmpleado, EmpleadoAsalariadoNuevo4, idSupervisor);
        ///////////////////////    SALIDA DE DATOS    //////////////////////////// 
        

        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1 ,       Denis Tyler ,                     ,       4278.91\n";
        streamSalidaEsperada << "2 ,       Ryan Webster ,       Denis Tyler ,       2324.3\n";
        streamSalidaEsperada << "3 ,       Clarissa Parker ,       Denis Tyler ,       2880.68\n";
        streamSalidaEsperada << "4 ,       Emmanuelle Tennant ,       Clarissa Parker ,       1498.12\n\n";
        streamSalidaEsperada << "Sueldo Bruto Total:        Sueldo Neto Total:         Total Impuestos: \n35394.240000             33672.315600             1721.924400";
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }
}