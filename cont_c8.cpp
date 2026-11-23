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

BinaryEvent& Cont4bit::q(unsigned int salida){
    return qt[salida];
}

#ifdef test_c8

void Cont4bit::tablaDeVerdad()
{
}

void Cont4bit::salidaPorPantalla()
{
    printf("\n-> Co Q3Q2Q1Q0\n    %d  %d %d %d %d = %2d\n",
    salida.co,salida.q3,salida.q2,salida.q1,salida.q0,salida.cuenta);
}

void Cont4bit::salidaPorPantalla(char *val_ent, char *separador)
{
    printf("%s%s%d  %d %d %d %d = %2d\n",val_ent,separador,
    salida.co,salida.q3,salida.q2,salida.q1,salida.q0,salida.cuenta);
}

void Cont4bit::mostrarColumnas(char *msj_ent, char *separador)
{
    printf("%s%sCo Q3Q2Q1Q0\n",msj_ent,separador);
}

#endif

// Cont16bit::Cont16bit(){ salida.cuenta=0; }

// BinaryEvent& Cont16bit::q(unsigned int salida){
//     unsigned int i=0;
//     static unsigned int u=0;
//     if(cant==0){//no tiene ninguno, asigna un trigger
//         qi[0]=salida; cant++;
//     } else {//lo busca
//         for(i=0; i<cant && qi[i]!=salida; i++)

//         if(i>=cant){// NO lo encontro
//             if(i<MAX_SALIDAS){// Hay libres 
//                 qi[i]=salida; cant++;
//             } else {// Todos ocupados
//                 qi[u]=salida; u++;
//                 if(u==MAX_SALIDAS){u=0;}
//             }
//         }

//     }

//     return qt[i];
// }



