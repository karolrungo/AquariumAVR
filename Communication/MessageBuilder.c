/*
 * MessageBuilder.c
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */
#include "MessageBuilder.h"

Message buildMessageLcdBackground(bool p_turnOn)
{
	Message l_msg;
	l_msg.msgType = MSG_LCD_BACKGROUND;
	l_msg.msgData.lcdBackground.turnOn = p_turnOn;
	return l_msg;
}

