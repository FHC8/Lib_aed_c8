#include "utilidades.h"

int printfBin(ENTERO valor, ENTERO cantbit)
{
    char buff[cantbit+1]={0};
    ENTERO mascara = 1,i=0;
    mascara<<=(cantbit-1);
    for(i=0;i<cantbit;i++,mascara>>=1){
        buff[i]=(valor&mascara)?'1':'0';
    }
    buff[cantbit]='\0';
    return printf("-> %s",buff);
}
