#ifndef _POS_H_
#define _POS_H_

#include <stdint.h>

#define MAX_NUMBER_TASKS 32

#define NEW_TASK(NAME , FUNCTION , TIME)\
	Task_t new_task_##NAME = {			\
		.callback = &FUNCTION,			\
		.runTime = TIME,				\
		.lastRun = 0,					\
	};									\
	POS_InsertTask(&new_task_##NAME);	\


typedef struct
{
	void(*callback)();
	uint32_t runTime;
	uint32_t lastRun;
}Task_t;

typedef struct
{
	uint8_t lastID;
	uint32_t sysTick;
	uint32_t sysTickIncrement;
}POS_t;

void POS_InsertTask(Task_t* newTask);

void POS_Run();

void POS_SysTick();

void POS_SetSysTickIncrement(uint32_t newSystickIncrement);

uint32_t POS_GetSysTick();

#endif
