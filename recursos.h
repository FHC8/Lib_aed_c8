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
#ifndef _RECURSOS_H
#define _RECURSOS_H
#include "config_lib_aed_c8.h"

#ifdef test_c8
#include <stdio.h>
#endif

template<int cantidad>
class c_buffer{
private:
    unsigned int array[cantidad];
    const unsigned int max=cantidad;
    unsigned int cant=0;
public:
    c_buffer(){}
    unsigned int elems(void){ return cant; }
    unsigned int hayLugar(void){ return (cant<max); }
    unsigned int hayValores(void){ return (cant>0); }
    unsigned int esValido(unsigned int idx){ return (idx<cant); }
    unsigned int poner(unsigned int valor){
        static unsigned int u=0;
        unsigned int i;
        if(hayLugar()){
            array[cant]=valor; i=cant; cant++;
        }else{
            array[u]=valor; i=u; u=(u<max)?u+1:0;
        }
        return i;
    }
    unsigned int indice(unsigned int valor){
        int i;
        for(i=0; i<cant && array[i]!=valor; i++);
        return i;
    }
    unsigned int valor(unsigned int idx){ return array[idx]; }
#ifdef test_c8
    void mostrar(void){
        int i;
        if(hayValores()){
            for(i=0; i<cant; i++){
                printf("indice: %d - valor: %d\n",i,array[i]);
            }
        }
    }
#endif
};



#endif
