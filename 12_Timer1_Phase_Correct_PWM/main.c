/*
 * Project_Name    :   Timer1_Phase_Correct_PWM
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>




void Init_Timer1_PhaseCorrectPWM (void);


int main (void) {

	DDRC |= (1 << 0);
	DDRD |= (1 << 5);
	Init_Timer1_PhaseCorrectPWM();

	for (;;) {

		if (PIND & (1 << 5))
			PORTC = 0x01;
		else
			PORTC = 0x00;
	}

	return 0;
}


void Init_Timer1_PhaseCorrectPWM (void) {

	TCNT1   = 0x00;
	TCCR1A |= (1 << COM1A1) | (1 << WGM10);
	TCCR1B |= (1 << CS11)   | (1 << CS10);
	OCR1AH  = 0x00;
	OCR1AL  = 0x7F;
}
