/*
 * fifo.c
 *
 *  Created on: Jan 16, 2023
 *      Author: Muhand
 */
/*
#include "fifo.h"
#include "stdio.h"

//APIs
fifo_status fifo_buffer_init(fifo_buf_t* fifo,element_type* buf,unsigned int length)
{
	//fifo exist or not
	if(buf==NULL)
		return fifo_null;

	fifo->base= buf;
	fifo->head= buf;
	fifo->tail= buf;
	fifo->length= length;
	fifo->count= 0;
	return fifo_no_error;
}

fifo_status fifo_buffer_enqueue(fifo_buf_t* fifo,element_type item)
{
	// fifo exist or not
	if(!fifo->base||!fifo->head||!fifo->tail)
			return fifo_null;
	//fifo is full or not
	if (fifo_is_full(fifo) == fifo_full)
		return fifo_full;
	//add item
 *(fifo->head)=item;
	fifo->count++;
	//circular fifo
	if(fifo->head == (fifo->base + (fifo->length*sizeof(element_type))))
		fifo->head=fifo->base;
	else
		fifo->head++;
	return fifo_no_error;
}
fifo_status fifo_buffer_dequeue(fifo_buf_t* fifo,element_type* item )
{
	if(!fifo->base||!fifo->head||!fifo->tail)
				return fifo_null;
	//fifo is empty or not
	if(fifo->count==0)
		return fifo_empty;
	// get the item from the buffer (queue)
 *item=*(fifo->tail);
	fifo->count--;
	if(fifo->tail == (fifo->base + (fifo->length*sizeof(element_type))))
			fifo->tail=fifo->base;
		else
			fifo->tail++;
		return fifo_no_error;
}
fifo_status fifo_is_full(fifo_buf_t* fifo)
{
	if(!fifo->base||!fifo->head||!fifo->tail)
				return fifo_null;
	if(fifo->count == fifo->length)
		return fifo_full;
	else
		return fifo_no_error;
}
void fifo_print(fifo_buf_t* fifo)
{
	element_type* temp; // a pointer to not change in the main fifo
	int i;
	if(fifo->count==0)
		printf("fifo is empty\n");
	else
	{
		temp=fifo->tail;
		printf("\n ------ fifo print -----\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t %x \n",*temp);
			temp++;
		}
		printf("------ SHUKRAN------\n");

	}

}
 */

#include "fifo.h"
//APIs
fifo_status_buff_t fifo_init(fifo_buff_t* fifo, element_type* buff, unsigned int length)
{
	//if exist
	if(buff==NULL)
		return fifo_null;
	fifo->base   = buff;
	fifo->head   = buff;
	fifo->tail   = buff;
	fifo->length = length;
	fifo->count  = 0;
	return fifo_no_error;

}
fifo_status_buff_t fifo_enqueue(fifo_buff_t* fifo, element_type item)
{
	//if exist
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;

	//if full??
	if(fifo_is_full(fifo) == fifo_full)
		return fifo_full;

	//if not full
	*(fifo->head) = item;
	fifo->count++;

	//circular fifo
	if(fifo->head == (fifo->base + (fifo->length*sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;
	return fifo_no_error;


}
fifo_status_buff_t fifo_dequeue(fifo_buff_t* fifo, element_type* item)
{
	//if exist
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	//if empty??
	if(fifo_is_empty(fifo) == fifo_empty)
		return fifo_empty;
	//if not empty
	*item=*(fifo->tail);
	fifo->count--;

	//circular fifo
	if(fifo->tail == (fifo->base + (fifo->length*sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;
	return fifo_no_error;

}
fifo_status_buff_t fifo_is_full(fifo_buff_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	if(fifo->count == fifo->length)
		return fifo_full;
	else
		return fifo_no_error;

}
fifo_status_buff_t fifo_is_empty(fifo_buff_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	if(fifo->count == 0)
		return fifo_empty;
	else
		return fifo_no_error;

}
void fifo_print(fifo_buff_t* fifo)
{
	int i;
	element_type* temp; // pointer variable to not change our fifo
	if(fifo_is_empty(fifo) == fifo_empty)
		printf("===fifo empty===\n");
	else
	{
		temp = fifo->tail;
		printf("===fifo print===\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t %x \n",*temp);
			temp++;
		}


	}


}
