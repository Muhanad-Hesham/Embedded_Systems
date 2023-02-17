/*
 * CA.h
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
//Define states
enum {
	CA_waiting,
	CA_driving,
}CA_state_id;

//declare states functions CA collision avoidance
STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*CA_state)(); //it will be included in main so will be seen in main
#endif /* CA_H_ */
