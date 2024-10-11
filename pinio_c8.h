/**
 * @file pinio_c8.h
 * @author Cochini Felix H (felixhcochini@gmail.com)
 * @brief Para usar con placa (solo arduino por ahora)
 * @version 0.1
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _PINIO_C8_H
#define _PINIO_C8_H
#include "common_type_c8.h"
#include <stdio.h>

/**
 * @brief Comentar para implementacion con Arduino
 * 
 */
#define test_c8

#ifndef test_c8
#include <Arduino.h>
/**
 * @brief Mascara para definir un numero 
 * de pin como entrada
 * 
 * @param valor representa a la expresion
 */
#define entrada(pinx) pinMode(pinx,INPUT)
/**
 * @brief Macro para definir un numero 
 * de pin como salida
 * 
 * @param pinx numero de pin
 */
#define salida(pinx) pinMode(pinx,OUTPUT)
/**
 * @brief Macro para leer el estado 
 * de un numero de pin
 * 
 * @param pinx numero de pin
 */
#define leer(pinx) digitalRead(pinx)
/**
 * @brief Macro para escribir un valor  
 * en un numero de pin
 * 
 * @param pinx numero de pin
 * @param valor nivel logico
 */
#define escribir(pinx,valor) digitalWrite(pinx,valor)
#else
/**
 * @brief Macro para definir un numero 
 * de pin como entrada
 * 
 * @param pinx numero de pin
 */
#define entrada(pinx)
/**
 * @brief Macro para definir un numero 
 * de pin como salida
 * 
 * @param pinx numero de pin
 */
#define salida(pinx)
/**
 * @brief Macro para leer el estado 
 * de un numero de pin
 * 
 * @param pinx numero de pin
 */
#define leer(pinx)
/**
 * @brief Macro para escribir un valor  
 * en un numero de pin
 * 
 * @param pinx numero de pin
 * @param valor nivel logico
 */
#define escribir(pinx,valor)
#endif
/**
 * @brief Mascara para una funcion logica
 * 
 * @param valor representa a la expresion
 */
#define fl(valor) (valor) & 0x0001
/**
 * @brief Macro para definicion de variable global
 * 
 */
#define variable(x) ENTERO x=0
/**
 * @brief Macro para activar un pin fisico
 * 
 * @param pinx numero de pin
 */
#define enAlto(pinx) escribir(pinx,HIGH)
/**
 * @brief Macro para desactivar un pin fisico
 * 
 * @param pinx numero de pin
 */
#define enBajo(pinx) escribir(pinx,LOW)
/**
 * @brief Macro para definir un pin fisico 
 * como entrada, habiendo definido el pin 
 * previamente con el formato "pinID" y dando
 * 
 * @param variable ID de la variable
 */
#define entradaPin(variable) entrada(pin##variable)
/**
 * @brief Macro para definir un pin fisico 
 * como salida, habiendo definido el pin 
 * previamente con el formato "pinID" y dando
 * 
 * @param variable ID de la variable
 */
#define salidaPin(variable) salida(pin##variable)
/**
 * @brief Macro para leer un pin fisico, 
 * habiendo definido el pin 
 * previamente con el formato "pinID". Se guarda
 * en variable
 * 
 * @param variable ID de la variable
 */
#define leerPin(variable) variable = leer(pin##variable)
/**
 * @brief Macro para escribir un pin fisico, 
 * habiendo definido el pin 
 * previamente con el formato "pinID". Se escribe
 * con el contenido de la variable
 * 
 * @param variable ID de la variable
 */
#define escribirPin(variable) escribir(pin##variable,variable)
/**
 * @brief Macro para escribir un pin fisico, 
 * habiendo definido el pin 
 * previamente con el formato "pinID". Y escribe 1
 * 
 * @param variable ID de la variable
 */
#define enAltoPin(variable) enAlto(pin##variable)
/**
 * @brief Macro para escribir un pin fisico, 
 * habiendo definido el pin 
 * previamente con el formato "pinID". Y escribe 0
 * 
 * @param variable ID de la variable
 */
#define enBajoPin(variable) enBajo(pin##variable)


template<int cantidadDePines>
class Arduiniable {
protected:
    PIN pinSalida[cantidadDePines];
public:
  Arduiniable(){
    for(int i=0;i<cantidadDePines;i++){pinSalida[i]=0;}
  }
  void actualizar(SALIDA bus){
    for(int i=0;i<cantidadDePines;i++){
#ifndef test_c8
        escribir(pinSalida[i],((bus>>i)&0x00000001));
#else
        printf("pin: %2d -> salida: %d\n", pinSalida[i], ((bus>>i)&0x00000001));
#endif
    }
  }
};







#endif

