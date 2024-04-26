/*
 * gpior_wrapper.h
 *
 *  Created on: 19 de abr. de 2024
 *      Author: peter
 */

#ifndef _GPIO_WRAPPER_H_
#define _GPIO_WRAPPER_H_

#include "driver/gpio.h"
#include <stdint.h>
#include <stdbool.h>

void GPIO_SetPinOutput( uint8_t pin , bool state );

void GPIO_SetPinInput( uint8_t pin );

void GPIO_SetOutputLevel( uint8_t pin , bool state);

bool GPIO_GetInputLevel( uint8_t pin );

#endif
