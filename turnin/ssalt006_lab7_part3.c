/*	Author: lab
 *  Partner(s) Name:Skyler Saltos 
 *	Lab Section: 022
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	This exercise has use use a photoresistor to check when to light up a LED given 
 *	enought light is shown from a MAX value determined in EX. 2
 *
 *
 *	Explanation for determining max discussed at end of video but to summarize, 
 *	I chose the value given when the photoresistor was exposed to the light of my room
 *	and used half that value as it was most accurate in not being too large or too small.
 *	I attempted to use the MAX given when shining the flashlight from ex. 2  but that value was much 
 *	too large for the photoresistor to react to normal room lighting. 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *
 *	https://youtu.be/djnqSLlmX5g
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

	int MAX = 0x0FF;//max value from light in room hitting photoresistor

	int lightThreshold = MAX / 2; //value used to determine if LED should light 

    /* Insert your solution below */
    while (1) {
		
	unsigned short lightInput = ADC; // value of ADC register stored inside light  variable - 10 bit value

	if ( lightInput >= lightThreshold ) {

		PORTB = 0x01;

	}//enought light to turn on LED


	else if ( lightInput < lightThreshold ) {



		PORTB = 0x00;

	}//not enought light, do not illuminate
	

	



    }
    return 1;
}
