/**
 * @file desplazador_c8.cpp
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief Metodos
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "desplazador_c8.h"

Desp::Desp()
{
}


void Desp::conectar(DIRECCION dir, ENTRADA n, DATO datos)
{
    salida.valor=(dir)?(datos>>n):(datos<<n);
}

#ifdef test_c8
void Desp::salidaPorPantalla()
{
    char buff[33]={0};
    ENTERO mascara = 1,i=0;
    mascara<<=31;
    for(i=0;i<32;i++,mascara>>=1){
        buff[i]=(salida.valor&mascara)?'1':'0';
    }
    buff[32]='\0';
    printf("-> %s",buff);
}
#endif
