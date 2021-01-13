/*
 * Template of program with configuration of LCD screen with HD4470 driver
 * Pawel Krol - Politechnika Krakowska - 2019/2020
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include "hd44780/hd44780.hpp"

int main (void){

    LCD_Initalize();

    while(1){
        LCD_Clear();
        LCD_GoTo(2,0);
        LCD_WriteText("PAWEL KROL");
        LCD_GoTo(0,1);
        LCD_WriteText("KRAKOW 2019/2020");
        _delay_ms(500);

    }
}
