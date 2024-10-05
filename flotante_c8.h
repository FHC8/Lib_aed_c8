/**
 * @file flotante_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Analisis de un flotante
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _FLOTANTE_H
#define _FLOTANTE_H
#include "common_type_c8.h"
#include <stdio.h>

/**
 * @brief flotante simple discriminado 
 * 
 */
class IEEE_754_c8 {
    public :
        /**
         * @brief Constructor
         * 
         */
        IEEE_754_c8();
        /**
         * @brief Constructor
         * 
         * @param f un numero con coma
         */
        IEEE_754_c8(float f);
        /**
         * @brief Cargar un flotante
         * 
         * @param f un numero con coma
         */
        void setFlotante(float f);
        /**
         * @brief Devolver un flotante
         * 
         * @return float 
         */
        float getFlotante(void);
        /**
         * @brief Devolver la Mantisa del flotante
         * 
         * @return CAMPO mantisa
         */
        CAMPO getMantisa(void);
        /**
         * @brief Cargar una Mantisa
         * 
         * @param m mantisa
         */
        void setMantisa(CAMPO m);
        /**
         * @brief Devolver una Cadena de Bit de la Mantisa
         * 
         * @return char* 
         */
        char* getStrBinMantisa(void);
        /**
         * @brief Devolver el Exponente desplazado del flotante
         * 
         * @return CAMPO exponente desplazado
         */
        CAMPO getExponenteD(void);
        /**
         * @brief Cargar un Exponente desplazado
         * 
         * @param ed exponente desplazado
         */
        void setExponenteD(CAMPO ed);
        /**
         * @brief Devolver una Cadena de Bit del Exponente desplazado
         * 
         * @return char* 
         */
        char* getStrBinExponenteD(void);
        /**
         * @brief Obtener el Signo del flotante
         * 
         * @return CAMPO signo
         */
        CAMPO getSigno(void);
        /**
         * @brief Cargar un Signo
         * 
         * @param s Signo
         */
        void setSigno(CAMPO s);
        /**
         * @brief Obtener el Signo del flotante
         * 
         * @return char* 
         */
        char* getStrBinSigno(void);
    private:
    IEEE_754_t flotante;
    char strmantisa[24];
    char strexponented[9];
    char strsigno[2];
    void updateMantisa();
    void updateExponenteD();
    void updateSigno();

};
#endif