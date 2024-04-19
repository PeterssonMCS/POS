#include "POS.h"

Task_t tasks[MAX_NUMBER_TASKS];

POS_t gActualPOS = {
  .lastID = 0,
  .sysTick = 0,
  .sysTickIncrement = 0,
};

/*
 * Insert new Task on the stack of OS
 */
void POS_InsertTask(Task_t* newTask)
{
	if(gActualPOS.lastID < MAX_NUMBER_TASKS)
	{
		tasks[gActualPOS.lastID].timer = newTask->timer;
		tasks[gActualPOS.lastID].callback = newTask->callback;
		gActualPOS.lastID++;
	}
}

/*
 * Run the tasks on the stack of OS
 */
void POS_Run()
{
	unsigned long int startTaskTimer;
	for(int i = 0; i < gActualPOS.lastID ; i++)
	{
		startTaskTimer = gActualPOS.sysTick;
		tasks[i].callback();
		while(gActualPOS.sysTick - startTaskTimer < tasks[i].timer);
	}
}

/*
 * Update the internal timer of the OS
 */
void POS_SysTick()
{
	gActualPOS.sysTick += gActualPOS.sysTickIncrement;
}

/*
 * Update the internal increment depending of the timer used to update the systick
 */
void POS_SetSysTickIncrement(unsigned long int newSystickIncrement)
{
	gActualPOS.sysTickIncrement = newSystickIncrement;
}

/*
 * Return the value of the internal timer used by the OS
 */
unsigned long int POS_GetSysTick()
{
	return gActualPOS.sysTick;
}
