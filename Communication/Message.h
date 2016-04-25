/*
 * Message.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGE_H_
#define COMMUNICATION_MESSAGE_H_

#include "MessageTypes.h"
#include "MessageData.h"

typedef struct Message
{
	MessageType msgType;
	MessageData msgData;
} Message;

#endif /* COMMUNICATION_MESSAGE_H_ */
