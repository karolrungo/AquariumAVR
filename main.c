/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef MAIN_C_
#define MAIN_C_

#include <avr/interrupt.h>

#include "TimerManager/TimerManager.h"
#include "LED_SERVICE/led.h"
#include "LCD/lcd44780.h"
#include "Utilities/Logger.h"
#include "1Wire/ds18x20.h"

void timerCallback1()
{
	LOG_Line("Jestem callback'iem 1!");
}
void timerCallback2()
{
	LOG_Line("Jestem callback'iem 2!");
}
void timerCallback3()
{
	LOG_Line("Jestem callback'iem 3!");
}

int main(void)
{
	sei(); //enable global interrupts
	LOG_init();

	lcd_init();
	initSoftwareTimers();

	setAlarmLedAsOutput();
	setAlarmLedOff();

	registerTimer(0, &timerCallback1);
	registerTimer(-1568, &timerCallback1);
	registerTimer(1007, &timerCallback1);
	registerTimer(3000, &timerCallback2);
	registerTimer(5000, &timerCallback3);

	while(true)
	{
		softwareTimersEvents();
	}
return 0;
}


#endif /* MAIN_C_ */
