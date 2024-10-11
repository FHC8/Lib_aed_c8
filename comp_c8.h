/**
 * @file comp_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Comparadores
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _COMP_C8_H
#define _COMP_C8_H
#include "common_type_c8.h"
#include "pinio_c8.h"
#include <stdio.h>
#ifdef test_c8
#include "debug_c8.h"
#endif

/**
 * @brief Comparador de 1 bit
 * 
 */
#ifndef test_c8
class Comp1bit{
#else
class Comp1bit: public Info_c8{
#endif
    public :
    /**
     * @brief salida resultado:{A_Menor_B,A_Igual_B,A_Mayor_B}
     * 
     */
    union{
        PUERTO resultado:3;
        struct {
                CAMPO A_Mayor_B:1;
                CAMPO A_Igual_B:1;
                CAMPO A_Menor_B:1;
        };
        }salida;
        /**
         * @brief Constructor
         * 
         */
        Comp1bit();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param A Entrada
         * @param B Entrada
         */
        void conectar(ENTRADA A,ENTRADA B);
#ifdef test_c8
        /**
         * @brief tabla del Comparador de 1 bit
         * 
         */
        void tablaDeVerdad();
        /**
         * @brief Muestra salida del Comparador de 1 bit
         * 
         */
        void salidaPorPantalla();
#endif
};

/**
 * @brief Comparador de 4 bit
 * 
 */
class Comp4bit: public Comp1bit{
    public :
    /**
     * @brief Constructor
     * 
     */
        Comp4bit();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param A Entrada
         * @param B Entrada
         */
        void conectar(ENTRADA A,ENTRADA B);
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param A Entrada
         * @param B Entrada
         * @param A_Mayor_B Entrada de expansion 
         * @param A_Igual_B Entrada de expansion 
         * @param A_Menor_B Entrada de expansion 
         */
        void conectar(ENTRADA A,ENTRADA B, ENTRADA A_Mayor_B, ENTRADA A_Igual_B, ENTRADA A_Menor_B);
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param A_3 Entrada 
         * @param A_2 Entrada 
         * @param A_1 Entrada 
         * @param A_0 Entrada 
         * @param B_3 Entrada 
         * @param B_2 Entrada 
         * @param B_1 Entrada 
         * @param B_0 Entrada 
         */
        void conectar(ENTRADA A_3,ENTRADA A_2,ENTRADA A_1,ENTRADA A_0,ENTRADA B_3,ENTRADA B_2,ENTRADA B_1,ENTRADA B_0);
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param A_3 Entrada  
         * @param A_2 Entrada 
         * @param A_1 Entrada 
         * @param A_0 Entrada 
         * @param B_3 Entrada 
         * @param B_2 Entrada 
         * @param B_1 Entrada 
         * @param B_0 Entrada 
         * @param A_Mayor_B Entrada de expansion 
         * @param A_Igual_B Entrada de expansion 
         * @param A_Menor_B Entrada de expansion  
         */
        void conectar(ENTRADA A_3,ENTRADA A_2,ENTRADA A_1,ENTRADA A_0,ENTRADA B_3,ENTRADA B_2,ENTRADA B_1,ENTRADA B_0,ENTRADA A_Mayor_B,ENTRADA A_Igual_B,ENTRADA A_Menor_B);
#ifdef test_c8
        /**
         * @brief tabla del Comparador de 4 bit
         * 
         */
        void tablaDeVerdad();
        /**
         * @brief Muestra salida del Comparador de 4 bit
         * 
         */
        void salidaPorPantalla();
#endif
};

#endif