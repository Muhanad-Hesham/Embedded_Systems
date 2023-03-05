/*
 * students.h
 *
 *  Created on: Mar 3, 2023
 *      Author: Muhand
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_


#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define DPRINTF(...) fflush(stdin); fflush(stdout); printf(__VA_ARGS__); fflush(stdin); fflush(stdout);


typedef struct{
	unsigned char Fname[40];
	unsigned char Lname[40];
	int roll;
	float gpa;
	int cid[10];
}info_t;

//buffer contains students data
info_t buffer[100];

typedef struct{
	unsigned int length;
	unsigned int count;
	info_t* base;
	info_t* tail;
	info_t* head;

}fifo_buf_t;

typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null,
	fifo_error

}fifo_buff_status;

typedef enum{
	exist,
	not_exist
}check_t;


//APIs

check_t Check_Roll(fifo_buf_t* fifo,int roll);
fifo_buff_status FIFO_INIT(fifo_buf_t* fifo,info_t* buf,unsigned int length);
fifo_buff_status Add_Student_File(fifo_buf_t* fifo);
fifo_buff_status Add_Student_Manually(fifo_buf_t* fifo);
fifo_buff_status Find_Using_Roll(fifo_buf_t* fifo);
fifo_buff_status Find_Using_Fname(fifo_buf_t* fifo);
fifo_buff_status Display_Using_cid(fifo_buf_t* fifo);
fifo_buff_status Total_No_Students(fifo_buf_t* fifo);
fifo_buff_status Delete_Student_by_roll(fifo_buf_t* fifo);
fifo_buff_status Shift_Buffer(int index,fifo_buf_t* fifo);
fifo_buff_status Update_Student_by_roll(fifo_buf_t* fifo);
fifo_buff_status Show_All_Info(fifo_buf_t* fifo);



#endif /* STUDENTS_H_ */
