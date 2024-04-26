/*
 * adc_wrapper.c
 *
 *  Created on: 25 de abr. de 2024
 *      Author: peter
 */

#include "adc_wrapper.h"

#define ADC_WIDTH ADC_WIDTH_BIT_12
#define ADC_ATTEN ADC_ATTEN_DB_0

#define ADC_1 ADC1_CHANNEL_6
#define ADC_2 ADC1_CHANNEL_7

void ADC_Init()
{
    adc1_config_width(ADC_WIDTH);
    adc1_config_channel_atten(ADC_1, ADC_ATTEN);

    adc1_config_width(ADC_WIDTH);
    adc1_config_channel_atten(ADC_2, ADC_ATTEN);
}

int32_t ADC_Read(uint8_t value)
{
	uint32_t adc_reading;
	switch(value)
	{
		case 0:
			adc_reading = adc1_get_raw(ADC_1);
		break;
		case 1:
			adc_reading = adc1_get_raw(ADC_2);
		break;
		default:
			adc_reading = 0;
		break;
	}
	return adc_reading;
}
