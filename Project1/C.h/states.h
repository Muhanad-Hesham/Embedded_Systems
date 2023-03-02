#ifndef STATES_H_
#define STATES_H_

#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "platforms_types.h"

#define STATE_DEFINE(_statFUN_) void st_##_statFUN_()
#define STATE(_statFUN_)  st_##_statFUN_


void Set_Pressure_Val(int pval );
void High_Pressure_Detected ();
void Alarm_Act_start_alarm();
void Alarm_Act_stop_alarm();



#endif