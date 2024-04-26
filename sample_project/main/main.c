#include <stdio.h>
#include <POS.h>
#include "timers/system_timers.h"
#include "gpio_wrapper/gpio_wrapper.h"
#include "useful_macros.h"
#include "adc_wrapper/adc_wrapper.h"

#define OS_TICK 1

BUTTON_LIST(GPIO_LIST)
OUTPUT_LIST(GPIO_LIST)

void keyboard_task()
{
	BUTTON_LIST(GET_BUTTON)
}

void task1()
{
	static bool state = false;
	GPIO_SetOutputLevel(PIN_OUTPUT_1 , state);
	state = state == false? true : false;
}

void task2()
{
	static bool state = false;
	GPIO_SetOutputLevel(PIN_OUTPUT_2 , state);
	state = state == false? true : false;
}

void task3()
{
	static bool state = false;
	GPIO_SetOutputLevel(PIN_OUTPUT_3 , state);
	state = state == false? true : false;
}

void task5()
{
	int32_t value_y = ADC_Read(1);
	int32_t value_x = ADC_Read(0);
	printf("x: %lu y: %lu \n" , value_x , value_y);
}

void app_main(void)
{
	TIMERS_RegisterCallback(&POS_SysTick);
	POS_SetSysTickIncrement(OS_TICK);
	TIMERS_Init(OS_TICK);
	ADC_Init();

	NEW_TASK(KEYBOARD , keyboard_task , 1)
//	NEW_TASK(TASK1 , task1 , 300)
//	NEW_TASK(TASK2 , task2 , 200)
//	NEW_TASK(TASK3 , task3 , 100)
	NEW_TASK(TASK5 , task5 , 1000)

	BUTTON_LIST(SET_BUTTON)
	OUTPUT_LIST(SET_OUTPUT)

	while(1)
	{
		POS_Run();
	}
}
