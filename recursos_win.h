/**
 * @file rucursos_win.h
 * @author Cochini Felix H (felixhcochini@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _RECURSOS_WIN_H
#define _RECURSOS_WIN_H
#include "config_lib_aed_c8.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef test_c8
#include <windows.h>

/*
Attribute	                Meaning
--------------------------  --------------------------------------------
FOREGROUND_BLUE	            Text color contains blue.
FOREGROUND_GREEN	        Text color contains green.
FOREGROUND_RED	            Text color contains red.
FOREGROUND_INTENSITY	    Text color is intensified.
BACKGROUND_BLUE	            Background color contains blue.
BACKGROUND_GREEN	        Background color contains green.
BACKGROUND_RED	            Background color contains red.
BACKGROUND_INTENSITY	    Background color is intensified.
COMMON_LVB_LEADING_BYTE	    Leading byte.
COMMON_LVB_TRAILING_BYTE	Trailing byte.
COMMON_LVB_GRID_HORIZONTAL	Top horizontal.
COMMON_LVB_GRID_LVERTICAL	Left vertical.
COMMON_LVB_GRID_RVERTICAL	Right vertical.
COMMON_LVB_REVERSE_VIDEO	Reverse foreground and background attributes.
COMMON_LVB_UNDERSCORE	    Underscore.


Ejemplo
FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE
*/


class ConsolaColor {
    public:
    ConsolaColor(HANDLE consola);
    ConsolaColor(HANDLE consola, WORD color);
    ConsolaColor();
    ConsolaColor(WORD color);
    void setColorConsola(WORD color);
    void restoreColorConsola();
    void saveColorConsola();
    int printc(const char *formato,...);
    int printc(const char *formato);
    private:
    HANDLE miConsola;
    WORD atributoAnterior;
    WORD atributoNuevo;
};

#define printSiUnoCon(consola,val) (val)?consola.printc("%d",val):printf("%d",val)

#define CONSOLAC8 GetStdHandle(STD_OUTPUT_HANDLE)
// (x)?printf(colores[colorx],x,strsp):printf("%d%s",x,strsp)

#define DEFAULT (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY)	        

#define AZUL (FOREGROUND_BLUE|\
FOREGROUND_INTENSITY)	        

#define VERDE (FOREGROUND_GREEN|\
FOREGROUND_INTENSITY)	        

#define ROJO (FOREGROUND_RED|\
FOREGROUND_INTENSITY)	        

#define CELESTE (FOREGROUND_BLUE|\
FOREGROUND_GREEN|\
FOREGROUND_INTENSITY)	        

#define AMARILLO (FOREGROUND_GREEN|\
FOREGROUND_RED|\
FOREGROUND_INTENSITY)

#define VIOLETA (FOREGROUND_BLUE|\
FOREGROUND_RED|\
FOREGROUND_INTENSITY)


#define FROJO (BACKGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_INTENSITY)	        	        

#define FROJO1 (BACKGROUND_RED|\
FOREGROUND_INTENSITY)	        	        

#define FROJO2 (BACKGROUND_RED|\
BACKGROUND_INTENSITY)	        	        

#define FROJO3 BACKGROUND_RED

#define FVERDE (BACKGROUND_GREEN|\
FOREGROUND_INTENSITY|\
BACKGROUND_INTENSITY)

#define FVERDE1 (BACKGROUND_GREEN|\
FOREGROUND_INTENSITY)

#define FVERDE2 (BACKGROUND_GREEN|\
BACKGROUND_INTENSITY)

#define FVERDE3 BACKGROUND_GREEN


#define FAZUL (BACKGROUND_BLUE|\
FOREGROUND_INTENSITY|\
BACKGROUND_INTENSITY)

#define FAZUL1 (BACKGROUND_BLUE|\
FOREGROUND_INTENSITY)

#define FAZUL2 (BACKGROUND_BLUE|\
BACKGROUND_INTENSITY)

#define FAZUL3 BACKGROUND_BLUE


#define FCELESTE (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_BLUE|BACKGROUND_GREEN|\
BACKGROUND_INTENSITY)	        	        

#define FCELESTE1 (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_BLUE|BACKGROUND_GREEN)	        	        

#define FCELESTE2 (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
BACKGROUND_BLUE|BACKGROUND_GREEN)	        	        

#define FCELESTE0 (BACKGROUND_BLUE|\
BACKGROUND_GREEN|FOREGROUND_INTENSITY|\
BACKGROUND_INTENSITY)	        	        

#define FCELESTE3 (BACKGROUND_BLUE|\
BACKGROUND_GREEN|FOREGROUND_INTENSITY)	        	        

#define FCELESTE4 (BACKGROUND_BLUE|\
BACKGROUND_GREEN|BACKGROUND_INTENSITY)	        	        

#define FCELESTE5 (BACKGROUND_BLUE|\
BACKGROUND_GREEN)	        	        

#define FAMARILLO (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_GREEN|BACKGROUND_RED|\
BACKGROUND_INTENSITY)	        	        

#define FAMARILLO1 (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_GREEN|BACKGROUND_RED)	        	        

#define FAMARILLO2 (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
BACKGROUND_GREEN|BACKGROUND_RED)	        	        

#define FAMARILLO0 (BACKGROUND_GREEN|\
BACKGROUND_RED|FOREGROUND_INTENSITY|\
BACKGROUND_INTENSITY)	        	        

#define FAMARILLO3 (BACKGROUND_GREEN|\
BACKGROUND_RED|FOREGROUND_INTENSITY)	        	        

#define FAMARILLO4 (BACKGROUND_GREEN|\
BACKGROUND_RED|BACKGROUND_INTENSITY)	        	        

#define FAMARILLO5 (BACKGROUND_GREEN|\
BACKGROUND_RED)	        	        


#define FVIOLETA (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_BLUE|BACKGROUND_RED|\
BACKGROUND_INTENSITY)	        	        

#define FVIOLETA1 (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
FOREGROUND_INTENSITY|\
BACKGROUND_BLUE|BACKGROUND_RED)	        	        

#define FVIOLETA2 (FOREGROUND_BLUE|\
FOREGROUND_GREEN|FOREGROUND_RED|\
BACKGROUND_BLUE|BACKGROUND_RED)	        	        

#define FVIOLETA0 (BACKGROUND_BLUE|\
BACKGROUND_RED|FOREGROUND_INTENSITY|\
BACKGROUND_INTENSITY)	        	        

#define FVIOLETA3 (BACKGROUND_BLUE|\
BACKGROUND_RED|FOREGROUND_INTENSITY)	        	        

#define FVIOLETA4 (BACKGROUND_BLUE|\
BACKGROUND_RED|BACKGROUND_INTENSITY)	        	        

#define FVIOLETA5 (BACKGROUND_BLUE|\
BACKGROUND_RED)	        	        

#endif


#endif