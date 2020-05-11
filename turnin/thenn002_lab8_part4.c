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
	unsigned char temp;
	ADC_init();
	unsigned short partition = MAX/8;
	while (1) {
		value = ADC;
		temp = 0x00;
		if(value >= (partition*1)) {temp = temp | 0x01;}
		if(value >= (partition*2)) {temp = temp | 0x02;}
		if(value >= (partition*3)) {temp = temp | 0x04;}
		if(value >= (partition*4)) {temp = temp | 0x08;}
		if(value >= (partition*5)) {temp = temp | 0x10;}
		if(value >= (partition*6)) {temp = temp | 0x20;}
		if(value >= (partition*7)) {temp = temp | 0x40;}
		if(value >= (partition*8)) {temp = temp | 0x80;}
		PORTB = temp;
    	}
   	return 1;
}
