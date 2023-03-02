
#include "states.h"

enum {
	PS_Reading,
	PS_Waiting
}Psensor_state_id;

void PS_INIT();
STATE_DEFINE(PS_Reading);
STATE_DEFINE(PS_Waiting);

extern void (*PS_state)();
