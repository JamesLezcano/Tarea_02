#include <gtest/gtest.h>
#include <string>
#include <sstream>

#include "../src/ArbolPlanilla.h"

namespace {
    TEST(ArbolTests, Test_Constructor) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        arbol->AgregarNodo(1, 2, 0);

        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        EXPECT_EQ("Nodo: 1. Valor: 2\n", actual);
    }

    TEST(ArbolTests, Test_Agregar_Nodo) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        arbol->AgregarNodo(1, 2, 0);
        arbol->AgregarNodo(2, 7, 1);        

        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "Nodo: 1. Valor: 2" << std::endl;
        streamSalidaEsperada << "Nodo: 2. Valor: 7" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTests, Test_Agregar_Nodos_UnNivel) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        arbol->AgregarNodo(1, 2, 0);
        arbol->AgregarNodo(2, 7, 1);        
        arbol->AgregarNodo(450, 10, 1);

        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "Nodo: 1. Valor: 2" << std::endl;
        streamSalidaEsperada << "Nodo: 2. Valor: 7" << std::endl;
        streamSalidaEsperada << "Nodo: 450. Valor: 10" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }
    
    TEST(ArbolTests, Test_Agregar_Nodos_DosNiveles) {
        ArbolPlanilla *arbol = new ArbolPlanilla();
        arbol->AgregarNodo(1, 2, 0);
        arbol->AgregarNodo(2, 7, 1);
        arbol->AgregarNodo(450, 10, 1);
        arbol->AgregarNodo(301, 70, 2);
        arbol->AgregarNodo(760, 17, 450);

        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "Nodo: 1. Valor: 2" << std::endl;
        streamSalidaEsperada << "Nodo: 2. Valor: 7" << std::endl;
        streamSalidaEsperada << "Nodo: 301. Valor: 70" << std::endl;
        streamSalidaEsperada << "Nodo: 450. Valor: 10" << std::endl;
        streamSalidaEsperada << "Nodo: 760. Valor: 17" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTests, Test_Lectura_Stream) {
            
        std::ostringstream streamGeneracionEjemplo {};
        streamGeneracionEjemplo << "1 2" << std::endl;
        streamGeneracionEjemplo << "2 7 1" << std::endl;
        std::string entradaEjemplo = streamGeneracionEjemplo.str();

        std::istringstream streamEntradaEjemplo {entradaEjemplo};
        ArbolPlanilla *arbol = new ArbolPlanilla();
        streamEntradaEjemplo >> *arbol;

        std::ostringstream streamSalida {};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "Nodo: 1. Valor: 2" << std::endl;
        streamSalidaEsperada << "Nodo: 2. Valor: 7" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

}