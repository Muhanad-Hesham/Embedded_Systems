/*
 * DC.h
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
//Define states
enum {
	DC_idle,
	DC_busy,
}DC_state_id;

//declare states functions DC collision avoidance
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();
extern void (*DC_state)(); //it will be included in main so will be seen in main
#endif /* DC_H_ */
