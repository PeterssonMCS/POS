#include <stdio.h>
#include <POS.h>
#include "timers/system_timers.h"

#define OS_TICK 1

typedef union
{
	struct
	{
		int event_1 : 1;
		int event_2 : 1;
		int event_3 : 1;
		int event_4 : 1;
		int event_5 : 1;
		int event_6 : 1;
		int event_7 : 1;
		int event_8 : 1;
		int event_9 : 1;
		int event_10 : 1;
		int event_11 : 1;
		int event_12 : 1;
		int event_13 : 1;
		int event_14 : 1;
		int event_15 : 1;
		int event_16 : 1;
		int event_17 : 1;
		int event_18 : 1;
		int event_19 : 1;
		int event_20 : 1;
		int event_21 : 1;
		int event_22 : 1;
		int event_23 : 1;
		int event_24 : 1;
		int event_25 : 1;
		int event_26 : 1;
		int event_27 : 1;
		int event_28 : 1;
		int event_29 : 1;
		int event_30 : 1;
		int event_31 : 1;
	};
	int all_events;
}SYSTEM_EVENTS_t;

void task1()
{
	printf("Hello meu bom\n");
	printf("%ld\n",POS_GetSysTick());
}

void task2()
{
	printf("Hello meu bom 2 \n");
	printf("%ld\n",POS_GetSysTick());
}

void app_main(void)
{
	TIMERS_RegisterCallback(&POS_SysTick);
	POS_SetSysTickIncrement(OS_TICK);
	TIMERS_Init(OS_TICK);

	NEW_TASK(TASK1 , task1 , 1000)
	NEW_TASK(TASK2 , task2 , 2000)

	while(1)
	{
		POS_Run();
	}
}
