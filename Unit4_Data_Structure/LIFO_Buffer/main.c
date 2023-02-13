/*
 * main.c
 *
 *  Created on: Jan 15, 2023
 *      Author: Muhand
 */


#include "stdio.h"
#include "stdlib.h"
#include "lifo.h"

unsigned int buffer1[5]; //5*4=20 bytes in bss as unintialized variable
void main()
{
	unsigned int i; unsigned int temp = 0; //(1)

	lifo_buff_t uart_buff , I2c_buff;
	lifo_init(&uart_buff,buffer1,5);
	//dynamic allocation for another buffer or array
	unsigned int* buffer2 = (unsigned int*) malloc (5*sizeof(unsigned int)); // dynamic 5*4=20 bytes in heap
	lifo_init(&I2c_buff,buffer2,5);

	for(i=0;i<5;i++)
	{
		if(lifo_add_item(&uart_buff,i)==lifo_no_error)
			printf("uart_buff add = %d\n",i);

	}
	for(i=0;i<5;i++)
		{
			if(lifo_get_item(&uart_buff,&temp)==lifo_no_error)
				printf("uart_buff get = %d\n",temp);


		}



}



