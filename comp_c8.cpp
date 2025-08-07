/**
 * @file comp_c8.cpp
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Metodos
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "comp_c8.h"

Comp1bit::Comp1bit(){}

void Comp1bit::conectar(ENTRADA A, ENTRADA B){
    if(A>B){
        salida.resultado=0b001;
    } else if (A<B) {
        salida.resultado=0b100;
    } else {
        salida.resultado=0b010;
    }
}

#ifdef test_c8
void Comp1bit::tablaDeVerdad()
{
    VAR4 in;
    printf("\tTabla de Verdad - COMPARADOR 1BIT\n\n");
    printf("\tA  B   A>B A=B A<B\n");
    for(in.valor=0;in.valor<4;in.valor++){
        conectar(in.b1,in.b0);
        if(in.valor%4==0){printf("\t----   -----------\n");}
        printf("%d\t%d  %d    %d   %d   %d   \n",
        in.valor,in.b1,in.b0,
        salida.A_Mayor_B,salida.A_Igual_B,salida.A_Menor_B);
    }
    printf("\n");
}

void Comp1bit::salidaPorPantalla()
{
    printf("\n-> A>B A=B A<B\n    %d   %d   %d\n",
    salida.A_Mayor_B,salida.A_Igual_B,salida.A_Menor_B);
}
#endif

Comp4bit::Comp4bit(){}
void Comp4bit::conectar(ENTRADA A, ENTRADA B)
{
    Comp1bit::conectar(A,B);
}
void Comp4bit::conectar(ENTRADA A, ENTRADA B, ENTRADA A_Mayor_B, ENTRADA A_Igual_B, ENTRADA A_Menor_B)
{
    Comp1bit::conectar(A,B);
    //salida.A_Mayor_B;
}
void Comp4bit::conectar(ENTRADA A_3,ENTRADA A_2,ENTRADA A_1,ENTRADA A_0,ENTRADA B_3,ENTRADA B_2,ENTRADA B_1,ENTRADA B_0){
    unsigned int a = (A_3<<3)+(A_2<<2)+(A_1<<1)+A_0;
    unsigned int b = (B_3<<3)+(B_2<<2)+(B_1<<1)+B_0;
    Comp1bit::conectar(a,b);
}
void Comp4bit::conectar(ENTRADA A_3,ENTRADA A_2,ENTRADA A_1,ENTRADA A_0,ENTRADA B_3,ENTRADA B_2,ENTRADA B_1,ENTRADA B_0,ENTRADA A_Mayor_B,ENTRADA A_Igual_B,ENTRADA A_Menor_B){

}

#ifdef test_c8
void Comp4bit::tablaDeVerdad()
{
    BIT10 in;
    printf("\tTabla de Verdad - COMPARADOR 4BIT\n\n");
    printf("\t   A         B\n");
    printf("\t--------  --------\n");
    printf("\tA3A2A1A0  B3B2B1B0   A>B A=B A<B\n");
    for(in.bus=0;in.bus<256;in.bus++){
        conectar(in.b7,in.b6,in.b5,in.b4,in.b3,in.b2,in.b1,in.b0);
        if(in.bus%4==0){printf("\t--------  --------   -----------\n");}
        printf("%d\t%d %d %d %d   %d %d %d %d     %d   %d   %d\n",
        in.bus,in.b7,in.b6,in.b5,in.b4,in.b3,in.b2,in.b1,in.b0,
        salida.A_Mayor_B,salida.A_Igual_B,salida.A_Menor_B);
    }
    printf("\n");    
}

void Comp4bit::salidaPorPantalla()
{
    printf("\n-> A>B A=B A<B\n    %d   %d   %d\n",
    salida.A_Mayor_B,salida.A_Igual_B,salida.A_Menor_B);
}

void Comp4bit::salidaPorPantalla(char * val_ent,char * separador)
{
    printf("%s%s%d   %d   %d\n",val_ent,separador,
    salida.A_Mayor_B,salida.A_Igual_B,salida.A_Menor_B);
}

void Comp4bit::mostrarColumnas(char *msj_ent, char *separador)
{
    printf("%s%sA>B A=B A<B\n",msj_ent,separador);
}

#endif
