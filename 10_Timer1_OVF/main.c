/*
 * Project_Name    :   Timer1_OVF
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void Init_Timer1_OVF (void);
ISR (TIMER1_OVF_vect);


int main (void) {

	DDRB = 0xFF;
	Init_Timer1_OVF();

	for (;;) {

		PORTB = 0x00;
	}

	return 0;
}


ISR (TIMER1_OVF_vect) {

	while (1) {

		PORTB = 0x03;
		_delay_ms (1000);
		PORTB = 0x00;
		_delay_ms (1000);
	}
}


void Init_Timer1_OVF (void) {

	TCCR1A = 0x00;
	TCCR1B = (1 << CS11) | (1 << CS10);
	TIMSK1 |= (1 << TOIE1);
    sei ();
}






