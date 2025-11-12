
#ifndef _COUNT_C8_H_
#define _COUNT_C8_H_

#include "config_lib_aed_c8.h"
#include "common_type_c8.h"
#include "pinio_c8.h"
#include <stdio.h>
#ifdef test_c8
#include "debug_c8.h"
#endif
#include "patrones_c8.h"

/* codigo */

#ifndef test_c8
class Cont4bit {
#else
class Cont4bit: public Info_c8, public IObserver{
#endif
    public :
    /**
     * @brief salida cuenta:{co,q3q2q1q0}
     * 
     */
        union {
            PUERTO cuenta;
            struct {
                CAMPO q:4;
                CAMPO c:1;
            };
            struct {
                CAMPO q0:1;
                CAMPO q1:1;
                CAMPO q2:1;
                CAMPO q3:1;
                CAMPO co:1;
            };
        }salida;

        Cont4bit();
        
        void conectar(ENTRADA clk,ENTRADA modo);

        
#ifdef test_c8
        /**
         * @brief tabla de verdad de un 
         * Sumador de 1 bit
         */
        void tablaDeVerdad();
        /**
         * @brief muestra el ultimo resultado
         * por pantalla, formato por defecto
         */
        void salidaPorPantalla();
        
        /**
         * @brief Muestra por pantalla un Mensaje que deberian
         * ser valores de entrada + separador + 
         * salida por defecto.
         * 
         * @param val_ent 
         * @param separador 
         */
        void salidaPorPantalla(char * val_ent,char * separador);

        /**
         * @brief Muestra por pantalla un Mensaje + separador +
         * Columnas de salida por defecto
         * 
         * @param msj_ent 
         * @param separador 
         */
        void mostrarColumnas(char * msj_ent,char * separador);
#endif
};

#endif

