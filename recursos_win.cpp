/**
 * @file rucursos_win.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "recursos_win.h"

ConsolaColor::ConsolaColor(HANDLE consola)
{
    miConsola = consola;
    saveColorConsola();
}

ConsolaColor::ConsolaColor(HANDLE consola, WORD color)
{
    miConsola = consola;
    saveColorConsola();
    setColorConsola(color);
}

ConsolaColor::ConsolaColor()
{
    // printf("basura: %X\n\n",miConsola);
    miConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    // printf("cargado: %X\n\n",miConsola);
    saveColorConsola();
}

ConsolaColor::ConsolaColor(WORD color)
{
    ConsolaColor();
    setColorConsola(color);
}

void ConsolaColor::setColorConsola(WORD color)
{
    atributoNuevo = color;
    // printf("Color Nuevo: %X\n\n",atributoNuevo);
}

void ConsolaColor::restoreColorConsola()
{
    SetConsoleTextAttribute(miConsola, atributoAnterior);
}

void ConsolaColor::saveColorConsola()
{
    CONSOLE_SCREEN_BUFFER_INFO consolaInfo;
    GetConsoleScreenBufferInfo(miConsola, &consolaInfo);
    atributoAnterior = consolaInfo.wAttributes;
    // printf("Color anterior: %X\n\n",consolaInfo.wAttributes);
}

int ConsolaColor::printc(const char *formato,...)
{
    va_list args;
    SetConsoleTextAttribute(miConsola, atributoNuevo);
    // printf("printc\n");
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);
    SetConsoleTextAttribute(miConsola, atributoAnterior);
    return 1;
}

int ConsolaColor::printc(const char *formato)
{
    SetConsoleTextAttribute(miConsola, atributoNuevo);
    printf(formato);
    SetConsoleTextAttribute(miConsola, atributoAnterior);
    return 1;
}
