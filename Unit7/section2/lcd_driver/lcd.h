/*
 * lcd.h
 *
 * Created: 3/27/2023 3:15:39 AM
 *  Author: Muhand
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

//definitions
#define lcd_port				PORTA
#define data_dir_lcd_port		DDRA
#define data_shift				0 //0 for 8 bit data mode / 4 for 4 bit data mode
#define lcd_control				PORTB
#define data_dir_lcd_control	DDRB
#define en_switch				3
#define rw_switch				2
#define rs_switch				1

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

//commands
#define LCD_REGISTER_SELECT_PIN						(0)
#define LCD_READ_WRITE_PIN							(1)
#define LCD_ENABLE_PIN								(2)
#define LCD_REGISTER_SELECT_ENABLE					(1)
#define LCD_REGISTER_SELECT_DISABLE					(0)
#define READ_FROM_LCD								(1)
#define WRITE_TO_LCD								(0)
#define LCD_ENABLE									(1)
#define LCD_DISABLE									(0)
#define LCD_FIRST_LINE								(0)
#define LCD_SECOND_LINE								(1)
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

//apis
void lcd_check_isbusy(void);
void lcd_kick(void); // enable and disable lcd
void lcd_send_command(unsigned char command);
void lcd_send_char(unsigned char character);
void lcd_send_string(char* string);
void lcd_init(void);
void lcd_clear_screen();
void lcd_gotoXY(unsigned char line,unsigned char position);



#endif /* LCD_H_ */