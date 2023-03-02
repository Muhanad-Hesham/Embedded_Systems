#ifndef ALARM_ACT_H_
#define ALARM_ACT_H_

#include "states.h"

enum {
	AC_Waiting,
	AC_ON,
	AC_OFF
}AC_state_id;

void AC_INIT();
STATE_DEFINE(AC_Waiting);
STATE_DEFINE(AC_ON);
STATE_DEFINE(AC_OFF);

extern void (*AC_state)();









#endif