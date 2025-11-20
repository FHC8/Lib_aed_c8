/**
 * @file clock_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-11-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _CLOCK_C8_H_
#define _CLOCK_C8_H_
#include "trigger_c8.h"
#include "config_lib_aed_c8.h"
#ifdef test_c8
#include "debug_c8.h"
#include <stdio.h>
#endif


#define conectarCon(x) agregar(&x)

class Clock : public Trigger {
public:
    // En el Evento o en la ISR
    void setClock() {
#ifdef test_c8
        printf("set - clk\n");
#endif
        notificar(); // Notificar a todos los observadores del nuevo dato
    }
};

#endif
