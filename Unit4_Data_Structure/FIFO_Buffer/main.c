/*
 * main.c
 *
 *  Created on: Jan 16, 2023
 *      Author: Muhand
 */
/*
#include "stdio.h"
#include "fifo.h"
void main()
{
	fifo_buf_t fifo_uart; int i; int temp=0;
	if(fifo_buffer_init(&fifo_uart,uart_buffer,5) == fifo_no_error)
		printf("fifo init-------- done successfully\n");

	for(i=0;i<7;i++){
		printf("fifo enqueue (%x) \n",i);
		if(fifo_buffer_enqueue(&fifo_uart,i) == fifo_no_error)
			printf("fifo enqueue -------- done successfully\n");
		else
			printf("fifo enqueue -------- failed\n");
	}

	fifo_print(&fifo_uart); // test by displaying the buffer

	if(fifo_buffer_dequeue(&fifo_uart,&temp) == fifo_no_error)
		printf("fifo dequeue (%X)-------- done successfully\n",temp);
	if(fifo_buffer_dequeue(&fifo_uart,&temp) == fifo_no_error)
		printf("fifo dequeue (%X)-------- done successfully\n",temp);

	fifo_print(&fifo_uart); // test by displaying the buffer
}
*/

#include "fifo.h"
void main()
{
	element_type i, temp;
	fifo_buff_t uart_fifo;
	if(fifo_init(&uart_fifo,uart_fifo_buff,5)==fifo_no_error)
		printf("===fifo init is done===\n");
	else
		printf("===fifo init failed===\n");

	for(i=0 ; i<7 ; i++)
	{
		if(fifo_enqueue(&uart_fifo,i)==fifo_no_error)
			printf("===fifo_enqueue add (%x)===\n===fifo_enqueue add successfully===\n",i);
		else
			printf("===fifo_enqueue add (%x)===\n===fifo_enqueue add failed===\n",i);
	}

	fifo_print(&uart_fifo); //test by displaying the buffer

	if(fifo_dequeue(&uart_fifo,&temp)==fifo_no_error)
		printf("===fifo_dequeue get (%x)===\n",temp);
	if(fifo_dequeue(&uart_fifo,&temp)==fifo_no_error)
		printf("===fifo_dequeue get (%x)===\n",temp);

	fifo_print(&uart_fifo); //test by displaying the buffer
	printf("====And Thank you====");


}
