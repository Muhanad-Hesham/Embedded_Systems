/*
 * US.h
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */

#ifndef US_H_
#define US_H_

#include "state.h"
//Define states
enum {
	US_busy

}US_state_id;

//declare states functions US collision avoidance
STATE_define(US_busy);
void US_init();

extern void (*US_state)(); //it will be included in main so will be seen in main
#endif /* US_H_ */
