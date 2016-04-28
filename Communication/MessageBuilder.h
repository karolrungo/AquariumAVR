/*
 * MessageBuilder.h
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGEBUILDER_H_
#define COMMUNICATION_MESSAGEBUILDER_H_

#include <stdbool.h>

#include "Message.h"

Message buildMessageLcdBackground(bool p_turnOn);
Message buildMessageDS18B20TemperatureRequest(uint8_t p_sensorNumber);

#endif /* COMMUNICATION_MESSAGEBUILDER_H_ */
