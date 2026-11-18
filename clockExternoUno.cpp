#include "clockExternoUno.h"


ClockExternoUno::ClockExternoUno(uint8_t pin_n, int mode) {
    pinMode(pin_n,INPUT);   // pinMode(pin_n,INPUT_PULLUP);
    event_counter=0;
    if(pin_n == 2) {
        instance_0 = this;  // Guarda la instancia
        attachInterrupt(0, isrWrapper_0, mode);
    } else if(pin_n == 3) {
        instance_1 = this;  // Guarda la instancia
        attachInterrupt(1, isrWrapper_1, mode);
    }
}

void ClockExternoUno::actualizarClock() {
    if(event_counter>0){
        ATOMIC() { event_counter--; }
        notificar();
    }
}

