/**
 * @file deco_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Decodificadores
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _DECO_C8_H
#define _DECO_C8_H
#include "config_lib_aed_c8.h"
#include "utilidades.h"
#include "common_type_c8.h"
#include "pinio_c8.h"
#include <stdio.h>
#ifdef test_c8
#include "debug_c8.h"
#include "recursos_win.h"
#endif

/**
 * @brief Decodificador binario de 2 a 4
 * 
 */
#ifndef test_c8
class Deco2a4{
#else
class Deco2a4 : public Info_c8,public Terminal_c8{
#endif
    public :
    /**
     * @brief salida puerto: {o3,o2,o1,o0}
     * 
     */
        union {
            PUERTO puerto;
            struct {
                CAMPO o0:1;
                CAMPO o1:1;
                CAMPO o2:1;
                CAMPO o3:1;
            };
        } salida;
        /**
         * @brief Constructor
         * 
         */
        Deco2a4();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a1 Entrada 
         * @param a0 Entrada 
         */
        void conectar(unsigned int a1,unsigned int a0);
#ifdef test_c8
        /**
         * @brief tabla de decodificador de 2 a 4
         * 
         */
        void tablaDeVerdad();
        /**
         * @brief Muestra salida del decodificador de 2 a 4
         * 
         */
        void salidaPorPantalla();
        /**
         * @brief tabla de decodificador de 2 a 4
         * 
         */
        void tablaDeVerdad(HANDLE consola, WORD color);
        /**
         * @brief Muestra salida del decodificador de 2 a 4
         * 
         */
        void salidaPorPantalla(HANDLE consola, WORD color);
#endif
};

/**
 * @brief Decodificador binario de 3 a 8
 * 
 */
#ifndef test_c8
class Deco3a8{
#else
class Deco3a8 : public Info_c8, public Terminal_c8{
#endif
    public :
    /**
     * @brief salida puerto: {o7,o6,o5,o4,o3,o2,o1,o0}
     * 
     */
        union {
            PUERTO puerto;
            struct {
                CAMPO o0:1;
                CAMPO o1:1;
                CAMPO o2:1;
                CAMPO o3:1;
                CAMPO o4:1;
                CAMPO o5:1;
                CAMPO o6:1;
                CAMPO o7:1;
            };
        } salida;
        /**
         * @brief Constructor
         * 
         */
        Deco3a8();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param a2 Entrada 
         * @param a1 Entrada 
         * @param a0 Entrada 
         */
        void conectar(unsigned int a2,unsigned int a1,unsigned int a0);
#ifdef test_c8
        /**
         * @brief tabla de decodificador de 3 a 8
         * 
         */
        void tablaDeVerdad();
        /**
         * @brief Muestra salida del decodificador de 3 a 8
         * 
         */
        void salidaPorPantalla();
        /**
         * @brief tabla de decodificador de 3 a 8
         * 
         */
        void tablaDeVerdad(HANDLE consola, WORD color);
        /**
         * @brief Muestra salida del decodificador de 3 a 8
         * 
         */
        void salidaPorPantalla(HANDLE consola, WORD color);
#endif
};

/**
 * @brief Decodificador de BCD a 7 Segmentos
 * 
 */
#ifndef test_c8
class Deco7seg{
#else
class Deco7seg : public Info_c8, public Terminal_c8{
#endif
    public :
    /**
     * @brief salida port: {a,b,c,d,e,f,g}
     * 
     */
        union {
            SALIDA port;
            struct {
                CAMPO g:1;
                CAMPO f:1;
                CAMPO e:1;
                CAMPO d:1;
                CAMPO c:1;
                CAMPO b:1;
                CAMPO a:1;
            };
        }salida;
        /**
         * @brief Identificador de los pines fisicos de salida
         * 
         */
        SALIDA pinSalida[7];
        /**
         * @brief Constructor
         * 
         */
        Deco7seg();
        /**
         * @brief Constructor
         * 
         * @param pa identificador del pin a 
         * @param pb identificador del pin b 
         * @param pc identificador del pin c 
         * @param pd identificador del pin d 
         * @param pe identificador del pin e 
         * @param pf identificador del pin f 
         * @param pg identificador del pin g 
         */
        Deco7seg(SALIDA pa, SALIDA pb, SALIDA pc, SALIDA pd, SALIDA pe, SALIDA pf, SALIDA pg);
        /**
         * @brief configuracion inicial
         * 
         */
        void configurar();
        /**
         * @brief Conecta las entradas al bloque
         * 
         * @param A Entrada
         * @param B Entrada 
         * @param C Entrada 
         * @param D Entrada 
         */
        void conectar(ENTRADA A,ENTRADA B,ENTRADA C,ENTRADA D);

        void conectar(BUS ABCD);
        /**
         * @brief 
         * 
         * @param entrada de 4 bit 
         */
        void conectar(BIT4 entrada);
        /**
         * @brief Activa las salidas de 7 segmentos instanciadas
         * 
         */
        void mostrar();
        /**
         * @brief Activa las salidas de 7 segmentos indicadas
         * 
         * @param pa Salida
         * @param pb Salida 
         * @param pc Salida 
         * @param pd Salida 
         * @param pe Salida 
         * @param pf Salida 
         * @param pg Salida 
         */
        void mostrar(SALIDA pa, SALIDA pb, SALIDA pc, SALIDA pd, SALIDA pe, SALIDA pf, SALIDA pg);
#ifdef test_c8
        /**
         * @brief tabla de verdad del Deco BCD a 7 segmentos
         * 
         */
        void tablaDeVerdad();
        /**
         * @brief Muestra salida de 7 segmentos
         * 
         */
        void salidaPorPantalla();
        /**
         * @brief tabla de verdad del Deco BCD a 7 segmentos
         * 
         */
        void tablaDeVerdad(HANDLE consola, WORD color);
        /**
         * @brief Muestra salida de 7 segmentos
         * 
         */
        void salidaPorPantalla(HANDLE consola, WORD color);
#endif
};

#endif