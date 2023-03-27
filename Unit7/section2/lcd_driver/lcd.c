/*
 * lcd.c
 *
 * Created: 3/27/2023 3:15:26 AM
 *  Author: Muhand
 */ 
#include "lcd.h"
void lcd_init(void)
{
	_delay_ms(20);
	//potrB output
	data_dir_lcd_control |= (1<<en_switch | 1<<rw_switch | 1<<rs_switch);
	//portB zero volt
	lcd_control &= ~(1<<en_switch | 1<<rw_switch | 1<<rs_switch);
	data_dir_lcd_port = 0xff;
	_delay_ms(15);
	lcd_clear_screen();
	
	#ifdef EIGHT_BIT_MODE
	lcd_send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	lcd_send_command(0x02);
	lcd_send_command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	lcd_send_command(LCD_ENTRY_MODE);
	lcd_send_command(LCD_BEGIN_AT_FIRST_RAW);
	lcd_send_command(LCD_DISP_ON_CURSOR_BLINK);
}
void lcd_clear_screen()
{
	lcd_send_command(LCD_CLEAR_SCREEN);
}
void lcd_check_isbusy(void)
{
	data_dir_lcd_port &= ~(0xff<<data_shift);
	lcd_control |= (1<<rw_switch);
	lcd_control &= ~(1<<rs_switch);
	lcd_kick();
	data_dir_lcd_port |= 0xff;
	lcd_control &= ~(1<<rw_switch);
}
// enable and disable lcd
void lcd_kick(void)
{	//to not interrupt lcd
	lcd_control &= ~(1<<en_switch);
	_delay_ms(50);
	lcd_control |= (1<<en_switch);
}
void lcd_send_command(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
	lcd_check_isbusy();
	lcd_port = command;
	lcd_control &= ~(1<<rw_switch | 1<<rs_switch);
	lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	lcd_check_isbusy();
	lcd_port = ((lcd_port & 0x0f) | (command & 0xf0));
	lcd_control &= ~(1<<rw_switch | 1<<rs_switch);
	lcd_kick();
	lcd_port = ((lcd_port & 0xf0) | (command << 4));
	lcd_control &= ~(1<<rw_switch | 1<<rs_switch);
	lcd_kick();
	
	#endif
}
void lcd_send_char(unsigned char character)
{
	#ifdef EIGHT_BIT_MODE
	lcd_check_isbusy();
	lcd_port = character;
	lcd_control &= ~(1<<rw_switch);
	lcd_control |= (1<<rs_switch);
	lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	lcd_port = (lcd_port & 0x0f | character & 0xf0);
	lcd_control &= ~(1<<rw_switch);
	lcd_control |= (1<<rs_switch);
	lcd_kick();
	lcd_port = (lcd_port & 0xfo | character << 4);
	lcd_control &= ~(1<<rw_switch);
	lcd_control |= (1<<rs_switch);
	lcd_kick();
	
	#endif
}
void lcd_send_string(char* string)
{
	int count =0; //to count how much char on the line (should be 16 only)
	while(*string>0)
	{
		count++;
		lcd_send_char(*string++);
		if(count==16) //go to second line
		lcd_gotoXY(1,0);
		else if(count==32 || count==33)	//clear screen and show again
		{
			lcd_clear_screen();
			lcd_gotoXY(0,0);
			count = 0;
		}
	}
	
}

void lcd_gotoXY(unsigned char line,unsigned char position)
{
	if(line==0)
	{
		if(position<16 && position>=0)
			lcd_send_command(LCD_BEGIN_AT_FIRST_RAW + position);
	}
	if(line==1)
	{
		if(position<16 && position>=0)
		lcd_send_command(LCD_BEGIN_AT_SECOND_RAW + position);
	}
}
