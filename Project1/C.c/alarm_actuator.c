

#include "alarm_actuator.h"

void (*AC_state)();

void AC_INIT()
{

	// alarm_actuator_driver init
}

void Alarm_Act_stop_alarm()
{
	AC_state = STATE(AC_OFF);
}
void Alarm_Act_start_alarm()
{
	AC_state = STATE(AC_ON);
}


STATE_DEFINE(AC_Waiting)
{
	AC_state_id = AC_Waiting;
}
STATE_DEFINE(AC_ON)
{
	//state name
	AC_state_id = AC_ON;
	//state action
	Set_Alarm_actuator(0);
	//check event
	AC_state = STATE(AC_Waiting);

}
STATE_DEFINE(AC_OFF)
{
	//state name
	AC_state_id = AC_OFF;
	//state action
	Set_Alarm_actuator(1);
	//check event
	AC_state = STATE(AC_Waiting);
}