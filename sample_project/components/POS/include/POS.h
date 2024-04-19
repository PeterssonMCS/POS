#ifndef _POS_H_
#define _POS_H_

#define MAX_NUMBER_TASKS 32

#define NEW_TASK(NAME , FUNCTION , TIME)\
	Task_t new_task_##NAME = {			\
		.callback = &FUNCTION,			\
		.timer = TIME					\
	};									\
	POS_InsertTask(&new_task_##NAME);	\


typedef struct
{
	void(*callback)();
	unsigned int timer;
}Task_t;

typedef struct
{
	short unsigned int lastID;
	long unsigned int sysTick;
	long unsigned int sysTickIncrement;
}POS_t;

void POS_InsertTask(Task_t* newTask);

void POS_Run();

void POS_SysTick();

void POS_SetSysTickIncrement(unsigned long int newSystickIncrement);

unsigned long int POS_GetSysTick();

#endif
