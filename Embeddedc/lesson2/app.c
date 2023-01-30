#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth: honda ";

void main(void)
{
	 uart_send_string ( string_buffer);
}	
