/*
 * MessageBuilder.c
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */
#include "MessageBuilder.h"

#include "../Utilities/Logger.h"

Message buildMessageLcdBackground(LcdBackround p_state)
{
	Message l_msg;
	l_msg.destinationAddress = LCD_Service;
	l_msg.msgType = MSG_LCD_BACKGROUND;
	l_msg.msgData.lcdBackground = p_state;
	return l_msg;
}

Message buildMessageDS18B20TemperatureRequest(uint8_t p_sensorNumber)
{
	Message l_msg;
	l_msg.destinationAddress = DS18B20_Service;
	l_msg.msgType = MSG_DS18B20_TEMPERATURE_REQ;
	l_msg.msgData.ds1820SensorNumber = p_sensorNumber;
	return l_msg;
}

Message buildMessageLcdDisplayTemperature()
{
	Message l_msg;
	l_msg.destinationAddress = LCD_Service;
	l_msg.msgType = MSG_LCD_DISPLAY_TEMPERATURE;
	return l_msg;
}

