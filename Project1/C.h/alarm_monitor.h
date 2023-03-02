#ifndef ALARM_M_H_
#define ALARM_M_H_

#include "states.h"


enum {
	AM_Alarm_ON,
	AM_Alarm_OFF,
	AM_Waiting
}AM_state_id;


STATE_DEFINE(AM_Alarm_ON);
STATE_DEFINE(AM_Alarm_OFF);
STATE_DEFINE(AM_Waiting);

extern void (*AM_state)();


#endif
