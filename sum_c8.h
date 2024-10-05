/**
 * @file sum_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Sumadores
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _SUM_C8_H
#define _SUM_C8_H
#include "common_type_c8.h"
#include "pinio_c8.h"
#include "debug_c8.h"
#include <stdio.h>

/**
 * @brief Medio sumador de 1 bit
 * 
 */
#ifndef test_c8
class MedioSum1bit{
#else
class MedioSum1bit: public Info_c8{
#endif
    public :
    /**
     * @brief salida total:{co,r0}
     * 
     */
        union {
            PUERTO total;
            struct {
                CAMPO r0:1;
                CAMPO co:1;
            };
        }salida;
        /**
         * @brief Constructor
         * 
         */
        MedioSum1bit();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a Entrada 
         * @param b Entrada 
         */
        void conectar(ENTRADA a,ENTRADA b);
#ifdef test_c8
        /**
         * @brief tabla de verdad de un 
         * Medio sumador de 1 bit
         * 
         */
        void tablaDeVerdad();
        /**
         * @brief muestra el ultimo resultado
         * por pantalla
         * 
         */
        void salidaPorPantalla();
#endif
};

/**
 * @brief Sumador Completo de 1 bit
 * 
 */
#ifndef test_c8
class Sum1bit{
#else
class Sum1bit: public Info_c8{
#endif
    public :
    /**
     * @brief salida total:{co,r0}
     * 
     */
        union {
            PUERTO total;
            struct {
                CAMPO r0:1;
                CAMPO co:1;
            };
        }salida;
        Sum1bit();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a Entrada
         * @param b Entrada
         * @param ci Entrada
         */
        void conectar(ENTRADA a,ENTRADA b,ENTRADA ci);
#ifdef test_c8
        /**
         * @brief tabla de verdad de un 
         * Sumador de 1 bit
         */
        void tablaDeVerdad();
        /**
         * @brief muestra el ultimo resultado
         * por pantalla
         */
        void salidaPorPantalla();
#endif
};

/**
 * @brief Sumador Completo de 4 bit
 * 
 */
#ifndef test_c8
class Sum4bit{
#else
class Sum4bit: public Info_c8{
#endif
    public :
    /**
     * @brief salida total:{co,r3r2r1r0}
     * 
     */
        union {
            PUERTO total;
            struct {
                CAMPO resultado:4;
                CAMPO carry:1;
            };
            struct {
                CAMPO r0:1;
                CAMPO r1:1;
                CAMPO r2:1;
                CAMPO r3:1;
                CAMPO co:1;
            };
        }salida;

        Sum4bit();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a Entrada
         * @param b Entrada
         */
        void conectar(ENTRADA a,ENTRADA b);
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a Entrada (4 bit)
         * @param b Entrada (4 bit)
         * @param ci Entrada 
         */
        void conectar(ENTRADA a,ENTRADA b,ENTRADA ci);
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a3 Entrada 
         * @param a2 Entrada 
         * @param a1 Entrada 
         * @param a0 Entrada 
         * @param b3 Entrada 
         * @param b2 Entrada 
         * @param b1 Entrada 
         * @param b0 Entrada 
         */
        void conectar(ENTRADA a3,ENTRADA a2,ENTRADA a1,ENTRADA a0,ENTRADA b3,ENTRADA b2,ENTRADA b1,ENTRADA b0);
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a3 Entrada
         * @param a2 Entrada
         * @param a1 Entrada
         * @param a0 Entrada
         * @param b3 Entrada
         * @param b2 Entrada
         * @param b1 Entrada
         * @param b0 Entrada
         * @param ci Entrada
         */
        void conectar(ENTRADA a3,ENTRADA a2,ENTRADA a1,ENTRADA a0,ENTRADA b3,ENTRADA b2,ENTRADA b1,ENTRADA b0,ENTRADA ci);
#ifdef test_c8
        /**
         * @brief tabla de verdad de un 
         * Sumador de 1 bit
         */
        void tablaDeVerdad();
        /**
         * @brief muestra el ultimo resultado
         * por pantalla
         */
        void salidaPorPantalla();
#endif
};

/**
 * @brief Sumador Completo de 8 bit
 * 
 * @code {.c}
 * unsigned int varentrada = 8
 * Sum8bit misumador = Sum8bit();               // Instanciacion / Creacion del componente
 * misumador.conectar(5,varentrada,0);          // para hacer la suma de 5 + 8 + 0 (carry)
 * varresultado = misumador.salida.resultado;   // obtengo de la salida solo el resultado
 * varcarry = misumador.salida.co;              // obtengo solo el carry de salida
 * vartodo = misumador.salida.total;            // obtengo todo junto {carry,resultado}
 * @endcode
 * 
 * @note La **Instanciacion** es equivalente a declarar una variable, 
 * si no se hace, no se puede usar el componente.
 * 
 */
class Sum8bit{
    public:
        union{
            port(total)
            struct{
                dport(resultado,8)
                dbit(carry)
            };
            struct{
                dbit(r0)
                dbit(r1)
                dbit(r2)
                dbit(r3)
                dbit(r4)
                dbit(r5)
                dbit(r6)
                dbit(r7)
                dbit(co)
            };
        }salida;
        /**
         * @brief Constructor Sumador 8bit
         * 
         */
        Sum8bit();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a ENTRADA
         * @param b ENTRADA
         * @param ci ENTRADA
         */
        void conectar(ENTRADA a, ENTRADA b, ENTRADA ci);
};

#endif