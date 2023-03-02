
#include "main_alg.h"
void (*Mg_state)();

int Mg_pval = 0;
int threshold = 20;

void Set_Pressure_Val(int pval )
{
	Mg_pval = pval;
	Mg_state = STATE(Mg_HP_detect);
}


STATE_DEFINE(Mg_HP_detect)
{
	Mg_state_id = Mg_HP_detect;
	
	if(Mg_pval > threshold)
	{
		High_Pressure_Detected ();
	}
	else
	{
		Mg_state = STATE(Mg_HP_detect);

	}
	
}


