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

static void forwardMsgToService(const ServiceAddress p_destination,  Message p_msg);

void sendMessage(const ServiceAddress p_source, const ServiceAddress p_destination, Message p_msg)
{
	LOG_Line("Sending %s from %s to %s", msgType2String(p_msg.msgType), toString(p_source), toString(p_destination));
	forwardMsgToService(p_destination, p_msg);
}

void forwardMsgToService(const ServiceAddress p_destination,  Message p_msg)
{
	switch(p_msg.msgType)
	{
		case MSG_LCD_BACKGROUND:
			handleLcdBackground(p_msg.msgData);
		break;
		case MSG_DS18B20_TEMPERATURE_REQ:
			handleDS18B20_TemperatureRequest(p_msg.msgData);
		break;

		default:
			LOG_Line("Not known msg type: %d", p_msg.msgType);
		break;
	}
}
