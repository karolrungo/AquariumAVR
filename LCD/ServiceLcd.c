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
	LOG_Line("LCD initialization started");
	lcd_init();
	LOG_Line("LCD initialization finished");
}

void handleLcdBackground(const MessageData p_msgData)
{
	if(p_msgData.lcdBackground.turnOn)
	{
		LOG_Line("Lcd background ON");
		lcd_backgroundLedOn();
	}
	else
	{
		LOG_Line("Lcd background OFF");
		lcd_backgroundLedOff();
	}
}
