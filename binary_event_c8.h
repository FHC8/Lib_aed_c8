
#ifndef _BINARY_EVENT_C8_H_
#define _BINARY_EVENT_C8_H_
#include "trigger_c8.h"

class BinaryEvent : public Trigger{
private:
    unsigned int estado=0;
public:
    unsigned int evaluarValor(unsigned int valor){
        unsigned int rta = 0;
        if(estado==0 && valor==1) { rta=1; estado=1; }
        else if(estado==1 && valor==0) { estado=0; } 
        return rta;
    }
    unsigned int evaluar(unsigned int valor) {
        return (evaluarValor(valor) && (getCant()>0));
    }
};



#endif

