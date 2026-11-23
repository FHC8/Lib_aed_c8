/**
 * @file clockExternoUno.h
 * @author your name (you@domain.com)
 * @brief Arduino UNO tiene solo 2 interrupciones Externas
 * @version 0.1
 * @date 2025-11-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _CLOCK_EXTERNO_H_
#define _CLOCK_EXTERNO_H_
#ifdef test_c8
#include <Arduino.h>
#include <trigger_c8.h>
#include <SimplyAtomic.h>

#define FLANCO_POS RISING
#define FLANCO_NEG FALLING

#define INIT_ClockExternoUno ClockExternoUno* ClockExternoUno::instance_0 = nullptr; \
ClockExternoUno* ClockExternoUno::instance_1 = nullptr

class ClockExternoUno : public Trigger{
private:
    volatile unsigned int event_counter;
    // Static pointer a una de las instancias disponibles en UNO (INT0 e INT1)
    static ClockExternoUno* instance_0;
    // Static pointer a una de las instancias disponibles en UNO (INT0 e INT1)
    static ClockExternoUno* instance_1;

    // Static ISR 
    static void isrWrapper_0() {if (instance_0) {instance_0->handleInterrupt();}}
    // Static ISR 
    static void isrWrapper_1() {if (instance_1) {instance_1->handleInterrupt();}}

    /**
     * @brief Metodo para recibir la interrupcion
     */
    void handleInterrupt() { event_counter++; }

public:
    /**
     * @brief Constructor de un Objeto Clock Externo de Arduino Uno
     * 
     * @param pin_n 2 | 3
     * @param mode FLANCO_POS | FLANCO_NEG
     */
    ClockExternoUno(uint8_t pin_n, int mode);

    /**
     * @brief Si hubo clock, actualiza los componentes que lo reciben
     */
    void actualizarClock();
};

#endif
#endif

