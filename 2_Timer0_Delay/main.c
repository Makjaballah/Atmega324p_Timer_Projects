/*
 * Project_Name    :   Timer0_Delay
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>



void Timer0_delay (void);


int main (void) {

	DDRC = 0xFF;

	for (;;) {

		PORTC= 0x01;
		Timer0_delay();
		PORTC= 0x00;
		Timer0_delay();
	}

	return 0;
}

void Timer0_delay (void) {

	TCNT0  = 0x00;
	TCCR0A = 0x00;
	TCCR0B = 0x05;
	while((TIFR0 & 0x01) == 0);
	TCCR0B = 0x00;
	TIFR0  = 0x01;
}
