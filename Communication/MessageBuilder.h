/*
 * MessageBuilder.h
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGEBUILDER_H_
#define COMMUNICATION_MESSAGEBUILDER_H_

#include "Message.h"

Message buildMessageLcdBackground(LcdBackround p_state);
Message buildMessageLcdDisplayTemperature();
Message buildMessageDS18B20TemperatureRequest(uint8_t p_sensorNumber);

#endif /* COMMUNICATION_MESSAGEBUILDER_H_ */
