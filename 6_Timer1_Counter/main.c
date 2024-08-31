/*
 * Project_Name    :   Timer1_Counter
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>



uint16_t Counter = 0;

int main (void) {

	DDRB  = 0x00;
	DDRC  = 0xFF;
	PORTB = 0xFF;

	TCCR1A = 0x00;
	TCCR1B |= (1 << CS12) | (1 << CS11)| (1 << CS10);

	for (;;) {

		Counter  = TCNT1H;
		Counter <<= 8;
		Counter +=  TCNT1L;

		if (Counter == 10)
			PORTC = 0x01;
		else
			PORTC = 0x00;

		if (TCNT1 > 10) {
			Counter = 0;
			TCNT1   = 0;
		}
	}

	return 0;
}
