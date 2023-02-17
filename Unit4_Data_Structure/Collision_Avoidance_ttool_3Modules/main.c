/*
 * main.c
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */

#include "CA.h"
#include "US.h"
#include "DC.h"


void setup()
{
	//init all the drivers
	//init IRQ ..
	//init Block
	US_init();
	DC_init();
	//set statets pointers for each bloack
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

void main(){

	setup();
	while(1)
	{
		volatile int d;

		US_state();
		CA_state();
		DC_state();
		//delay
		for(d=0; d<=1000;d++);
	}

}
