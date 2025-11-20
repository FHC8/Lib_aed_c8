/**
 * @file count_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-11-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _COUNT_C8_H_
#define _COUNT_C8_H_

#include "config_lib_aed_c8.h"
#include "common_type_c8.h"
#include "pinio_c8.h"
#include <stdio.h>
#ifdef test_c8
#include "debug_c8.h"
#endif

// // extern unsigned int contador;
// // extern MSG msg;
// // extern UINT_PTR timerId;

// /**
//  * @brief Sumador Completo de 4 bit
//  * 
//  */
// #ifndef test_c8
// class Cont4bit {
// #else
// class Cont4bit: public Info_c8{
// #endif
//     private :
//         ESTADO deteccion;
//     public :
//     /**
//      * @brief salida cuenta:{co,q3q2q1q0}
//      * 
//      */
//         union {
//             PUERTO cuenta;
//             struct {
//                 CAMPO q:4;
//                 CAMPO c:1;
//             };
//             struct {
//                 CAMPO q0:1;
//                 CAMPO q1:1;
//                 CAMPO q2:1;
//                 CAMPO q3:1;
//                 CAMPO co:1;
//             };
//         }salida;

//         Cont4bit();
        
//         void conectar(ENTRADA clk,ENTRADA modo);
// #ifdef test_c8
//         /**
//          * @brief tabla de verdad de un 
//          * Sumador de 1 bit
//          */
//         void tablaDeVerdad();
//         /**
//          * @brief muestra el ultimo resultado
//          * por pantalla, formato por defecto
//          */
//         void salidaPorPantalla();
        
//         /**
//          * @brief Muestra por pantalla un Mensaje que deberian
//          * ser valores de entrada + separador + 
//          * salida por defecto.
//          * 
//          * @param val_ent 
//          * @param separador 
//          */
//         void salidaPorPantalla(char * val_ent,char * separador);

//         /**
//          * @brief Muestra por pantalla un Mensaje + separador +
//          * Columnas de salida por defecto
//          * 
//          * @param msj_ent 
//          * @param separador 
//          */
//         void mostrarColumnas(char * msj_ent,char * separador);
//         void CALLBACK tickProc(HWND, UINT, UINT_PTR, DWORD);
// #endif
// };

// #ifdef test_c8
// class Clock {
//     public :
//     virtual bool recibir(ENTRADA clk) const = 0;
//     // virtual ~Clock(){}
// };

// class Directo : public Clock {
//     public : 
//     enum EstadoFlanco { ESPERA_FLANCO, LLEGO_FLANCO};
//     Directo(){ actualizar=ESPERA_FLANCO; }
//     bool recibir(ENTRADA clk) {
//         bool rta=false;
//         switch (actualizar){
//             case ESPERA_FLANCO:
//                 if(clk){
//                     actualizar = LLEGO_FLANCO;
//                     rta=true;
//                 }
//                 break;
//             case LLEGO_FLANCO:
//                 if(!clk){
//                     actualizar = ESPERA_FLANCO;
//                 }
//                 break;        
//             default:
//                 break;
//         }
//         return rta;
//     }
//     private :
//     EstadoFlanco actualizar;
// };
// #endif

#endif
