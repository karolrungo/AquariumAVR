/*
 * ServiceLcd.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef LCD_SERVICELCD_H_
#define LCD_SERVICELCD_H_

#include "lcd44780.h"
#include "../Communication/MessageData.h"
#include "../Utilities/Logger.h"

void handleLcdBackground(const MessageData p_msgData)
{
	if(p_msgData.lcdBackground.isOn)
	{
		LOG_Line("ON");
		lcd_backgroundLedOn();
	}
	else
	{
		LOG_Line("OFF");
		lcd_backgroundLedOff();
	}
}

#endif /* LCD_SERVICELCD_H_ */
