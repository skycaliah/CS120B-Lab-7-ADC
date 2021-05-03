/*	Author: lab
 *  Partner(s) Name:Skyler Saltos 
 *	Lab Section: 022
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	This exercise has use use a photoresistor to check when to light up a LED given 
 *	enought light is shown from a MAX value determined in EX. 2
 *
 *	Use 8 LEDs to incrementally light up depending on the amount of light the photoresistor is exposed to.
 *
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	
*	UPDATE: Due to working on lab in different time of day, the room lighting changed thus shifting 
*	the value of my MAX, after attempting to revaulate, my MAX value became larger due to factors 
*	such as room lighting and use of different flashlight due to dead batteries. 
 *	https://youtu.be/uBcewg6ON0Q
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

	int MAX = 0x300;//max value from light in room hitting photoresistor

//	int lightThreshold = MAX / 2; //value used to determine if LED should light 

	int currLimit; // variable to hold the current numeric threshold needed to light the next LED in 
		       // in increments of 39 based of our estiamted max

	int upperLimit; //holds upper valued to ensure light intensity within range to light LEDs

	int ledThreshold = MAX / 8;
    /* Insert your solution below */
    while (1) {
		
	unsigned short lightInput = ADC; // value of ADC register stored inside light  variable - 10 bit value
	currLimit = 0;
	upperLimit = currLimit + ledThreshold;

	if( lightInput <= upperLimit && lightInput > currLimit ) {

		PORTB = 0x01;

	}//enought light for first LED

	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;


	
	if (lightInput >= currLimit && lightInput <= upperLimit){
	
		PORTB = 0x03;


	}//enough light for 2 LEDs

	
	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;

	if ( lightInput >= currLimit && lightInput <= upperLimit ) {

		PORTB = 0x07;

	}//enought light for 3 LEDs

	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;

	if( lightInput >= currLimit && lightInput <= upperLimit){


		PORTB = 0x0F;
	}//endough light for 4 leds


	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;


	if ( lightInput >= currLimit && lightInput <= upperLimit ){

		PORTB = 0x1F;

	}//endough light for 5 leds


	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;


	if( lightInput >= currLimit && lightInput <= upperLimit){


		PORTB = 0x3F;

	}//end enought light for 6 leds




	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;

	if( lightInput >= currLimit && lightInput <= upperLimit){

		PORTB = 0x7F;

	}//end enought light for 7 leds


	currLimit = upperLimit;
	upperLimit = upperLimit + ledThreshold;

	if( lightInput >= currLimit && lightInput <= upperLimit){

	PORTB = 0xFF;

	}//end enought light for 8 leds on










    }
    return 1;
}
