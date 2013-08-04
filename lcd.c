#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

void byteCmd(int cmd){
	// clear RS
	PORTB &= ~RS;
	// clear E 
	PORTB &= ~E;
	PORTB |= E;
	// clear the top nibble
	PORTD &= 0x0f;
	PORTD |= (cmd<<4)&0xf0;
	// toggle the E bit high
	PORTB &= ~E;

	return;
}




int writeLcdCmd(int cmd){
	// clear RS
	PORTB &= ~RS;
	// clear E 
	PORTB &= ~E;
	//set E
	PORTB |= E;
	// clear the top nibble
	PORTD &= 0x0f;
	// write the data nibble
	PORTD |= (cmd)&0xf0;
	PORTB &= ~E;
	PORTB |= E;
	PORTD &= 0x0f;
	PORTD |= (cmd<<4)&0xf0;
	// toggle the E bit high
	PORTB &= ~E;

	return 0;
}

int writeLcdData(int data){
	// clear E 
	PORTB &= ~E;
	PORTB |= E;

	// set RS
	PORTB |= RS;

	// clear the top nibble
	PORTD &= 0x0f;
	// write the data nibble
	PORTD |= (data)&0xf0;
	PORTB &= ~E;
	PORTB |= E;
	PORTD &= 0x0f;
	PORTD |= (data<<4)&0xf0;
	// toggle the E bit high
	PORTB &= ~E;

	_delay_us(50);
	return 0;
}
void clearScreen(void){
	writeLcdCmd(0x01);
	_delay_us(50);
}

int initLCD(void){
	/* Set the GPIO Pins required to Output! */
	DDRB |= (RS | E);
	DDRD |= DATA_PINS;

	PORTD &= ~DATA_PINS;
	PORTB &= ~(RS | E);

	_delay_ms(100);
	byteCmd(0x03);
	_delay_ms(5);
	writeLcdCmd(0x28);
	_delay_us(50);
	writeLcdCmd(0x28);
	_delay_us(50);
	writeLcdCmd(0x0c);
	_delay_us(50);
	writeLcdCmd(0x01);
	_delay_us(50);
	writeLcdCmd(0x06);
	_delay_ms(100);


	writeLcdData('H');
	writeLcdData('e');
	writeLcdData('l');
	writeLcdData('l');
	writeLcdData('o');

	writeLcdData(' ');
	
	writeLcdData('f');
	writeLcdData('u');
	writeLcdData('c');
	writeLcdData('k');
	writeLcdData('e');
	writeLcdData('r');
	writeLcdData('s');
	
	
	return 0;
}

