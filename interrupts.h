#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include <avr/io.h>
#include <avr/interrupt.h>

/* Interrupt vector for timer 0 
 */
#define BEAT_FREQ 60
ISR(TIMER0_OVF_vect);

#endif
