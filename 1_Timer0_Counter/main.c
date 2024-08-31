/*
 * Project_Name    :   Timer0_Counter
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>



uint8_t Counter = 0;


int main (void) {

	DDRB  = 0x00;
	DDRC  = 0xFF;
	PORTB = 0xFF;

	TCCR0A = 0x00;
	TCCR0B |= (1 << CS02) | (1 << CS01);
	TCNT0 = 0x00;

	for (;;) {

		Counter = TCNT0;
		if (Counter == 10)
			PORTC = 0x01;
		else
			PORTC = 0x00;
		if (TCNT0 > 10) {
			Counter = 0;
			TCNT0   = 0;
		}
	}

	return 0;
}
