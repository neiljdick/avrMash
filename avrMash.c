#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "interrupts.h"


/* Clock Frequency is 16Mhz. Prescaler is /1024. Interrupt every 0xff. 
 * Interrupt frequency is 61 hz..? */


int main (void)
{
	/* set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5);
	// set global interrupts
	sei();

	// set up the heart beat
	// init the timer to use the prescaler /1024
	TCCR0B |= 0x05;
	// TCNT0 // timer reg
	// enable the interrupt for overflow
	TIMSK0 |= _BV(TOIE0);


	initLCD();
	while(1);


	return 0;
}
