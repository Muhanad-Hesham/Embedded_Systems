#ifndef MAIN_ALG_H_
#define MAIN_ALG_H_

#include "states.h"

enum {
	Mg_HP_detect

}Mg_state_id;

STATE_DEFINE(Mg_HP_detect);

extern void (*Mg_state)();




#endif