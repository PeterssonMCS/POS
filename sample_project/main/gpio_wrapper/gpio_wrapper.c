/*
 * gpio_wrapper.c
 *
 *  Created on: 19 de abr. de 2024
 *      Author: peter
 */
#include "gpio_wrapper.h"

uint64_t gOutputBitMask = 0;
uint64_t gInputBitMask = 0;

gpio_config_t pOutputConfig =
{
	.mode = GPIO_MODE_OUTPUT,
	.pull_up_en = false,
	.pull_down_en = false,
};

gpio_config_t pInputConfig =
{
	.mode = GPIO_MODE_INPUT,
	.pull_up_en = false,
	.pull_down_en = true,
};

void GPIO_SetPinOutput( uint8_t pin , bool state )
{
	gOutputBitMask |= (1 << pin);
	pOutputConfig.pin_bit_mask = gOutputBitMask;
	gpio_config(&pOutputConfig);
}

void GPIO_SetPinInput( uint8_t pin )
{
	gInputBitMask |= (1 << pin);
	pInputConfig.pin_bit_mask = gInputBitMask;
	gpio_config(&pInputConfig);
}

void GPIO_SetOutputLevel( uint8_t pin , bool state)
{
	gpio_set_level( pin , state );
}

bool GPIO_GetInputLevel( uint8_t pin )
{
	return gpio_get_level( pin );
}
