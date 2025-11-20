#include "cont_c8.h"

Cont4bit::Cont4bit(){ salida.cuenta=0; }

void Cont4bit::serNotificadoPor(IObservable* obserbable) {
    salida.cuenta++;
#ifdef test_c8
    printf("- actualiza cuenta: %d\n",salida.cuenta);
#endif
    notificar();
}

void Cont4bit::notificar() {
    unsigned int val=0;
    for(int i=0; i<MAX_SALIDAS; i++){
        val = ((salida.cuenta>>i)&1);
        if(qt[i].evaluar(val)){
    #ifdef test_c8
            printf("-- q%d: flanco ASCENDENTE\n",i);
    #endif 
            qt[i].notificar();
        }
    }
}

void Cont4bit::conectar(unsigned int Qi, IObserver *observer) {
    qt[Qi].agregar(observer);
}
