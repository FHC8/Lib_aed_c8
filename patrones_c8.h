/**
 * @file patrones_c8.h
 * @author Felix H Cochini (felixhcochini@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-11-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _PATRONES_C8_H_
#define _PATRONES_C8_H_
#include <vector>


class IObserver {
public:
    virtual void serNotificadoPor(IObservable* obserbable) = 0;
    virtual ~IObserver() {}
};


class IObservable {
public:
    virtual void agregar(IObserver* observer) = 0;
    virtual void remover(IObserver* observer) = 0;
    virtual void notificar() = 0;
    virtual ~IObservable() {}
};

#endif
 
