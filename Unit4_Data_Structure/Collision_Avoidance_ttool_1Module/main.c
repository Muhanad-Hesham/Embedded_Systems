/*
 * main.c
 *
 *  Created on: Feb 16, 2023
 *      Author: Muhand
 */

#include "CA.h"


void setup()
{
	//init all the drivers
	//init IRQ ..
	//init Block
	//set statets pointers for each bloack
	CA_state = STATE(CA_waiting);
}

void main(){

	setup();
	while(1)
	{
		volatile int d;
		CA_state();
		//delay
		for(d=0; d<=1000;d++);
	}

}
