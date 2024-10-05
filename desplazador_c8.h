/**
 * @file desplazador_c8.h
 * @author Cochini Felix H (felixhcochini@gmail.com)
 * @brief Desplazador
 * @version 0.1
 * @date 2024-07-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _DESPLAZADOR_C8_H
#define _DESPLAZADOR_C8_H
#include "common_type_c8.h"
#include <stdio.h>

/**
 * @brief Enumeracion para indicar 
 * la direccion de desplazamiento
 * 
 */
typedef enum {IZQUIERDA,DERECHA} DIRECCION;

/**
 * @brief Desplazador de n bit
 * 
 * @code {.c}
 * unsigned int vardatos = 0b11000000
 * Desp desplazador1 = Desp();                  // Instanciacion / Creacion del componente
 * desplazador1.conectar(DERECHA,5,vardatos);   // desplaza a la derecha, 5 lugares, el contenido de vardatos
 * resultadofinal = desplazador1.salida.valor;  // resultadofinal <- 00000110
 * @endcode
 * 
 * @note La **Instanciacion** es equivalente a declarar una variable, 
 * si no se hace, no se puede usar el componente.
 * 
 */
class Desp{
    public:
    BIT32 salida;
    /**
     * @brief Constructor
     * 
     */
    Desp();
    /**
     * @brief Conecta las entradas al bloque
     * 
     * @param dir direccion
     * @param n bits a desplazar
     * @param datos bus de entrada
     */
    void conectar(DIRECCION dir, ENTRADA n, ENTRADA datos);
    /**
     * @brief Muestra por pantalla 32 bit
     * 
     */
    void salidaPorPantalla();
};

#endif