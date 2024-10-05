/**
 * @file mux_c8.cpp
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Metodos
 * @version 0.1
 * @date 2024-07-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "mux_c8.h"

MuxQ2v1::MuxQ2v1()
{
    salida.bus=0;
}

void MuxQ2v1::conectar(BUS I1, BUS I0, ENTRADA sel)
{   
    salida.bus=(sel)?(I1):(I0);
}

void MuxQ2v1::tablaDeVerdad()
{
    printf("\n\n...falta terminar...\n\n");
}

void MuxQ2v1::salidaPorPantalla()
{
    printf("-> o3 o2 o1 o0 : %d %d %d %d\n",
    salida.o3,salida.o2,salida.o1,salida.o0);
}
