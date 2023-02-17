/*
 * CA.c
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */


#include "CA.h"
//varibales

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

int US_get_distance_random(int l, int r, int count);
//STATE pointer to function

void(*CA_state)(); // pointer seen only from CA.c must be seen from main

//definition for function states
STATE_define(CA_waiting)
{
	//state name
	CA_state_id = CA_waiting;
	//state action
	//send to dc motor / speed DC_motor(speed)
	CA_speed = 0;
	//event check
	//US_get_distance(CA_distance)
	CA_distance = US_get_distance_random(45, 55, 1);
	(CA_distance <= CA_threshold ) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("\nCA_waiting state: distance=%d speed=%d",CA_distance,CA_speed);
}

STATE_define(CA_driving)
{
	//state name
	CA_state_id = CA_driving;
	//state action
	//send to dc motor / speed DC_motor(speed)
	CA_speed = 30;
	//event check
	//US_get_distance(CA_distance)
	CA_distance = US_get_distance_random(45, 55, 1);
	(CA_distance <= CA_threshold ) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("\nCA_driving state: distance=%d speed=%d",CA_distance,CA_speed);

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
