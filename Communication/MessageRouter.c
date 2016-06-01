/*
 * MessageRouter.c
 *
 *  Created on: 20 kwi 2016
 *      Author: Karol
 */

#include  "MessageRouter.h"
#include "../Utilities/Logger.h"

#include "../1Wire/1WireService.h"
#include "../LCD/ServiceLcd.h"

static void forwardMsgToService(Message p_msg);

void sendMessage(const ServiceAddress p_source, Message p_msg)
{
	LOG_INFO("Sending %s from %s to %s", msgType2String(p_msg.msgType),
										 serviceAddressToString(p_source),
										 serviceAddressToString(p_msg.destinationAddress));
	forwardMsgToService(p_msg);
}

void forwardMsgToService(Message p_msg)
{
	switch(p_msg.msgType)
	{
		case MSG_LCD_BACKGROUND:
			handleLcdBackground(p_msg.msgData);
		break;
		case MSG_DS18B20_TEMPERATURE_REQ:
			handleDS18B20_TemperatureRequest(p_msg.msgData);
		break;
		case MSG_LCD_DISPLAY_TEMPERATURE:
			handleLcdDisplayTemperature();
		break;

		default:
			LOG_DEBUG("Not known msg type: %s", msgType2String(p_msg.msgType));
		break;
	}
}
