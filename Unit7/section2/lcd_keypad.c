/*
 * lcd_keypad_drivers.c
 *
 * Created: 3/27/2023 3:08:24 AM
 * Author : Muhand
 */ 

#include <avr/io.h>
#include "lcd_driver/lcd.h"
#include "keypad_driver/keypad.h"
int main(void)
{
	lcd_init();
	keypad_init();
	char pressed_key;
    /* Replace with your application code */
    while (1) 
    {
		pressed_key = keypad_getkey();
		switch(pressed_key)
		{
			case '?' :
			lcd_clear_screen();
			break;
			case 'N' :
			break;
			default :
			lcd_send_char(pressed_key);
		}
			
    }
}

