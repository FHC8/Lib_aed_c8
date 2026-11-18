#ifndef _CONT_C8_H_
#define _CONT_C8_H_

#include "config_lib_aed_c8.h"
#include "common_type_c8.h"
#include "pinio_c8.h"

#ifdef test_c8
#include <stdio.h>
#include "debug_c8.h"
#endif

#include "patrones_c8_min.h"
#include "binary_event_c8.h"

#define MAX_SALIDAS 4
#define conectarSalidaCon(Qi,observer) conectar(Qi,&observer)

#ifndef test_c8
class Cont4bit: public IObserver {
#else
class Cont4bit: public IObserver{ /* public Info_c8, */
#endif
    private :
       BinaryEvent qt[MAX_SALIDAS];
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

        void serNotificadoPor(IObservable *obserbable) override;

        void notificar();

        BinaryEvent& q(unsigned int salida);

        void conectar(unsigned int Qi, IObserver* observer);

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


#ifndef test_c8
class Cont16bit: public IObserver {
#else
class Cont4bit: public IObserver{ /* public Info_c8, */
#endif
    private :
       BinaryEvent qt[MAX_SALIDAS];
    public :
    /**
     * @brief salida cuenta:{co,q3q2q1q0}
     * 
     */
        union {
            PUERTO cuenta;
            struct {
                CAMPO q:16;
                CAMPO c:1;
            };
            struct {
                CAMPO q0:1;
                CAMPO q1:1;
                CAMPO q2:1;
                CAMPO q3:1;
                CAMPO q4:1;
                CAMPO q5:1;
                CAMPO q6:1;
                CAMPO q7:1;
                CAMPO q8:1;
                CAMPO q9:1;
                CAMPO q10:1;
                CAMPO q11:1;
                CAMPO q12:1;
                CAMPO q13:1;
                CAMPO q14:1;
                CAMPO q15:1;
                CAMPO co:1;
            };
        }salida;

        Cont16bit();

        void serNotificadoPor(IObservable *obserbable) override;

        void notificar();

        BinaryEvent& q(unsigned int salida);

        void conectar(unsigned int Qi, IObserver* observer);

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

