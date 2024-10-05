/**
 * @file debug_c8.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _DEBUG_C8_H
#define _DEBUG_C8_H
#include <windows.h>

/**
 * @brief Informativa
 * 
 */
class Info_c8{
    public:
    /**
     * @brief Muestra la tabla de verdad por 
     * pantalla de comandos, solo para debug.
     */
    virtual void tablaDeVerdad()=0;
    /**
     * @brief Muestra por terminal la salida
     * 
     */
    virtual void salidaPorPantalla()=0;
};

/**
 * @brief Informativa
 * 
 */
class Terminal_c8{
    public:
    /**
     * @brief Muestra la tabla de verdad por 
     * pantalla de comandos, con color, solo para windows.
     */
    virtual void tablaDeVerdad(HANDLE consola, WORD color)=0;
    /**
     * @brief Muestra por terminal la salida
     * , con color, solo para windows
     */
    virtual void salidaPorPantalla(HANDLE consola, WORD color)=0;
};

#endif