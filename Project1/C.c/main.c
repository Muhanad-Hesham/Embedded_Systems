#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "states.h"
#include "Psensor.h"
#include "main_alg.h"
#include "alarm_monitor.h"
#include "alarm_actuator.h"

void setup()
{
	PS_INIT();
	AC_INIT();
	PS_state = STATE(PS_Reading);
	Mg_state = Set_Pressure_Val;
	AM_state = Alarm_Act_stop_alarm;
	AC_state = STATE(AC_Waiting);
	
	
}


int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		/*int pval = getPressureVal();
		if (pval > 20)
		{
			Set_Alarm_actuator(0);
			
		}
		else
		{
			Set_Alarm_actuator(1);
			
		}*/
		//Implement your Design 
		PS_state();
		Mg_state();
		AM_state();
		AC_state();
	}

}
