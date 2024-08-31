/*
 * Project_Name    :   Timer1_Delay
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>




void Timer1_delay (void);


int main (void) {

	DDRC = 0xFF;

	for (;;) {

		PORTC= 0x01;
		Timer1_delay();
		PORTC= 0x00;
		Timer1_delay();

	}

	return 0;
}

void Timer1_delay (void) {

	TCNT1H  = 0xF7;
	TCNT1L  = 0xD8;
	TCCR1A  = 0x00;
	TCCR1B  = 0x02;
	while((TIFR1 & 0x01) == 0);
	TCCR1B  = 0x00;
	TIFR1   = 0x01;
}
