#ifndef _MESSAGING_SYSTEM_H
#define _MESSAGING_SYSTEM_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_NUMBER_MESSAGES 4

typedef struct
{
	uint8_t origin;
	uint8_t destination;
	uint8_t command;
	uint32_t value;
}MESSAGE_t;

typedef struct
{
	MESSAGE_t new_msg[MAX_NUMBER_MESSAGES];
	uint8_t start;
	uint8_t end;
	uint8_t distance;
}CIRCULAR_BUFFER_t;

bool MESSAGE_SendMessage(MESSAGE_t new_message);

bool MESSAGE_ExtractMessage(uint8_t index , MESSAGE_t *new_message);

void MESSAGE_IncrementBuffer(CIRCULAR_BUFFER_t * buffer);

void MESSAGE_DecrementBuffer(CIRCULAR_BUFFER_t * buffer);

void MESSAGE_CopyMessage(MESSAGE_t* buffer, MESSAGE_t new_message);

#endif
