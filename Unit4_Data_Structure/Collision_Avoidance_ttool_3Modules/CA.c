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


//STATE pointer to function

void(*CA_state)(); // pointer seen only from CA.c must be seen from main

void US_set_distance(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold ) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("\nUS -------distance=%d----->CA ", CA_distance);
}



//definition for function states
STATE_define(CA_waiting)
{
	//state name
	CA_state_id = CA_waiting;
	printf("\nCA_waiting state: distance=%d speed=%d",CA_distance,CA_speed);
	//state action
	//send to dc motor / speed DC_motor(speed)
	CA_speed = 0;
	DC_motor_set_speed(CA_speed);
	//event check
	//US_get_distance(CA_distance)


}

STATE_define(CA_driving)
{
	//state name
	CA_state_id = CA_driving;
	printf("\nCA_driving state: distance=%d speed=%d",CA_distance,CA_speed);
	//state action
	//send to dc motor / speed DC_motor(speed)
	CA_speed = 30;
	DC_motor_set_speed(CA_speed);
	//event check
	//US_get_distance(CA_distance)



}


