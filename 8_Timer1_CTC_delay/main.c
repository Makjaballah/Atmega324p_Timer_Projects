/*
 * Project_Name    :   Timer1_CTC_delay
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>



void Timer1_CTC_delay (void);


int main (void) {

	DDRC = 0xFF;

	for (;;) {

		PORTC= 0x01;
		Timer1_CTC_delay();
		PORTC= 0x00;
		Timer1_CTC_delay();
	}

	return 0;
}

void Timer1_CTC_delay (void) {

	TCNT1H  = 0x00;
	TCNT1L  = 0x00;
	OCR1AH  = 0x0E;
	OCR1AL  = 0xA7;
	TCCR1A  = 0x00;
	TCCR1B  = (1 << WGM12) | (1 << CS11);
	while((TIFR1 & 0x02) == 0);
	TCCR1B  = 0x00;
	TIFR1   = 0x02;
}
