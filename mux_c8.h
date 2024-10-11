/**
 * @file mux_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Multiplexores
 * @version 0.1
 * @date 2024-07-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _MUX_C8_H
#define _MUX_C8_H
#include "common_type_c8.h"
#include "pinio_c8.h"
#include <stdio.h>
#ifdef test_c8
#include "debug_c8.h"
#endif
/**
 * @brief Multiplexor cuadruple de 2 vias a 1
 * 
 */
#ifndef test_c8
class MuxQ2v1 {
#else
class MuxQ2v1: public Info_c8{
#endif
    public:
    union{
        port(bus)
        struct{
            dbit(o0)
            dbit(o1)
            dbit(o2)
            dbit(o3)
        };
    }salida;
        /**
         * @brief Constructor de mux cuadruple de
         * 2 vias a 1
         */
        MuxQ2v1();
        /**
         * @brief Conecta las vias y la seleccion
         * 
         * @param I1 - Via 1
         * @param I0 - Via 0
         * @param sel - Seleccion
         */
        void conectar(BUS I1, BUS I0, ENTRADA sel);
#ifdef test_c8
    /**
     * @brief 
     * 
     */
    void tablaDeVerdad();
    /**
     * @brief 
     * 
     */
    void salidaPorPantalla();
#endif
};

#endif