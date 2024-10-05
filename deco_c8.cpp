/**
 * @file deco_c8.cpp
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Metodos
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "deco_c8.h"

Deco2a4::Deco2a4(){salida.puerto=0;}
void Deco2a4::conectar(unsigned int a1,unsigned int a0)
{
    unsigned int valor = (a1<<1)+(a0);
    switch(valor){
        case 0: salida.puerto=1;break;
        case 1: salida.puerto=2;break;
        case 2: salida.puerto=4;break;
        default: salida.puerto=8;break;
    }
}

void Deco2a4::tablaDeVerdad()
{
    VAR4 in;
    printf("\tTabla de Verdad - DECO2a4\n\n");
    printf("\ta1 a0  o3 o2 o1 o0\n");
    for(in.valor=0;in.valor<4;in.valor++){
        conectar(in.b1,in.b0);
        if(in.valor%4==0){printf("\t-----  -----------\n");}
        printf("%d\t%d  %d   %d  %d  %d  %d\n",
        in.valor,in.b1,in.b0,
        salida.o3,salida.o2,
        salida.o1,salida.o0);
    }
}

void Deco2a4::salidaPorPantalla()
{
    printf("-> o3 o2 o1 o0\n   %d  %d  %d  %d\n",
    salida.o3,salida.o2,salida.o1,salida.o0);
}

void Deco2a4::tablaDeVerdad(HANDLE consola, WORD color)
{
    ConsolaColor cmd = ConsolaColor(consola,color);
    VAR4 in;
    printf("\tTabla de Verdad - DECO2a4\n\n");
    printf("\ta1 a0  o3 o2 o1 o0\n");
    for(in.valor=0;in.valor<4;in.valor++){
        conectar(in.b1,in.b0);
        if(in.valor%4==0){printf("\t-----  -----------\n");}
        printf("%d\t%d  %d   ",
        in.valor,in.b1,in.b0);
        printSiUnoCon(cmd,salida.o3);printf("  ");
        printSiUnoCon(cmd,salida.o2);printf("  ");
        printSiUnoCon(cmd,salida.o1);printf("  ");
        printSiUnoCon(cmd,salida.o0);printf("\n");
    }
}

void Deco2a4::salidaPorPantalla(HANDLE consola, WORD color)
{
    ConsolaColor cmd = ConsolaColor(consola,color);
    printf("-> o3 o2 o1 o0\n   ");
    printSiUnoCon(cmd,salida.o3);printf("  ");
    printSiUnoCon(cmd,salida.o2);printf("  ");
    printSiUnoCon(cmd,salida.o1);printf("  ");
    printSiUnoCon(cmd,salida.o0);printf("  ");
}

Deco3a8::Deco3a8(){salida.puerto=0;}
void Deco3a8::conectar(unsigned int a2,unsigned int a1,unsigned int a0)
{
    unsigned int valor = (a2<<2)+(a1<<1)+(a0);
    switch(valor){
        case 0: salida.puerto=1;break;
        case 1: salida.puerto=2;break;
        case 2: salida.puerto=4;break;
        case 3: salida.puerto=8;break;
        case 4: salida.puerto=16;break;
        case 5: salida.puerto=32;break;
        case 6: salida.puerto=64;break;
        default: salida.puerto=128;
    }
}

void Deco3a8::tablaDeVerdad()
{
    VAR4 in;
    printf("\tTabla de Verdad - DECO3a8\n\n");
    printf("\ta2 a1 a0  o7 o6 o5 o4 o3 o2 o1 o0\n");
    for(in.valor=0;in.valor<8;in.valor++){
        conectar(in.b2,in.b1,in.b0);
        if(in.valor%4==0){printf("\t--------  -----------------------\n");}
        printf("%d\t%d  %d  %d   %d  %d  %d  %d  %d  %d  %d  %d\n",
        in.valor,in.b2,in.b1,in.b0,
        salida.o7,salida.o6,salida.o5,salida.o4,
        salida.o3,salida.o2,salida.o1,salida.o0);
    }
}

void Deco3a8::salidaPorPantalla()
{
    printf("-> o7 o6 o5 o4 o3 o2 o1 o0\n   %d  %d  %d  %d  %d  %d  %d\n",
    salida.o7,salida.o6,salida.o5,salida.o4,
    salida.o3,salida.o2,salida.o1,salida.o0);
}

void Deco3a8::tablaDeVerdad(HANDLE consola, WORD color)
{
    ConsolaColor cmd = ConsolaColor(consola,color);
    VAR4 in;
    printf("\tTabla de Verdad - DECO3a8\n\n");
    printf("\ta2 a1 a0  o7 o6 o5 o4 o3 o2 o1 o0\n");
    for(in.valor=0;in.valor<8;in.valor++){
        conectar(in.b2,in.b1,in.b0);
        if(in.valor%4==0){printf("\t--------  -----------------------\n");}
        printf("%d\t%d  %d  %d   ",
        in.valor,in.b2,in.b1,in.b0);
        printSiUnoCon(cmd,salida.o7);printf("  ");
        printSiUnoCon(cmd,salida.o6);printf("  ");
        printSiUnoCon(cmd,salida.o5);printf("  ");
        printSiUnoCon(cmd,salida.o4);printf("  ");
        printSiUnoCon(cmd,salida.o3);printf("  ");
        printSiUnoCon(cmd,salida.o2);printf("  ");
        printSiUnoCon(cmd,salida.o1);printf("  ");
        printSiUnoCon(cmd,salida.o0);printf("\n");
    }
}

void Deco3a8::salidaPorPantalla(HANDLE consola, WORD color)
{
    ConsolaColor cmd = ConsolaColor(consola,color);
    printf("-> o7 o6 o5 o4 o3 o2 o1 o0\n   ");
    printSiUnoCon(cmd,salida.o7);printf("  ");
    printSiUnoCon(cmd,salida.o6);printf("  ");
    printSiUnoCon(cmd,salida.o5);printf("  ");
    printSiUnoCon(cmd,salida.o4);printf("  ");
    printSiUnoCon(cmd,salida.o3);printf("  ");
    printSiUnoCon(cmd,salida.o2);printf("  ");
    printSiUnoCon(cmd,salida.o1);printf("  ");
    printSiUnoCon(cmd,salida.o0);printf("\n");
}

//-------------------------------------
//-------------------------------------
//-------------------------------------

Deco7seg::Deco7seg()
{
    salida.port=0;
    for(int i=0;i<7;i++){
        pinSalida[i]=0;
    }
}

Deco7seg::Deco7seg(SALIDA pa, SALIDA pb, SALIDA pc, SALIDA pd, SALIDA pe, SALIDA pf, SALIDA pg)
{
    salida.port=0;
    pinSalida[6]=pa;
    pinSalida[5]=pb;
    pinSalida[4]=pc;
    pinSalida[3]=pd;
    pinSalida[2]=pe;
    pinSalida[1]=pf;
    pinSalida[0]=pg;
}

void Deco7seg::configurar()
{
    for(int i=0;i<7;i++){
        salida(pinSalida[i]);
    }
}
void Deco7seg::conectar(ENTRADA A,ENTRADA B,ENTRADA C,ENTRADA D)
{
    unsigned int valor = (A<<3)+(B<<2)+(C<<1)+D;
    switch(valor){
        case 0: salida.port=0b1111110;break;
        case 1: salida.port=0b0110000;break;
        case 2: salida.port=0b1101101;break;
        case 3: salida.port=0b1111001;break;
        case 4: salida.port=0b0110011;break;
        case 5: salida.port=0b1011011;break;
        case 6: salida.port=0b1011111;break;
        case 7: salida.port=0b1110000;break;
        case 8: salida.port=0b1111111;break;
        case 9: salida.port=0b1111011;break;
        default: salida.port=0b0000001;break;
    }
}
void Deco7seg::mostrar(SALIDA pa, SALIDA pb, SALIDA pc, SALIDA pd, SALIDA pe, SALIDA pf, SALIDA pg)
{
    escribir(pa,salida.a);
    escribir(pb,salida.b);
    escribir(pc,salida.c);
    escribir(pd,salida.d);
    escribir(pe,salida.e);
    escribir(pf,salida.f);
    escribir(pg,salida.g);
}

void Deco7seg::conectar(BIT4 entrada)
{
    conectar(entrada.b3, entrada.b2, entrada.b1, entrada.b0);
}

void Deco7seg::mostrar()
{
    for(int i=0;i<7;i++){
        escribir(pinSalida[i],((salida.port>>i)&0x0001));
    }
}

#ifdef test_c8
void Deco7seg::tablaDeVerdad()
{
    VAR4 bcd;
    printf("\tTabla de Verdad - BCD7SEG\n\n");
    printf("\tA B C D  a b c d e f g\n");
    for(bcd.valor=0;bcd.valor<16;bcd.valor++){
        conectar(bcd.b3,bcd.b2,bcd.b1,bcd.b0);
        if(bcd.valor%4==0){printf("\t-------  -------------\n");}
        printf("%d\t%d %d %d %d  %d %d %d %d %d %d %d\n",
        bcd.valor,bcd.b3,bcd.b2,bcd.b1,bcd.b0,
        salida.a,salida.b,salida.c,salida.d,
        salida.e,salida.f,salida.g);
    }    
}

void Deco7seg::salidaPorPantalla()
{
    printf("-> a b c d e f g\n   %d %d %d %d %d %d %d\n",
    salida.a,salida.b,salida.c,salida.d,
    salida.e,salida.f,salida.g);
}

void Deco7seg::tablaDeVerdad(HANDLE consola, WORD color)
{
    ConsolaColor cmd = ConsolaColor(consola,color);
    VAR4 bcd;
    printf("\tTabla de Verdad - BCD7SEG\n\n");
    printf("\tA B C D  a b c d e f g\n");
    for(bcd.valor=0;bcd.valor<16;bcd.valor++){
        conectar(bcd.b3,bcd.b2,bcd.b1,bcd.b0);
        if(bcd.valor%4==0){printf("\t-------  -------------\n");}
        printf("%d\t%d %d %d %d  ",
        bcd.valor,bcd.b3,bcd.b2,bcd.b1,bcd.b0);
        printSiUnoCon(cmd,salida.a);printf(" ");
        printSiUnoCon(cmd,salida.b);printf(" ");
        printSiUnoCon(cmd,salida.c);printf(" ");
        printSiUnoCon(cmd,salida.d);printf(" ");
        printSiUnoCon(cmd,salida.e);printf(" ");
        printSiUnoCon(cmd,salida.f);printf(" ");
        printSiUnoCon(cmd,salida.g);printf("\n");
    }
}
void Deco7seg::salidaPorPantalla(HANDLE consola, WORD color)
{
    ConsolaColor cmd = ConsolaColor(consola,color);
    printf("-> a b c d e f g\n   ");
    printSiUnoCon(cmd,salida.a);printf(" ");
    printSiUnoCon(cmd,salida.b);printf(" ");
    printSiUnoCon(cmd,salida.c);printf(" ");
    printSiUnoCon(cmd,salida.d);printf(" ");
    printSiUnoCon(cmd,salida.e);printf(" ");
    printSiUnoCon(cmd,salida.f);printf(" ");
    printSiUnoCon(cmd,salida.g);printf("\n");
}
#endif