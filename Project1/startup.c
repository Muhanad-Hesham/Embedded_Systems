/*
 * startup.c
 *
 *  Created on: Feb 28, 2023
 *      Author: Muhand
 */

#include "stdint.h"

void reset_handler(void);
extern void main();

void default_handler()
{
	reset_handler();
}

void NMI_handler(void) __attribute__((weak,alias("default_handler")));;

void H_fault_handler(void) __attribute__((weak,alias("default_handler")));;

void MM_fault_handler(void) __attribute__((weak,alias("default_handler")));;

void Bus_fault(void) __attribute__((weak,alias("default_handler")));;

void Usage_fault_handler(void) __attribute__((weak,alias("default_handler")));;

extern uint32_t _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &_stack_top,
(uint32_t) &reset_handler,
(uint32_t) &NMI_handler,
(uint32_t) &H_fault_handler,
(uint32_t) &MM_fault_handler,
(uint32_t) &Bus_fault,
(uint32_t) &Usage_fault_handler
};

extern unsigned int _E_text;
extern unsigned int _s_data;
extern unsigned int _E_data;
extern unsigned int _s_bss;
extern unsigned int _E_bss;


void reset_handler(void)
{
unsigned int data_size =  (unsigned char*)&_E_data - (unsigned char*)&_s_data;
unsigned char* p_src = (unsigned char*)&_E_text;
unsigned char* p_dst = (unsigned char*)&_s_data;
int i=0;
for ( i ; i < data_size ; i++)
{
	*((unsigned char*)p_dst++) = *((unsigned char*)p_src++);
}

//init the .bss with zero
unsigned int bss_size =  (unsigned char*)&_E_bss - (unsigned char*)&_s_bss;
p_dst = (unsigned char*)&_s_bss;
for ( i ; i < bss_size ; i++)
{
	*((unsigned char*)p_dst++) = (unsigned char)0;
}
  main();
}
