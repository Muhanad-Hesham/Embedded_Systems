/*
 * lifo.c
 *
 *  Created on: Jan 15, 2023
 *      Author: Muhand
 */


//implementation
#include "stdio.h"
#include "lifo.h"

lifo_status_t lifo_add_item(lifo_buff_t* lifo_buff, unsigned int item)
{
	// if buffer is exist
	if(!lifo_buff->base || !lifo_buff->head)
			return lifo_null;
	//if buffer is full or not
  //if(lifo_buff->head >= (lifo_buff->base + (lifo_buff->length * sizeof(int)))
	if(lifo_buff->count == lifo_buff->length)
		return lifo_full;
	*(lifo_buff->head) = item;
	lifo_buff->head++;
	lifo_buff->count++;
	return lifo_no_error;

}



lifo_status_t lifo_get_item(lifo_buff_t* lifo_buff, unsigned int* item)
{
	// if buffer is exist
		if(!lifo_buff->base || !lifo_buff->head)
				return lifo_null;
	// if buffer is empty or not
		if(lifo_buff->count == 0)
			return lifo_empty;
		lifo_buff->head--;
		*item= *(lifo_buff->head);
		lifo_buff->count--;
		return lifo_no_error;

}
lifo_status_t lifo_init(lifo_buff_t* lifo_buff, unsigned int* buff, unsigned int length)
{
	if(lifo_buff == NULL)
		return lifo_null;
	lifo_buff->base = buff;
	lifo_buff->head = buff;
	lifo_buff->length = length;
	lifo_buff->count = 0;
    return lifo_no_error;
}


