/*
 * Project_Name    :   Timer1_COMP
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR (TIMER1_COMPA_vect);
void Timer1_Freq (uint16_t Freq);


int main (void) {

	DDRB |= (1 << 0);
	Timer1_Freq (30);

	for (;;) {

	}

	return 0 ;
}


ISR (TIMER1_COMPA_vect) {

	PINB |= (1 << 0);
}

void Timer1_Freq(uint16_t Freq) {

	TCCR1A = 0x00;
	TCCR1B = (1 << WGM12) | (1 << CS12);
	TIMSK1 |= (1 << OCIE1A);
	OCR1A = (F_CPU/(2*256*Freq))-1;
	sei ();
}











