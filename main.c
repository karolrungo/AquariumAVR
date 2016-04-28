/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef MAIN_C_
#define MAIN_C_

#include <avr/interrupt.h>

#include "AquariumData/AquariumData.h"

#include "Utilities/Logger.h"
#include "1Wire/ds18x20.h"

#include "Communication/MessageRouter.h"
#include "Communication/MessageBuilder.h"

#include "LCD/ServiceLcd.h"
#include "LED_SERVICE/led.h"

#include "LCD/lcd44780.h"
#include "Timers/SoftwareTimer.h"

void timerCallback1()
{
	LOG_Line("Jestem callback'iem 3!");
	//sendMessage(MAIN, LCD_Service, buildMessageLcdBackground(true));
}
void timerCallback2()
{
	LOG_Line("Jestem callback'iem 2!");
	sendMessage(MAIN, DS18B20_Service, buildMessageDS18B20TemperatureRequest(0));
}
void timerCallback3()
{
	LOG_Line("Jestem callback'iem 3!");
	lcd_cls();
	lcd_int(temperature);
	lcd_str(".");
	lcd_int(temperature_fract_bits);

}

int main(void)
{
	sei(); //enable global interrupts
	LOG_init();

	initLcd();
	initSoftwareTimers();

	setAlarmLedAsOutput();
	setAlarmLedOff();


	registerOneShotTimer(0, &timerCallback1);
	registerOneShotTimer(-1568, &timerCallback1);
	registerOneShotTimer(1007, &timerCallback1);
	registerPeriodicTimer(1000, &timerCallback2);
	registerPeriodicTimer(1000, &timerCallback3);

	while(true)
	{
		softwareTimersEvents();
	}
	return 0;
}

#endif /* MAIN_C_ */
