/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char MAX = 0xFF;
unsigned char levels = 0x00;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	//ADEN: setting this bit enables analog-to-digital conversion
	//ADSC: setting this bit starts the first conversion.
	//ADATE: setting this bit enables auto-triggering. Since we are in
			// Free Running Mode, a new conversion will trigger whenever the previous conversion completes
}

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	
	while(1) {
		unsigned short my_short = ADC;
		levels = MAX / 8;
		
		if (my_short <= levels) {
			PORTB = 0x01;
		} else if (my_short <= (levels * 2)) {
			PORTB = 0x03;
		} else if (my_short <= (levels * 3)) {
			PORTB = 0x07;
		} else if (my_short <= (levels * 4)) {
			PORTB = 0x0F;
		} else if (my_short <= (levels * 5)) {
			PORTB = 0x1F;
		} else if (my_short <= (levels * 6)) {
			PORTB = 0x3F;
		} else if (my_short <= (levels * 7)) {
			PORTB = 0x7F;
		} else if (my_short <= (levels * 8)) {
			PORTB = 0xFF;
		}
		
	} 
	return 1;

}
