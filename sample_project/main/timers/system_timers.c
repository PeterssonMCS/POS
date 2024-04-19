/*
 * system_timers.c
 *
 *  Created on: 18 de abr. de 2024
 *      Author: peter
 */
#include "system_timers.h"

esp_timer_handle_t timer_handle;

esp_timer_create_args_t timer_config = {
        .callback = &TIMERS_Callback,
        .arg = NULL,
        .name = "gptimer"
    };

void (*TimerCallback)();

void TIMERS_Callback(void* arg)
{
	TimerCallback();
}

void TIMERS_Init()
{
	esp_timer_create(&timer_config, &timer_handle);
	esp_timer_start_periodic(timer_handle, 1000);
}

void TIMERS_RegisterCallback(void(*cb)())
{
	TimerCallback = cb;
}
