/**
 * @file sum_c8.cpp
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Metodos
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "sum_c8.h"

MedioSum1bit::MedioSum1bit()
{
    salida.total=0;
}
void MedioSum1bit::conectar(ENTRADA a,ENTRADA b)
{
    salida.total = (0b11&(a+b));
}

#ifdef test_c8
void MedioSum1bit::tablaDeVerdad()
{
    VAR4 in;
    printf("\tTabla de Verdad - MEDIO SUMADOR 1BIT\n\n");
    printf("\tA  B   co r0\n");
    for(in.valor=0;in.valor<4;in.valor++){
        conectar(in.b1,in.b0);
        if(in.valor%4==0){printf("\t----   -----\n");}
        printf("%d\t%d  %d   %d  %d\n",
        in.valor,in.b1,in.b0,
        salida.co,salida.r0);
    }
    printf("\n");
}
void MedioSum1bit::salidaPorPantalla()
{
    printf("\n-> co r0\n    %d  %d\n",
    salida.co,salida.r0);
}
#endif

Sum1bit::Sum1bit()
{
    salida.total=0;
}
void Sum1bit::conectar(ENTRADA a,ENTRADA b,ENTRADA ci)
{
    salida.total = (0b11&(a+b+ci));
}

#ifdef test_c8
void Sum1bit::tablaDeVerdad()
{
    VAR4 in;
    printf("\tTabla de Verdad - SUMADOR COMPLETO 1BIT\n\n");
    printf("\tci A  B   co r0\n");
    for(in.valor=0;in.valor<8;in.valor++){
        conectar(in.b1,in.b0,in.b2);
        if(in.valor%4==0){printf("\t-------   -----\n");}
        printf("%d\t%d  %d  %d   %d  %d\n",
        in.valor,in.b2,in.b1,in.b0,
        salida.co,salida.r0);
    }
    printf("\n");
}

void Sum1bit::salidaPorPantalla()
{
    printf("\n-> co r0\n    %d  %d\n",
    salida.co,salida.r0);
}
#endif

Sum4bit::Sum4bit(){salida.total=0;}
void Sum4bit::conectar(ENTRADA a,ENTRADA b)
{
    salida.total = (0x1F&(a+b));
}
void Sum4bit::conectar(ENTRADA a,ENTRADA b,ENTRADA ci){salida.total = a+b+ci;}
void Sum4bit::conectar(ENTRADA a3,ENTRADA a2,ENTRADA a1,ENTRADA a0,ENTRADA b3,ENTRADA b2,ENTRADA b1,ENTRADA b0){
    unsigned int a=(a3<<3)+(a2<<2)+(a1<<1)+a0;
    unsigned int b=(b3<<3)+(b2<<2)+(b1<<1)+b0;
    salida.total = (0x1F&(a+b));
}
void Sum4bit::conectar(ENTRADA a3,ENTRADA a2,ENTRADA a1,ENTRADA a0,ENTRADA b3,ENTRADA b2,ENTRADA b1,ENTRADA b0,ENTRADA ci){
    unsigned int a=(a3<<3)+(a2<<2)+(a1<<1)+a0;
    unsigned int b=(b3<<3)+(b2<<2)+(b1<<1)+b0;
    salida.total = (0x1F&(a+b+ci));
}

#ifdef test_c8
void Sum4bit::tablaDeVerdad()
{
    BIT10 in;
    printf("\tTabla de Verdad - SUMADOR COMPLETO 4BIT\n\n");
    printf("\t      A         B\n");
    printf("\t   --------  --------\n");
    printf("\tCi A3A2A1A0  B3B2B1B0   Co R3R2R1R0\n");
    for(in.bus=0;in.bus<512;in.bus++){
        conectar(in.b7,in.b6,in.b5,in.b4,in.b3,in.b2,in.b1,in.b0,in.b8);
        if(in.bus%4==0){printf("\t-- --------  --------   -----------\n");}
        printf("%d\t%d  %d %d %d %d   %d %d %d %d     %d  %d %d %d %d = %d\n",
        in.bus,in.b8,in.b7,in.b6,in.b5,in.b4,in.b3,in.b2,in.b1,in.b0,
        salida.co,salida.r3,salida.r2,salida.r1,salida.r0,salida.total);
    }
    printf("\n");
}

void Sum4bit::salidaPorPantalla()
{
    printf("\n-> Co R3R2R1R0\n    %d  %d %d %d %d = %d\n",
    salida.co,salida.r3,salida.r2,salida.r1,salida.r0,salida.total);
}
#endif

Sum8bit::Sum8bit()
{
    salida.total=0;
}

void Sum8bit::conectar(ENTRADA a, ENTRADA b, ENTRADA ci)
{
    salida.total= (0x1FF&(a+b+ci));
}

