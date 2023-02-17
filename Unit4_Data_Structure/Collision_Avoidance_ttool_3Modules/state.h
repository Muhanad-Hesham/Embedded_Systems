/*
 * state.h
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
//automatic state function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_


//states connection between modules
void US_set_distance(int distance); //will defined put it in the destination CA
void DC_motor_set_speed(int speed); //will defined put it in the destination CA

#endif /* STATE_H_ */
