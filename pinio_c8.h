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
#include "config_lib_aed_c8.h"
#include "common_type_c8.h"
#include <stdio.h>

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
#define fl(valor) ((valor) & 0x0001)
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

/**
 * @brief componente base que da funcionalidades
 * de configuracion y actualizacion de salidas. 
 * Destinado a ser consumida por otro componente
 * de manera interna.
 * 
 * @tparam cantidadDePines a definir cuando se use
 */
template<int cantidadDePines>
class SalidasArduiniables {
protected:
  /**
   * @brief array con los numeros de pin de salida,
   * desde el bit 0 a bit (cantidadDePines-1)
   * 
   */
  PIN pinSalida[cantidadDePines];
public:
  SalidasArduiniables(){
    for(int i=0;i<cantidadDePines;i++){pinSalida[i]=0;}
  }
  /**
   * @brief Configura todos los pines definidos como salida
   * 
   */
  void configurarSalidas(){
#ifndef test_c8
    for(int i=0;i<cantidadDePines;i++){salida(pinSalida[i]);}
#endif
  }
  /**
   * @brief Configura todos los pines definidos dentro del rango 
   * como salida
   * 
   * @param ini pin de inicio
   * @param fin pin final
   */
  void configurarSalidas(PIN ini, PIN fin){
#ifndef test_c8
    for(int i=ini;i<fin;i++){salida(pinSalida[i]);}
#endif
  }
  void configurarSalidas(PIN pin){
#ifndef test_c8
    salida(pinSalida[pin]);
#endif
  }
  void actualizar(SALIDA bus,PIN pin){
#ifndef test_c8
    escribir(pinSalida[pin],fl(bus>>pin));
#endif
  }
  /**
   * @brief pone 1 o 0 en cada pin de salida
   * definido, segun los bits del bus de datos
   * 
   * @param bus cada bit saldra por cada
   * pin de salida.
   */
  void actualizar(SALIDA bus){
    for(int i=0;i<cantidadDePines;i++){
#ifndef test_c8
        escribir(pinSalida[i],fl(bus>>i));
#else
        printf("pin: %2d -> salida: %d\n", pinSalida[i], ((bus>>i)&0x00000001));
#endif
    }
  }
};


#endif

