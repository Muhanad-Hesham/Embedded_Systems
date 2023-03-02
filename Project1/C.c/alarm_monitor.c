
#include "alarm_monitor.h"

void (*AM_state)();

int Alarm_timer = 6000000;

void High_Pressure_Detected()
{
	AM_state = STATE(AM_Alarm_ON);
}	



STATE_DEFINE(AM_Alarm_OFF)
{
	//state name
	AM_state_id = AM_Alarm_OFF;
	//state action
	Alarm_Act_stop_alarm();
	//check state
	

}

STATE_DEFINE(AM_Alarm_ON)
{
	//state name
	AM_state_id = AM_Alarm_ON;
	//state action
	Alarm_Act_start_alarm();
	//DElay timer
	//Delay(Alarm_timer);
	//check state
	AM_state = STATE(AM_Waiting);
}

STATE_DEFINE(AM_Waiting)
{
	//state name
	AM_state_id = AM_Waiting;

	//state action
	Alarm_Act_stop_alarm();
	Delay(Alarm_timer);
	

	AM_state = STATE(AM_Alarm_OFF);
}
