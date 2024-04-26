/*
 * adc_wrapper.h
 *
 *  Created on: 25 de abr. de 2024
 *      Author: peter
 */

#ifndef _WRAPPER_ADC_WRAPPER_H_
#define _WRAPPER_ADC_WRAPPER_H_

#include <stdint.h>
#include "driver/adc.h"

void ADC_Init();

int32_t ADC_Read(uint8_t value);

#endif /* MAIN_ADC_WRAPPER_ADC_WRAPPER_H_ */
