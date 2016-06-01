/*
 * ServiceLcd.c
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#include "ServiceLcd.h"

#include "lcd44780.h"
#include "../Utilities/Logger.h"
#include "../AquariumData/AquariumData.h"

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

void handleLcdDisplayTemperature()
{
	lcd_cls();
	lcd_str("T1= ");
	lcd_int(temperature[0].temperature);
	lcd_str(".");
	lcd_int(temperature[0].temperature_fract_bits);
	lcd_str("oC");
	lcd_locate(1,0);
	lcd_str("T2= ");
	lcd_int(temperature[1].temperature);
	lcd_str(".");
	lcd_int(temperature[1].temperature_fract_bits);
	lcd_str("oC");
}
