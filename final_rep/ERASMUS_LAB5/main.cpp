#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "hd44780/HD44780.hpp"
#include "uartLib/uart.hpp"

//#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR  F_CPU/16/BAUD-1

int main (){
	//uint8_t i=0;
		char str[12];
		// LEDS CONTROLLER
		DDRB |= ((1 << DDB2) | (1 << DDB3) | (1 << DDB4) | (1 << DDB5)); // Direction of port line (1 - output)
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5); // Output register (1 - do not light)
		// BUTTONS CONTROLLER
		DDRD &= ~(1<<DDD0) | ~(1<<DDD1) | ~(1<<DDD2) | ~(1<<DDD3); // Direction of port line (0 - input)
		LCD_Initalize();
		int i=0;
		for(;;){
			if (!(PIND & 1<<PIND3)){

				if(i<=15){
					sprintf(str, "sprintf: %d", i);
					LCD_GoTo(0,0);
					LCD_WriteText(str);
					PORTB = PORTB-1;

					_delay_ms(1000);
					i = i+1;
				}
				else{
					LCD_Clear();
					i=0;
					sprintf(str, "sprintf: %d", i);
					LCD_GoTo(0,0);
					LCD_WriteText(str);
					PORTB = PORTB-1;

					_delay_ms(1000);
					i = i+1;
				}

			}
			else if (!(PIND & 1<<PIND2)){

				if(i>=0){
					sprintf(str, "sprintf: %d", i);
					LCD_GoTo(0,0);
					LCD_WriteText(str);
					PORTB = PORTB-1;
					_delay_ms(1000);
					i = i-1;
				}
				else if(i==9){
					LCD_Clear();
					sprintf(str, "sprintf: %d", i);
					LCD_GoTo(0,0);
					LCD_WriteText(str);
					PORTB = PORTB-1;
					_delay_ms(1000);
					i = i-1;
				}
				else{
					LCD_Clear();
					i=15;
					sprintf(str, "sprintf: %d", i);
					LCD_GoTo(0,0);
					LCD_WriteText(str);
					PORTB = PORTB-1;
					_delay_ms(1000);
					i = i-1;
				}

			}
			else if (!(PIND & 1<<PIND1)){
				i=0;
				PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
			}
			else if (!(PIND & 1<<PIND0)){
				sprintf(str, "sprintf: %d", i);
				USART_Transmit_String(str);
			}
			 // 5. Clear screen
			else {
				LCD_Clear();
			}
	 }
}
