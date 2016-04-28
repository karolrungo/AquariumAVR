/*
 * ServiceLcd.c
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#include "ServiceLcd.h"

#include "lcd44780.h"
#include "../Utilities/Logger.h"

void initLcd()
{
	LOG_DEBUG("LCD initialization started");
	lcd_init();
	LOG_DEBUG("LCD initialization finished");
}

void handleLcdBackground(const MessageData p_msgData)
{
	if(p_msgData.lcdBackground.turnOn)
	{
		LOG_INFO("Lcd background ON");
		lcd_backgroundLedOn();
	}
	else
	{
		LOG_INFO("Lcd background OFF");
		lcd_backgroundLedOff();
	}
}
