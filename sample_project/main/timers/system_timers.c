/*
 * system_timers.c
 *
 *  Created on: 18 de abr. de 2024
 *      Author: peter
 */
#include "system_timers.h"

esp_timer_handle_t gSystemTimer;

esp_timer_create_args_t gSystemTimerConfig = {
        .callback = &TIMERS_Callback,
        .arg = NULL,
        .name = "gptimer"
    };

void (*TimerCallback)();

/*
 *Run the callback registered
 */
void TIMERS_Callback(void* arg)
{
	TimerCallback();
}

void TIMERS_Init(int period)
{
	esp_timer_create(&gSystemTimerConfig, &gSystemTimer);
	esp_timer_start_periodic(gSystemTimer, period*1000);
}

void TIMERS_RegisterCallback(void(*cb)())
{
	TimerCallback = cb;
}
