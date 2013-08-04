#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

#define BLINK_DELAY_MS  1000

/* Clock Frequency is 16Mhz. Prescaler is /1024. Interrupt every 0xff. 
 * Interrupt frequency is 61 hz..? */

volatile int timer;
ISR(TIMER0_OVF_vect){

	//toggle the state of the LED
	timer++;
	if(timer==120){
		PORTB ^= _BV(PORTB5);
		timer=0;
	}

}

int main (void)
{
	timer=0;
	/* set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5);
	// set global interrupts
	sei();
	// init the timer to use the prescaler /1024
	TCCR0B |= 0x05;
	// TCNT0 // timer reg
	TIMSK0 |= _BV(TOIE0);
	while(1);


	return 0;
}
