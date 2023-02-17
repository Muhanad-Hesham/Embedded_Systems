/*
 * US.c
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */


#include "US.h"
//varibales


int US_distance = 0;


int US_get_distance_random(int l, int r, int count);
//STATE pointer to function

void(*US_state)(); // pointer seen only from US.c must be seen from main

void US_init()
{
	//init US driver
	printf("\nUS init");
}

//definition for function states
STATE_define(US_busy)
{
	//state name
	US_state_id = US_busy;
	//state action
	US_distance = US_get_distance_random(45, 55, 1);
	printf("\nUS_waiting state: distance=%d",US_distance);
	US_set_distance(US_distance);
	US_state = STATE(US_busy);

}



int US_get_distance_random(int l, int r, int count)
{
	//this will generate random numbers in range between l and r
	int i;
	for(i=0; i<count; i++){
		int rand_num = (rand() % (r-l+1)) + l;
		return rand_num;
	}

}
