#include <stdio.h>
#include <POS.h>
#include "timers/system_timers.h"

#define OS_TICK 1

void task1()
{
	printf("Hello meu bom\n");
	printf("%ld\n",POS_GetSysTick());
}

void app_main(void)
{
	TIMERS_RegisterCallback(&POS_SysTick);
	POS_SetSysTickIncrement(OS_TICK);
	TIMERS_Init();

	NEW_TASK(TASK1,task1,100)

	while(1)
	{
		POS_Run();
	}
}
