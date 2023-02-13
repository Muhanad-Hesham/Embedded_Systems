/*
 * linked_list.h
 *
 *  Created on: Feb 13, 2023
 *      Author: Muhand
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

// Definitions

#define Dprintf(...)        fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);

//effective data
typedef struct Sdata{
	int id;
	char name[40];
	float height;
}Sdata_t;

//Node for Data and Pointer to the next node
typedef struct Sstudent{
	Sdata_t student;
	struct Sstudent* Pnextstudent;
}Sstudent_t;


// APIs

void add_student();
int delete_student();
void view_student();
void delete_all();
int get_node(int index);
int students_numbers_iterative();
int students_numbers_recursive(Sstudent_t* gpfirststudent );
int get_node_from_end(int index);
int middle_node();
void Reverse_records();



#endif /* LINKED_LIST_H_ */
