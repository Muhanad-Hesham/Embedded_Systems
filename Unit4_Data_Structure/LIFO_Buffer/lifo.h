/*
 * lifo.h
 *
 *  Created on: Jan 15, 2023
 *      Author: Muhand
 */

#ifndef LIFO_H_
#define LIFO_H_




//definitions

typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;

}lifo_buff_t;

typedef enum{
	lifo_no_error,
	lifo_full,
	lifo_empty,
	lifo_null
}lifo_status_t;

//APIs

lifo_status_t lifo_add_item(lifo_buff_t* lifo_buff, unsigned int item);
lifo_status_t lifo_get_item(lifo_buff_t* lifo_buff, unsigned int* item);
lifo_status_t lifo_init(lifo_buff_t* lifo_buff, unsigned int* buff, unsigned int length);


#endif /* LIFO_H_ */
