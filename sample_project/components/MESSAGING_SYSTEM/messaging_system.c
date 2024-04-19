#include "include/messaging_system.h"

CIRCULAR_BUFFER_t gReceivedMessages[MAX_NUMBER_MESSAGES];

bool MESSAGE_SendMessage(MESSAGE_t new_message)
{
    uint8_t index = new_message.destination;
    if(gReceivedMessages[index].distance < MAX_NUMBER_MESSAGES - 1)
    {
        MESSAGE_IncrementBuffer(&gReceivedMessages[index]);
        MESSAGE_CopyMessage(&gReceivedMessages[index].new_msg[gReceivedMessages[index].end], new_message);
        return true;
    }
    return false; /*BUFFER is FULL*/
}

bool MESSAGE_ExtractMessage(uint8_t index, MESSAGE_t *out_msg)
{
    if(gReceivedMessages[index].distance > 0)
    {
        MESSAGE_CopyMessage(out_msg, gReceivedMessages[index].new_msg[gReceivedMessages[index].start]);
        MESSAGE_DecrementBuffer(&gReceivedMessages[index]);
        return true;
    }
    return false; /*BUFFER is EMPTY*/
}

void MESSAGE_IncrementBuffer(CIRCULAR_BUFFER_t * buffer)
{
    buffer->distance++;
    if(buffer->end + 1 >= MAX_NUMBER_MESSAGES)
    {
        buffer->end = 0;
    }
    else
    {
        buffer->end += 1;
    }
}

void MESSAGE_DecrementBuffer(CIRCULAR_BUFFER_t * buffer)
{
    buffer->distance--;
    if(buffer->start - 1 < 0)
    {
        buffer->start = MAX_NUMBER_MESSAGES - 1;
    }
    else
    {
        buffer->start -= 1;
    }
}

void MESSAGE_CopyMessage(MESSAGE_t* buffer, MESSAGE_t new_message)
{
    buffer->command = new_message.command;
    buffer->value = new_message.value;
    buffer->destination = new_message.destination;
    buffer->origin = new_message.origin;
}
