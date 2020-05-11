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

//Demo: https://drive.google.com/open?id=1E_NgGes2qd4v3qVzwBGx5fXAmU32A1TK

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	unsigned short value = 0x00;
	unsigned short MAX = 288; //change accordingly
	ADC_init();
	while (1) {
		value = ADC;
		if(value >= (MAX/2)) {PORTB = 0x01;}
		else {PORTB = 0x00;}
    	}
   	return 1;
}
