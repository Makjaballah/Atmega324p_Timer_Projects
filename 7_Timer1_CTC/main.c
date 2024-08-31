/*
 * Project_Name    :   Timer1_CTC
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void Init_Timer1_CTC (void);
ISR (TIMER1_COMPA_vect);


int main (void) {

	DDRB  = 0xFF;
	Init_Timer1_CTC();
	uint16_t Freq = 30;
	OCR1A = (F_CPU/ (2*256*Freq))-1;

	for (;;) {

	}

	return 0;
}

ISR (TIMER1_COMPA_vect) {

	PINB |= (1 << 0);
}

void Init_Timer1_CTC (void) {

	TCCR1A = 0x00;
	TCCR1B |= (1 << WGM12) | (1 << CS12);
	TIMSK1 |= (1 << OCIE1A);
	sei ();
}
