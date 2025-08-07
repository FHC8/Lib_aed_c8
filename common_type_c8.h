/**
 * @file common_type_c8.h
 * @author Cochini Felix H (felixhcochini@gmail.com)
 * @brief Definicion de tipos de uso comun
 * @version 0.1
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _COMMON_TYPE_C8_H
#define _COMMON_TYPE_C8_H
#include "config_lib_aed_c8.h"

#ifdef test_c8
#include <cstdio>
#define COLUMNAS(nom,msj) char nom[] = msj
#define SEPARADOR(nom,msj) char nom[] = msj
#define ETIQUETAS(nom,msj) char nom[] = msj
#define STR_VALORES(nom) char nom[50]
#define STR_VALORES_N(nom,n) char nom[n]
#define FORMATEAR(nom,format,...) snprintf(nom, sizeof(nom), format, __VA_ARGS__)
#endif

/**
 * @brief tipo de variable
 */
typedef unsigned int PIN;
/**
 * @brief tipo de variable
 */
typedef unsigned int ENTERO;
/**
 * @brief tipo de variable
 */
typedef unsigned int ENTRADA;
/**
 * @brief tipo de variable
 */
typedef unsigned int SALIDA;
/**
 * @brief tipo de variable
 */
typedef unsigned int BINARIO;
/**
 * @brief tipo de variable
 */
typedef unsigned int BINARIOS;
/**
 * @brief tipo de variable
 */
typedef unsigned int PUERTO;
/**
 * @brief tipo de variable
 */
typedef unsigned int BUS;
/**
 * @brief tipo de variable
 */
typedef unsigned int CAMPO;

/**
 * @brief tipo de variable
 */
typedef unsigned long DATO;


/**
 * @brief definicion de un campo de 1 bit
 * para uso exclusivo en estructuras.
 * 
 * @param x es el nombre
 */
#define dbit(x) CAMPO x:1;

/**
 * @brief definicion de un puerto, para
 * uso exclusivo en estructuras
 * 
 * @param x es el nombre
 */
#define port(x) PUERTO x;
/**
 * @brief definicion de un puerto, para
 * uso exclusivo en estructuras
 * 
 * @param x es el nombre
 * @param n es la cantidad de bit
 */
#define dport(x,n) PUERTO x:n;

#define unidad(los_campos_desde_0,nombre)\
union {\
los_campos_desde_0\
}nombre;

#define unidadx(los_campos_desde_0) unidad(los_campos_desde_0,nombre)

#define conjunto(los_campos_desde_0,nombre) \
struct {\
los_campos_desde_0\
}nombre;

#define conjuntox(los_campos_desde_0) conjunto(los_campos_desde_0,)

#define define_bus(nombre,los_bits_desde_0) \
union {\
    PUERTO bus;\
    struct {\
        los_bits_desde_0\
    };\
} nombre

/**
 * @brief definicion de un bus a medida
 * 
 * @param nombre del bus a crear
 * @param los_bits_desde_0 lista de dport/dbit
 * necesarios comenzando por el bit 0
 */
#define custom_bus(nombre,los_bits_desde_0) \
typedef union {\
    PUERTO bus;\
    struct {\
        los_bits_desde_0\
    };\
} nombre
/**
 * @brief definicion de un bus de 4 bit
 * 
 * @param nombre del bus a crear
 * @param x3 nombre del bit 3
 * @param x2 nombre del bit 2
 * @param x1 nombre del bit 1
 * @param x0 nombre del bit 0
 */
#define custom_bus4(nombre,x3,x2,x1,x0) \
typedef union { \
    dport(bus,4)\
    struct {\
        dbit(x0)\
        dbit(x1)\
        dbit(x2)\
        dbit(x3)\
    };\
} nombre
/**
 * @brief definicion de un bus de 8 bit
 * 
 * @param nombre del bus a crear
 * @param x7 nombre del bit 7
 * @param x6 nombre del bit 6
 * @param x5 nombre del bit 5
 * @param x4 nombre del bit 4
 * @param x3 nombre del bit 3
 * @param x2 nombre del bit 2
 * @param x1 nombre del bit 1
 * @param x0 nombre del bit 0
 */
#define custom_bus8(nombre,x7,x6,x5,x4,x3,x2,x1,x0) \
typedef union { \
    dport(bus,8)\
    struct {\
        dbit(x0)\
        dbit(x1)\
        dbit(x2)\
        dbit(x3)\
        dbit(x4)\
        dbit(x5)\
        dbit(x6)\
        dbit(x7)\
    };\
} nombre

/**
 * @brief 1 bit generico
 */
typedef struct 
{
    BINARIO b0:1;
} BIT;

