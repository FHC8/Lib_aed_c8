/**
 * @file flotante_c8.cpp
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Metodos
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "flotante_c8.h"


IEEE_754_c8::IEEE_754_c8(){}

IEEE_754_c8::IEEE_754_c8(float f){setFlotante(f);}

void IEEE_754_c8::setFlotante(float f)
{
    flotante.valor=f;
    updateExponenteD();
    updateMantisa();
    updateSigno();
}

float IEEE_754_c8::getFlotante(void) {
    return flotante.valor;
}

CAMPO IEEE_754_c8::getMantisa(void) {
    return flotante.mantisa;
}

void IEEE_754_c8::setMantisa(CAMPO m) {
    flotante.mantisa=(m&0x007FFFFF);
}

char *IEEE_754_c8::getStrBinMantisa(void) {
    return strmantisa;
}

CAMPO IEEE_754_c8::getExponenteD(void) {
    return flotante.exponente_d;
}

void IEEE_754_c8::setExponenteD(CAMPO ed) {
    flotante.exponente_d=(ed&0x000000FF);
}

char *IEEE_754_c8::getStrBinExponenteD(void)
{
    return strexponented;
}

void IEEE_754_c8::setSigno(CAMPO s) {
    flotante.signo=(s&0x00000001);
}

char *IEEE_754_c8::getStrBinSigno(void)
{
    return strsigno;
}

void IEEE_754_c8::updateMantisa() {
    unsigned int mascara = 1,i=0;
    mascara<<=22;
    for(i=0;i<23;i++,mascara>>=1){
        strmantisa[i]=(flotante.mantisa&mascara)?'1':'0';
    }
    strmantisa[23]='\0';
}

void IEEE_754_c8::updateExponenteD() {
    unsigned int mascara = 1,i=0;
    mascara<<=7;
    for(i=0;i<8;i++,mascara>>=1){
        strexponented[i]=(flotante.exponente_d&mascara)?'1':'0';
    }
    strexponented[8]='\0';
}

void IEEE_754_c8::updateSigno() {
    strsigno[0]=(flotante.signo&1)?'1':'0';
    strsigno[1]='\0';
}
