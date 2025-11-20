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
#include "patrones_c8.h"
#include <algorithm>
#include <stdio.h>

#define conectarCon(x) agregar(&x)

class Clock : public IObservable {
private:
    std::vector<IObserver*> observers;
    unsigned int nivel;
public:
    void agregar(IObserver* observer) override { observers.push_back(observer); }
    
    void remover(IObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    
    void notificar() override { for (IObserver* observer : observers) { observer->serNotificadoPor(this); } }
    
    // En el Evento o en la ISR
    void setNivel(unsigned int valor) {
        nivel = valor;
        printf("clk: %d\n",nivel);
        notificar(); // Notificar a todos los observadores del nuevo dato
    }
};


#endif
