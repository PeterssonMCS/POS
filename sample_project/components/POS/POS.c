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
		tasks[gActualPOS.lastID].runTime = newTask->runTime;
		tasks[gActualPOS.lastID].callback = newTask->callback;
		tasks[gActualPOS.lastID].lastRun = newTask->lastRun;
		gActualPOS.lastID++;
	}
}

/*
 * Run the tasks on the stack of OS
 */
void POS_Run()
{
	for(int i = 0; i < gActualPOS.lastID ; i++)
	{
		if(tasks[i].runTime <= gActualPOS.sysTick - tasks[i].lastRun)
		{
			tasks[i].callback();
			tasks[i].lastRun = gActualPOS.sysTick;
		}
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
void POS_SetSysTickIncrement(uint32_t newSystickIncrement)
{
	gActualPOS.sysTickIncrement = newSystickIncrement;
}

/*
 * Return the value of the internal timer used by the OS
 */
uint32_t POS_GetSysTick()
{
	return gActualPOS.sysTick;
}
