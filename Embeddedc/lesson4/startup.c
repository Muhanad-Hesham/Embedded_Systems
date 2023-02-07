
/* startup.c
Eng. Muhand
*/

#include "stdint.h"

void reset_handler(void);
extern int main(void);


void default_handler()
{
	reset_handler();
}
void NMI_handler(void) __attribute__((weak,alias("default_handler")));;

void H_fault_handler(void) __attribute__((weak,alias("default_handler")));;

void MM_fault_handler(void) __attribute__((weak,alias("default_handler")));;

void Bus_fault(void) __attribute__((weak,alias("default_handler")));;

void Usage_fault_handler(void) __attribute__((weak,alias("default_handler")));;

//reserve stack size 
static unsigned long stack_top[256]; // 256*4 1024 bytes ************
//**********************


void (* const g_p_func_vectors[])() __attribute__((section(".vectors"))) = 
{
   (void(*)()) ((unsigned long)stack_top + sizeof(stack_top)),
   &reset_handler,
   &NMI_handler,
   &H_fault_handler,
   &MM_fault_handler,
   &Bus_fault,
   &Usage_fault_handler 
};



extern unsigned int _E_text;
extern unsigned int _s_data;
extern unsigned int _E_data;
extern unsigned int _s_bss;
extern unsigned int _E_bss;
 
//copy data from rom to ram


	
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