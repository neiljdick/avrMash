#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupts.h"

/* Interrupt vector for timer 0 
 */
volatile int timer=0;
ISR(TIMER0_OVF_vect){
	//toggle the state of the LED
	timer++;
	if(timer==BEAT_FREQ){
		PORTB ^= _BV(PORTB5);
		timer=0;
	}
}
