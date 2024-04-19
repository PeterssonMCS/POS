/*
 * system_timers.h
 *
 *  Created on: 18 de abr. de 2024
 *      Author: peter
 */

#ifndef _SYSTEM_TIMERS_H_
#define _SYSTEM_TIMERS_H_

#include "esp_timer.h"
#include <stdlib.h>

void TIMERS_Callback(void* arg);

void TIMERS_Init();

void TIMERS_RegisterCallback(void(*cb)());


#endif /* MAIN_TIMERS_SYSTEM_TIMERS_H_ */
