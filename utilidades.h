/**
 * @file utilidades.h
 * @author Cochini Felix H (felixhcochini@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _UTILIDADES_H
#define _UTILIDADES_H
#include "common_type_c8.h"
#include <stdio.h>

#define wrap(x) x

#define concat2nx(x,y) x ## y
#define concat2(x,y) concat2nx(x,y)

#define concat3nx(x,y,z) x ## y ## z
#define concat3(x,y,z) concat3nx(x,y,z)

#define acadenanx(y)  #y
#define acadena(y)  acadenanx(y)

/**
 * @brief printf de un valor en binario
 * 
 * @param valor 
 * @param cantbit 
 * @return int 
 */
int printfBin(ENTERO valor, ENTERO cantbit);

#endif
