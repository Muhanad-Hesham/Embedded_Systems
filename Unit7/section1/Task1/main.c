/*
 * section1.c
 *
 * Created: 3/23/2023 2:13:47 PM
 * Author : Muhand
 */ 
/*
#include <avr/io.h>
*/

#define F_CPU	8000000UL 
#include <util/delay.h>
#define SETBIT(reg,bit)	(reg |= (1<<bit))
#define CLEARBIT(reg,bit)	(reg &= ~(1<<bit))
#define READBIT(reg,bit)	((reg >> bit) & 1)
#define TOGGLEBIT(reg,bit)	(reg ^= (1<<bit))

#define PORTA	*(volatile unsigned char*) (0x3B)
#define DDRA	*(volatile unsigned char*) (0x3A)
#define PINA	*(volatile unsigned char*) (0x39)

#define PORTB	*(volatile unsigned char*) (0x38)
#define DDRB	*(volatile unsigned char*) (0x37)
#define PINB	*(volatile unsigned char*) (0x36)	

#define PORTC	*(volatile unsigned char*) (0x35)
#define DDRC	*(volatile unsigned char*) (0x34)
#define PINC	*(volatile unsigned char*) (0x33)	

#define PORTD	*(volatile unsigned char*) (0x32)
#define DDRD	*(volatile unsigned char*) (0x31)
#define PIND	*(volatile unsigned char*) (0x30)




int main(void)
{
	//PORTD0 input
	CLEARBIT(DDRD,0);
	//PORTD4,5,6,7 output
	SETBIT(DDRD,4);
	SETBIT(DDRD,5);
	SETBIT(DDRD,6);
	SETBIT(DDRD,7);
    /* Replace with your application code */
    while (1) 
    {
		int i,j;
		
			for(i=5;i<8;i++)
			{
				while(READBIT(PIND,0) == 0);
				if(READBIT(PIND,0) == 1)
				SETBIT(PORTD,i);
				_delay_ms(500);
			}
		SETBIT(PORTD,4);
		_delay_ms(500);	
		CLEARBIT(PORTD,4);
		for(j=7;j>4;j--)
		{
			while(READBIT(PIND,0) == 0);
			if(READBIT(PIND,0) == 1)
			CLEARBIT(PORTD,j);
			_delay_ms(500);
		}
		SETBIT(PORTD,4);
		
    }
}