/**
 * @union BIT4 
 * 
 * @brief bus de 4 bit generico
 * 
 * @var BIT4::valor 
 * bus completo de 4 bit
 * @var BIT4::b0 
 * bit 0
 * @var BIT4::b1 
 * bit 1
 * @var BIT4::b2 
 * bit 2
 * @var BIT4::b3 
 * bit 3
 */
typedef union {
    dport(bus,4)
    struct{
        dbit(b0)
        dbit(b1)
        dbit(b2)
        dbit(b3)
    };
} BIT4;

/**
 * @union VAR4 
 * 
 * @brief variable de 4 bit generico
 * 
 * @code {.c}
 * VAR4 mivariable;         // creacion
 * mivariable.valor = 0xA;  // valor de 4 bit maximo
 * otravar = mivariable.b3; // solo el bit 3
 * @endcode
 * 
 * @note si carga un valor de mas de 4 bit, no genera error.
 * @f$\vec{V}@f$
 * 
 * @warning VAR4 es distinto de BIT4
 * 
 * @var VAR4::valor 
 * valor entero completo
 * @var VAR4::b0 
 * bit 0
 * @var VAR4::b1 
 * bit 1
 * @var VAR4::b2 
 * bit 2
 * @var VAR4::b3 
 * bit 3
 */
typedef union 
{
    PUERTO valor;
    struct {
        dbit(b0)
        dbit(b1)
        dbit(b2)
        dbit(b3)
    };
} VAR4;

/**
 * @union BIT8 
 * 
 * @brief bus de 4 bit generico
 * 
 * @var BIT8::valor 
 * bus completo de 4 bit
 * @var BIT8::b0 
 * bit 0
 * @var BIT8::b1 
 * bit 1
 * @var BIT8::b2 
 * bit 2
 * @var BIT8::b3 
 * bit 3
 * @var BIT8::b4 
 * bit 4
 * @var BIT8::b5
 * bit 5
 * @var BIT8::b6
 * bit 6
 * @var BIT8::b7 
 * bit 7
 */
typedef union 
{
    dport(bus,8)
    struct {
        dport(nibbleL,4)
        dport(nibbleH,4)
    };
    struct {
        dbit(b0)
        dbit(b1)
        dbit(b2)
        dbit(b3)
        dbit(b4)
        dbit(b5)
        dbit(b6)
        dbit(b7)
    };
} BIT8;

/**
 * @brief bus de 10 bit generico
 */
typedef union 
{
    dport(bus,10) /**< valor de 10 bit */
    struct {
        dbit(b0) /**< bit 0 */
        dbit(b1) /**< bit 1 */
        dbit(b2) /**< bit 2 */
        dbit(b3) /**< bit 3 */
        dbit(b4) /**< bit 4 */
        dbit(b5) /**< bit 5 */
        dbit(b6) /**< bit 6 */
        dbit(b7) /**< bit 7 */
        dbit(b8) /**< bit 8 */
        dbit(b9) /**< bit 9 */
    };
} BIT10;


#ifdef test_c8 // en PC
/**
 * @brief bus de 32 bit generico
 * 
 * @code {.c}
 * BIT32 bus;           // Declaro una variable bus de 32 bit
 * bus.valor = 128;     // Ponemos el valor 128 en el bus
 * bus.b5 = 1;          // Ponemos un 1 en el bit del bus => bus tiene 160
 * unavar = bus.b1      // Obtengo el bit 1 del bus, unavar <- 0
 * otravar = bus.valor  // otravar <- 160
 * @endcode 
 * 
 * @note BIT32 es un tipo de dato como cualquier otro, entonces 
 * de la misma forma que declaras un **int** o **float**. Es 
 * necesario hacerlo antes de poder usar una variable de este tipo.
 * 
 * 
 */
