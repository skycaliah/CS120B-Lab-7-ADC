/*	Author: lab
 *  Partner(s) Name:Skyler Saltos 
 *	Lab Section: 022
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 * 	In this Excercise we have 10 Leds connected to PORTB and PORTD ( 8 on B and 2 on D ) 
 * 	to represent a 10 Bit number that is the voltage ouput from a potentiometer that we store in a 
 * 	a2d variable and output on the ports. 
 *
 *
 *
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *
 *
 *	https://youtu.be/zKhjHuvvS3Q
 */


#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) ;


}//end initializtion for analog to digital conversion

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF; //Inputs

	DDRB = 0xFF;	PORTB = 0x00; //Outputs
	DDRD = 0xFF; 	PORTD = 0x00; 


	//call initialization to Analog -> Digital for microcontroller
	ADC_init();


	unsigned char temp; //temp variable used to hold value of shifted and casted a2d to write to ports 

    /* Insert your solution below */
    while (1) {
		
	unsigned short a2d = ADC; // value of ADC register stored inside a2d variable - 10 bit value

	//Want temp to hold last 8 bits in a2d
	temp = (char)a2d; // gets last 8 bits inside a2s
	PORTB = temp;


	temp = (a2d >> 8 ); // shift a2d to right by 8 to get upper 2 bits into the right most place

	PORTD = temp; // assign last 2 bits of a2d to PORTD 
	

	



    }
    return 1;
}
