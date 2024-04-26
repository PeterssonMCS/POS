/*
 * useful_macros.h
 *
 *  Created on: 19 de abr. de 2024
 *      Author: peter
 */

#ifndef _USEFUL_MACROS_H_
#define _USEFUL_MACROS_H_

#define BUTTON_LIST(MACRO)				\
	MACRO( PIN_BUTTON_1 , 27 )

#define OUTPUT_LIST(MACRO)				\
	MACRO( PIN_OUTPUT_1 , 12 )			\
	MACRO( PIN_OUTPUT_2 , 13 )			\
	MACRO( PIN_OUTPUT_3 , 14 )

#define SET_BUTTON(NAME , PIN)			\
	GPIO_SetPinInput(PIN);

#define SET_OUTPUT(NAME , PIN)			\
	GPIO_SetPinOutput(PIN , 0);

#define GET_BUTTON(NAME , PIN)			\
	NAME = GPIO_GetInputLevel(PIN);

#define VAR_BUTTON(NAME , PIN)			\
	bool NAME;

#define GPIO_LIST(NAME , PIN) \
	int NAME = PIN;

#endif /* MAIN_USEFUL_MACROS_H_ */
