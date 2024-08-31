/*
 * Project_Name    :   Timer0_Phase_Correct_PWM
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <avr/delay.h>



int main (void) {

	DDRB   |= (1 << 3);
	DDRC   |= (1 << 0);

	TCCR0B |= (1 << CS01) | (1 << CS00);
	TCCR0A |= (1 << WGM00);
	TCCR0A |= (1 << COM0A1) ;

	TCNT0 = 0x00;
	OCR0A = 127;

	for (;;) {

		if (PINB & (1 << 3))
			PORTC = 0x01;
		else
			PORTC = 0x00;
	}

	return 0;
}
