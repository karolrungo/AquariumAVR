/*
 * MessageRouter.h
 *
 *  Created on: 20 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGEROUTER_H_
#define COMMUNICATION_MESSAGEROUTER_H_

#include "ServiceAddresses.h"
#include "Message.h"

void sendMessage(const ServiceAddress, const ServiceAddress, const Message);

#endif /* COMMUNICATION_MESSAGEROUTER_H_ */
