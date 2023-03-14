/*
 * main.c
 *
 * Created: 3/14/2023 8:58:14 PM
 *  Author: Muhand
 */ 

#include <xc.h>
#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define set_bit(address,bit)     (address |= (1<<bit))
#define reset_bit(address,bit)   (address &= ~(1<<bit))
#define toggle_bit(address,bit)  (address ^= (1<<bit))
#define read_bit(address,bit)    ((address & (1<<bit))>>bit)

void GPIO_init()
{
	//Make portD direction output
	set_bit(DDRD,5);
	set_bit(DDRD,6);
	set_bit(DDRD,7);
	
}

void EXTI_init()
{
	//Global interrupt enable
	sei();
	//INT1 RISING
	set_bit(MCUCR,2);
	set_bit(MCUCR,3);
	//INT0 any logical change
	set_bit(MCUCR,0);
	reset_bit(MCUCR,1);
	//INT2 Falling
	reset_bit(MCUCSR,0);
	//External interrupt request enable
	set_bit(GICR,5);
	set_bit(GICR,6);
	set_bit(GICR,7);
	
}

int main(void)
{
    GPIO_init();
    EXTI_init();
    
    while(1)
    {
	    reset_bit(PORTD,5);
	    reset_bit(PORTD,6);
	    reset_bit(PORTD,7);
    }
}

ISR(INT0_vect)
{
	set_bit(PORTD,5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	set_bit(PORTD,6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	set_bit(PORTD,7);
	_delay_ms(1000);
}