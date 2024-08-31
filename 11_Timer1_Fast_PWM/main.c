/*
 * Project_Name    :   Timer1_Fast_PWM
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>




void Init_FastPWM (void);

int main (void) {

	DDRC |= (1 << 0);
	DDRD |= (1 << 5);

	Init_FastPWM();

	for (;;) {

		if (PIND & (1 << 5))
			PORTC = 0x01;
		else
			PORTC = 0x00;
	}

	return 0;
}


void Init_FastPWM (void) {

	TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
	TCCR1B |= (1 << CS10)   | (1 << WGM12);
	TCNT1   = 0x0000;
	OCR1AH  = 0x02;
	OCR1AL  = 0x66;
}






