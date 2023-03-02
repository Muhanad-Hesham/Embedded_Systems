
#include "Psensor.h"

void (*PS_state)();


void PS_INIT()
{
	//init pressure sensor driver
}
STATE_DEFINE(PS_Reading)
{
	//state name
	Psensor_state_id = PS_Reading;
	//state action
	int Ps_val = getPressureVal();
	//sending pressure value
	Set_Pressure_Val(Ps_val); 
	//delay for safe measurments
	Delay(600);
	//event check
	PS_state = STATE(PS_Waiting);
	
}
STATE_DEFINE(PS_Waiting)
{
	//state name
	Psensor_state_id = PS_Waiting;
	//make delay
	Delay(1000);
	//event check
	PS_state = STATE(PS_Reading);
}