typedef union 
{
    PUERTO valor; /**< valor de 32 bit */
    struct {
      dport(byte0,8)  
      dport(byte1,8)  
      dport(byte2,8)  
      dport(byte3,8)  
    };
    struct {
        dport(nibble0L,4)
        dport(nibble0H,4)
        dport(nibble1L,4)
        dport(nibble1H,4)
        dport(nibble2L,4)
        dport(nibble2H,4)
        dport(nibble3L,4)
        dport(nibble3H,4)
    };
    struct {
        dbit(b0) /**< bit 0 */
        dbit(b1) /**< bit 1 */
        dbit(b2) /**< bit 2 */
        dbit(b3) /**< bit 3 */
        dbit(b4) /**< bit 4 */
        dbit(b5) /**< bit 5 */
        dbit(b6) /**< bit 6 */
        dbit(b7) /**< bit 7 */
        dbit(b8) /**< bit 8 */
        dbit(b9) /**< bit 9 */
        dbit(b10) /**< bit 10 */
        dbit(b11) /**< bit 11 */
        dbit(b12) /**< bit 12 */
        dbit(b13) /**< bit 13 */
        dbit(b14) /**< bit 14 */
        dbit(b15) /**< bit 15 */
        dbit(b16) /**< bit 16 */
        dbit(b17) /**< bit 17 */
        dbit(b18) /**< bit 18 */
        dbit(b19) /**< bit 19 */
        dbit(b20) /**< bit 20 */
        dbit(b21) /**< bit 21 */
        dbit(b22) /**< bit 22 */
        dbit(b23) /**< bit 23 */
        dbit(b24) /**< bit 24 */
        dbit(b25) /**< bit 25 */
        dbit(b26) /**< bit 26 */
        dbit(b27) /**< bit 27 */
        dbit(b28) /**< bit 28 */
        dbit(b29) /**< bit 29 */
        dbit(b30) /**< bit 30 */
        dbit(b31) /**< bit 31 */
    };
} BIT32;



/**
 * @brief flotante discriminado por partes
 */
typedef union 
{
    float valor; /**< valor con coma */
struct {
    CAMPO mantisa:23; /**< todo lo que sigue despues de la coma */
    CAMPO exponente_d:8; /**< esponente desplazado en 127 */
    CAMPO signo:1; /**< bit de signo */
};    
} IEEE_754_t;

#else
/**
 * @brief bus de 32 bit generico
 * 
 * @code {.c}
 * BIT32 bus;           // Declaro una variable bus de 32 bit
 * bus.valor = 128;     // Ponemos el valor 128 en el bus
 * bus.b5 = 1;          // Ponemos un 1 en el bit del bus => bus tiene 160
 * unavar = bus.b1      // Obtengo el bit 1 del bus, unavar <- 0
 * otravar = bus.valor  // otravar <- 160
 * @endcode 
 * 
 * @note BIT32 es un tipo de dato como cualquier otro, entonces 
 * de la misma forma que declaras un **int** o **float**. Es 
 * necesario hacerlo antes de poder usar una variable de este tipo.
 * 
 * 
 */
typedef union 
{
    unsigned long valor; /**< valor de 32 bit */
    struct {
      dport(byte0,8)  
      dport(byte1,8)  
      dport(byte2,8)  
      dport(byte3,8)  
    };
    struct {
        dport(nibble0L,4)
        dport(nibble0H,4)
        dport(nibble1L,4)
        dport(nibble1H,4)
        dport(nibble2L,4)
        dport(nibble2H,4)
        dport(nibble3L,4)
        dport(nibble3H,4)
    };
    struct {
        dbit(b0) /**< bit 0 */
        dbit(b1) /**< bit 1 */
        dbit(b2) /**< bit 2 */
        dbit(b3) /**< bit 3 */
        dbit(b4) /**< bit 4 */
        dbit(b5) /**< bit 5 */
        dbit(b6) /**< bit 6 */
        dbit(b7) /**< bit 7 */
        dbit(b8) /**< bit 8 */
        dbit(b9) /**< bit 9 */
        dbit(b10) /**< bit 10 */
        dbit(b11) /**< bit 11 */
        dbit(b12) /**< bit 12 */
        dbit(b13) /**< bit 13 */
        dbit(b14) /**< bit 14 */
        dbit(b15) /**< bit 15 */
        dbit(b16) /**< bit 16 */
        dbit(b17) /**< bit 17 */
        dbit(b18) /**< bit 18 */
        dbit(b19) /**< bit 19 */
        dbit(b20) /**< bit 20 */
        dbit(b21) /**< bit 21 */
        dbit(b22) /**< bit 22 */
        dbit(b23) /**< bit 23 */
        dbit(b24) /**< bit 24 */
        dbit(b25) /**< bit 25 */
        dbit(b26) /**< bit 26 */
        dbit(b27) /**< bit 27 */
        dbit(b28) /**< bit 28 */
        dbit(b29) /**< bit 29 */
        dbit(b30) /**< bit 30 */
        dbit(b31) /**< bit 31 */
    };
} BIT32;



/**
 * @brief flotante discriminado por partes
 */
typedef union 
{
    float valor; /**< valor con coma */
struct {
    unsigned long mantisa:23; /**< todo lo que sigue despues de la coma */
    unsigned long exponente_d:8; /**< esponente desplazado en 127 */
    unsigned long signo:1; /**< bit de signo */
};    
} IEEE_754_t;

#endif

#endif