/*
 * fifo.h
 *
 *  Created on: Jan 16, 2023
 *      Author: Muhand
 */

#ifndef FIFO_H_
#define FIFO_H_
/*
#include "stdio.h"
#include "stdint.h"
// configuration
// select the element type( uint8_t, uint16_t, uint32_t,...)
#define element_type unsigned char

//create buffer
#define width 5 // select length of the buffer
element_type uart_buffer[width];


//datatype definition of the fifo buffer
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type* head;
	element_type* tail;
	element_type* base;
}fifo_buf_t;

//enum for status of the buffer
typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
}fifo_status;


//APIs
fifo_status fifo_buffer_init(fifo_buf_t* fifo,element_type* buf,unsigned int length);
fifo_status fifo_buffer_enqueue(fifo_buf_t* fifo,element_type item);
fifo_status fifo_buffer_dequeue(fifo_buf_t* fifo,element_type* item );
fifo_status fifo_is_full(fifo_buf_t* fifo);
void fifo_print(fifo_buf_t* fifo);
*/


#include "stdio.h"
#include "stdint.h"

//Generic FIFO Buffer

#define element_type uint8_t  //choose your element type in your fifo (uint8_t ,uint16_t ,uint32_t,...)

#define width 5 // number of elements in your fifo you can change

element_type uart_fifo_buff[width]; // Global Buffer

//Definitions
typedef struct{
	unsigned int count;
	unsigned int length;
	element_type* base;
	element_type* head;
	element_type* tail;

}fifo_buff_t;

typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null,
}fifo_status_buff_t;

//APIs
fifo_status_buff_t fifo_init(fifo_buff_t* fifo, element_type* buff, unsigned int length);
fifo_status_buff_t fifo_enqueue(fifo_buff_t* fifo, element_type item);
fifo_status_buff_t fifo_dequeue(fifo_buff_t* fifo, element_type* item);
fifo_status_buff_t fifo_is_full(fifo_buff_t* fifo);
fifo_status_buff_t fifo_is_empty(fifo_buff_t* fifo);
void fifo_print(fifo_buff_t* fifo);


#endif /* FIFO_H_ */
