/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef MAIN_C_
#define MAIN_C_

#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "AquariumData/AquariumData.h"

#include "Utilities/Logger.h"

#include "Communication/MessageRouter.h"
#include "Communication/MessageBuilder.h"

#include "LCD/ServiceLcd.h"
#include "LED_SERVICE/led.h"

#include "IR_DECODE/Service.h"
#include "IR_DECODE/ir_decode.h"

#include "Timers/SoftwareTimer.h"

//to remove
#include "LCD/lcd44780.h"
#include "UART/uart.h"

void timerCallback2()
{
	sendMessage(MAIN, buildMessageDS18B20TemperatureRequest(1));
	sendMessage(MAIN, buildMessageDS18B20TemperatureRequest(0));
	sendMessage(MAIN, buildMessageDS18B20TemperatureRequest(2));
}

void timerCallback3()
{
	sendMessage(MAIN, buildMessageLcdDisplayTemperature());
}

int main(void)
{
	sei(); //enable global interrupts
	LOG_init();

	initLcd();
	ir_init();	/* inicjalizacja dekodowania IR */
	initSoftwareTimers();

	setAlarmLedAsOutput();
	setAlarmLedOff();

	registerPeriodicTimer(1000, &timerCallback2);
	registerPeriodicTimer(1000, &timerCallback3);

	while(true)
	{
		softwareTimersEvents();
		irKeyEvents();
	}
	return 0;
}

#endif /* MAIN_C_ */
