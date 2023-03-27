/*
 * keypad.h
 *
 * Created: 3/27/2023 5:56:57 AM
 *  Author: Muhand
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

//keypad information

#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define C0	4
#define C1	5
#define C2	6
#define C3	7
#define keypad_port PORTD
#define keypad_pin	PIND
#define keypadDDR	DDRD

void keypad_init();
char keypad_getkey();

#endif /* KEYPAD_H_ */