/*
 * DC.c
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */


#include "DC.h"
//varibales

int DC_speed = 0;



//STATE pointer to function

void(*DC_state)(); // pointer seen only from DC.c mDCt be seen from main

void DC_init()
{
	// init pwm
	printf("\n DC init");
}

void DC_motor_set_speed(speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("\nCA -------speed=%d----->DC ", DC_speed);
}

//definition for function states
STATE_define(DC_idle)
{
	//state name
	DC_state_id = DC_idle;
	//state action
	//call pwm to make speed = DC_speed
	printf("\nDC_idle state: speed=%d",DC_speed);
}

STATE_define(DC_busy)
{
	//state name
	DC_state_id = DC_busy;
	//state action
	//call pwm to make speed = DC_speed
	DC_state = STATE(DC_idle);
	printf("\nDC_idle state: speed=%d",DC_speed);

}


